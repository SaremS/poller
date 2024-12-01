#ifndef IN_MEMORY_LOGGER_HPP
#define IN_MEMORY_LOGGER_HPP

#include <string>

#include "logger.hpp" 
#include "logging_message.hpp"
#include "actors/persisting_actor.hpp"


template<DerivedFromPersister DP>
class InMemoryLogger: public Logger<DP> {
public:
	InMemoryLogger(const unsigned int &maxLogSize) : maxLogSize_(maxLogSize) {}

private:
	std::vector<LogEntry> logEntries_;
	unsigned int maxLogSize_;
	mutable std::mutex mutex_;
};


#endif
