#ifndef IN_MEMORY_LOGGER_HPP
#define IN_MEMORY_LOGGER_HPP

#include <string>
#include <queue>

#include "logger.hpp" 
#include "logging_message.hpp"
#include "actors/persisting_actor.hpp"

#include "concepts/persister_concepts.hpp"


template<DerivedFromPersister<LoggingMessage> DP>
class InMemoryLogger: public Logger<DP> {
public:
	InMemoryLogger(const DP &persister): Logger<DP>(persister) {}
	std::queue<LoggingMessage> getInMemoryLogs() const {return loggingMessages_;}


protected:
	void processMessage(const LoggingMessage &message) {
		loggingMessages_.push(message);
	}

private:
	std::queue<LoggingMessage> loggingMessages_;
	
};

#endif
