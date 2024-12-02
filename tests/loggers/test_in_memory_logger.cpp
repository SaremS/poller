#include <string>
#include <queue>
#include <chrono>
#include <thread>

#include "gtest/gtest.h"

#include "../include/persisters/in_memory_persister.hpp"
#include "../include/loggers/logging_message.hpp"
#include "../include/loggers/logger.hpp"
#include "../include/loggers/in_memory_logger.hpp"

TEST(InMemoryLogger, processLoggingMessage) {
	InMemoryPersister<LoggingMessage> persister;
	InMemoryLogger<InMemoryPersister<LoggingMessage>> logger(persister);
	LoggingMessage message("TEST");	

	logger.start();
	logger.receiveMessage(message);

	size_t retries = 0;
	while (logger.getInMemoryLogs().size() < 1 && retries < 20) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		retries++;
	}
	logger.stop();

	EXPECT_EQ(logger.getInMemoryLogs().size(), 1);	
}
