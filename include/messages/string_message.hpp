#ifndef STRING_MESSAGE_HPP
#define STRING_MESSAGE_HPP

#include <string>

#include "message.hpp"

class StringMessage : public Message {
public:
	StringMessage(const std::string &message) : message_(message) {}
	std::string getAsJsonString() const override;
private:
	std::string message_;   
};

#endif 
