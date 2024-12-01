#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include "actors/persisting_actor.hpp"
#include "logging_message.hpp"


template<DerivedFromPersister DP>
class Logger: public PersistingActor<LoggingMessage, DP> {
public:
	Logger(const DP &persister): PersistingActor<LoggingMessage, DP>(persister) {}
	virtual ~Logger() = default;
	void processLoggingMessage(const LoggingMessage &message) const {
		processMessage(message);
	}
};

#endif
