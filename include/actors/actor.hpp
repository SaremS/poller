#ifndef ACTOR_HPP
#define ACTOR_HPP


#include <queue>
#include <type_traits>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include "messages/message.hpp"
#include "concepts/message_concepts.hpp"



template <DerivedFromMessage DM>
class Actor {
public:
	Actor() : isRunning_(false) {}


	void receiveMessage(const DM &message) {
		std::lock_guard<std::mutex> lock(queueMutex_);
		messageQueue_.push(message);
		executeOnQueueChange(messageQueue_);
		queueCv_.notify_one();
	}

	size_t getInboxSize() const {
		std::lock_guard<std::mutex> lock(queueMutex_);
		return messageQueue_.size();
	}

	bool inboxIsEmpty() const {
		std::lock_guard<std::mutex> lock(queueMutex_);
		return messageQueue_.empty();
	}

	void start() {
		isRunning_ = true;
        workerThread_ = std::thread([this]() {
            while (isRunning_) {
                DM message;
                {
                    std::unique_lock<std::mutex> lock(queueMutex_);
                    queueCv_.wait(lock, [this]() { return !messageQueue_.empty() || !isRunning_; });
                    
                    if (!isRunning_) return; 
                    message = messageQueue_.front();
                    messageQueue_.pop();
					executeOnQueueChange(messageQueue_);
                }
                processMessage(message); 
			}
		});
	}

	void stop() {
        isRunning_ = false;
        queueCv_.notify_all(); 
        if (workerThread_.joinable()) {
            workerThread_.join(); 
        }
	}

    virtual ~Actor() {
        stop(); 
	}


protected:
	virtual void executeOnQueueChange(const std::queue<DM> &updatedQueue) const = 0; 
	virtual void processMessage(const DM &message) const = 0;

	void loadIntoQueue(std::queue<DM> &queue) {
		if (messageQueue_.empty()) {
			messageQueue_ = queue;
		}
	}


private:
	std::queue<DM> messageQueue_;

	std::mutex queueMutex_;
	std::condition_variable queueCv_;
	std::thread workerThread_;
	std::atomic<bool> isRunning_;
};


#endif
