#ifndef ACTOR_MESSAGE_PAIR_HPP
#define ACTOR_MESSAGE_PAIR_HPP

#include <memory>

#include "messages/message.hpp"
#include "concepts/message_concepts.hpp"
#include "concepts/actor_concepts.hpp"


class VirtualActorMessagePair {
public:
    virtual ~VirtualActorMessagePair() = default;
    virtual void actorReceiveMessage() = 0; 
};

template <DerivedFromMessage DM, DerivedFromActor<DM> DA>
class ActorMessagePair: public VirtualActorMessagePair {
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
