#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include "actors/persisting_actor.hpp"
#include "logging_message.hpp"
#include "concepts/persister_concepts.hpp"


template<DerivedFromPersister<LoggingMessage> DP>
class Logger: public PersistingActor<LoggingMessage, DP> {
public:
	Logger(const DP &persister): PersistingActor<LoggingMessage, DP>(persister) {}
	virtual ~Logger() = default;

protected:
	virtual void processMessage(const LoggingMessage &message) = 0;
};

#endif
