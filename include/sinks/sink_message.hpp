#ifndef VIRTUAL_SINK_MESSAGE_HPP
#define VIRTUAL_SINK_MESSAGE_HPP

#include <string>

#include "messages/message.hpp"

class SinkMessage: public Message {
public:
	SinkMessage(const std::string &jsonRepresentation, const std::string &jsonTypes): 
		jsonRepresentation_(jsonRepresentation), jsonTypes_(jsonTypes) {}

	std::string getAsJsonString() const override {
		return jsonRepresentation_;
	}

private:
	std::string jsonRepresentation_;
	std::string jsonTypes_;
}


class SinkableMessage: public Message {
public:
	virtual SinkMessage makeSinkMessage() const = 0;

}


#endif
