#ifndef SINK_HPP
#define SINK_HPP

#include "messages/message.hpp"

class Sink {
public:
	virtual ~Sink() = default;
	virtual void process(const Message& message) const = 0;
};

#endif
