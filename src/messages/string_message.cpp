#include <string>

#include "../include/messages/string_message.hpp"


std::string StringMessage::getAsJsonString() const {
		return "{\"message\": \"" + message_ + "\"}";
}
