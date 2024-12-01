#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>

class Message {
public:
	virtual ~Message() = default;
	virtual std::string getAsJsonString() const = 0;
};

#endif
