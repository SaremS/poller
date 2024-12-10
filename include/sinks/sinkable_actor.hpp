#ifndef SINKABLE_ACTOR_HPP
#define SINKABLE_ACTOR_HPP

#include <memory>

#include "concepts/message_concepts"
#include "messages/message.hpp"
#include "actors/actor.hpp"
#include "sink_message.hpp"
#include "sink_actor.hpp"


template <DerivedFromSinkableMessage DSMIn, DerivedFromSinkableMessage DSMOut>
class SinkableActor: public Actor<DSMIn> {
public:
	SinkableActor(std::shared_ptr sinkActor): sinkActor(sinkActor_) {}

protected:
	void processMessage(const DSMIn &message) override {
		DSMOut outMessage = processSinkableMessage(message);
		sinkActor_->receiveMessage(outMessage.makeSinkMessage());
	}

	virtual DSMOut processSinkableMessage(const DSMIn &message) = 0;

private:
	std::shared_ptr<SinkActor> sinkActor_;
}

#endif 
