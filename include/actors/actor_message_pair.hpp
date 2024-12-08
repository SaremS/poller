#ifndef ACTOR_MESSAGE_PAIR_HPP
#define ACTOR_MESSAGE_PAIR_HPP

#include <memory>

#include "messages/message.hpp"
#include "concepts/message_concepts.hpp"
#include "concepts/actor_concepts.hpp"


template <DerivedFromMessage DM, DerivedFromActor<DM> DA>
class ActorMessagePair {
public:
	ActorMessagePair(std::unique_ptr<DA> &actor, std::unique_ptr<DM> &message): actor_(std::move(actor)), message_(std::move(message)) {}
	void actorReceiveMessage() {
		actor_->receiveMessage(*message_);
	}


private:
	std::unique_ptr<DA> actor_;
	std::unique_ptr<DM> message_;
};


#endif
