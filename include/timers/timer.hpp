#ifndef TIMER_H
#define TIMER_H

#include <memory>

#include "actors/actor.hpp"
#include "actors/actor_message_pair.hpp"
#include "messages/message.hpp"
#include "concepts/actor_concepts.hpp"


template <DerivedFromActor<Message> DA>
class Timer {
public:
    virtual ~Timer() {
		stop();
	};
	virtual void registerActorMessagePair(const std::unique_ptr<ActorMessagePair<DA, Message> > &actMes) {
		std::lock_guard<std::mutex> lock(timerMutex_);		 
		actorMessagePairs_.push_back(std::move(actMes));
	}
    virtual void start() = 0;
	virtual void stop() = 0;

protected:
	std::vector<std::unique_ptr<ActorMessagePair<DA, Message> >> actorMessagePairs_;
	std::atomic<bool> isRunning_;
	std::mutex timerMutex_;
	std::thread workerThread_;
};

#endif
