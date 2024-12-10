#ifndef SINK_HPP
#define SINK_HPP

#include "messages/message.hpp"
#include "sink_message.hpp"

class SinkActor: public Actor<SinkMessage>   {
public:
	virtual ~SinkActor() = default;
};

#endif
