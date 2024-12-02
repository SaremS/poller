#ifndef LOGGING_MESSAGE_HPP
#define LOGGING_MESSAGE_HPP

#include<string>

#include "messages/message.hpp"

class LoggingMessage : public Message {
public:
	LoggingMessage(std::string text) : logText_(text) {}
	std::string getAsJsonString() const override {
		return "{\"log_text\": \"" + logText_ + "\"}";
	}

private:
	std::string logText_;

};

#endif

