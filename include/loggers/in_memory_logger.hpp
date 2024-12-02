#ifndef IN_MEMORY_LOGGER_HPP
#define IN_MEMORY_LOGGER_HPP

#include <string>

#include "logger.hpp" 
#include "logging_message.hpp"
#include "actors/persisting_actor.hpp"

#include "concepts/persister_concepts.hpp"


template<DerivedFromPersister<LoggingMessage> DP>
class InMemoryLogger: public Logger<DP> {
	InMemoryLogger(const DP &persister): Logger<DP>(persister) {}

};

#endif
