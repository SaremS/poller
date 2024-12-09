#ifndef TIMER_H
#define TIMER_H

#include <memory>

#include "actors/actor.hpp"
#include "actors/actor_message_pair.hpp"
#include "messages/message.hpp"


class Timer {
public:
    virtual ~Timer() {
		if (isRunning_) {
			stop();
		}
	};

	virtual void registerActorMessagePair(std::unique_ptr<VirtualActorMessagePair> actMes) {
		std::lock_guard<std::mutex> lock(timerMutex_);		 
		actorMessagePairs_.push_back(std::move(actMes));
	}

    void start() {
		startActors();
		startFn();
	}

	void stop() {
		stopActors();
		stopFn();
	}

	size_t actorMessagePairsRegistered() {
		std::lock_guard<std::mutex> lock(timerMutex_);
		return actorMessagePairs_.size();
	}

	size_t getIthActorsInboxSize(const size_t &i) {
		std::lock_guard<std::mutex> lock(timerMutex_);
		return actorMessagePairs_[i]->getInboxSize();
	}


protected:
    virtual void startFn() = 0;
	virtual void stopFn() = 0;

	std::vector<std::unique_ptr<VirtualActorMessagePair>> actorMessagePairs_;
	std::atomic<bool> isRunning_;
	std::mutex timerMutex_;
	std::thread workerThread_;


private:
	void startActors() {
		std::lock_guard<std::mutex> lock(timerMutex_);
		for (auto &amp: actorMessagePairs_) {
			amp->startActor();
		}	
	}

	void stopActors() {
		std::lock_guard<std::mutex> lock(timerMutex_);
		for (auto &amp: actorMessagePairs_) {
			amp->stopActor();
		}	
	}
};

#endif
