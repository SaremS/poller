#ifndef VIRTUAL_SINK_MESSAGE_HPP
#define VIRTUAL_SINK_MESSAGE_HPP

#include <string>

#include "messages/message.hpp"

class SinkMessage: public Message {
public:
	std::string getAsJsonString() const override;

private:
	std::string jsonRepresentation_;
}


class SinkableMessage: public Message {
public:
	virtual SinkMessage makeSinkMessage() const = 0;

}


#endif
