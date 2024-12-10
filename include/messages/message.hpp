#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <memory>

class Message {
public:
	virtual ~Message() = default;
	std::unique_ptr<std::string> messageHeader = nullptr;
	virtual std::string getAsJsonString() const = 0;
};

#endif
