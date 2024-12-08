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
			stopTimer();
		}
	};
	virtual void registerActorMessagePair(std::unique_ptr<VirtualActorMessagePair> actMes) {
		std::lock_guard<std::mutex> lock(timerMutex_);		 
		actorMessagePairs_.push_back(std::move(actMes));
	}
    virtual void start() = 0;
	virtual void stop() = 0;

protected:
	void stopTimer() {
		stop();
	}
	std::vector<std::unique_ptr<VirtualActorMessagePair>> actorMessagePairs_;
	std::atomic<bool> isRunning_;
	std::mutex timerMutex_;
	std::thread workerThread_;
};

#endif
