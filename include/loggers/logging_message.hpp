#ifndef LOGGING_MESSAGE_HPP
#define LOGGING_MESSAGE_HPP

#include<string>

#include "messages/message.hpp"

class LoggingMessage : public Message {
public:
	LoggingMessage(std::string text) : loggingText_(text) {}
	std::string getAsJsonString() const override;

private:
	std::string loggingText_;

};

#endif

