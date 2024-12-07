#include <string>
#include <queue>
#include <chrono>
#include <thread>
#include <memory>

#include "gtest/gtest.h"

#include "../include/persisters/in_memory_persister.hpp"
#include "../include/loggers/logging_message.hpp"
#include "../include/loggers/logger.hpp"
#include "../include/loggers/in_memory_logger.hpp"
#include "../include/timers/n_shot_timer.hpp"
#include "../include/actors/actor_message_pair.hpp"

typedef ActorMessagePair<LoggingMessage, InMemoryLogger<InMemoryPersister<LoggingMessage> > > LogAmp;

TEST(NShotTimer, RunTimer) {
	InMemoryPersister<LoggingMessage> persister;
    auto logger = std::make_unique<InMemoryLogger<InMemoryPersister<LoggingMessage>>>(persister);
	logger->start();
	auto message = std::make_unique<LoggingMessage>("TEST"); 

	LogAmp amp(logger, message);
	
	NShotTimer<Actor<Message>> timer(1, 50);
	/*
	timer.registerActorMessagePair(std::make_unique(amp));

	timer.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	timer.stop();
	logger.stop();

	EXPECT_EQ(logger.getInMemoryLogs().size(), 1);*/	
}
