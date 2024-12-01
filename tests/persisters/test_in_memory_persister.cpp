#include <string>
#include <queue>

#include "gtest/gtest.h"

#include "../include/messages/string_message.hpp"
#include "../include/persisters/in_memory_persister.hpp"

TEST(inMemoryPersister, getQueueJson) {
	std::string testString = "TEST";
	StringMessage message(testString);
	std::queue<StringMessage> mQueue;
	mQueue.push(message);

	InMemoryPersister<StringMessage> persister;
	persister.persistQueueAsJson(mQueue);

	EXPECT_EQ(persister.getQueueJson(), "[{\"message\": \""+ testString + "\"}]");	
}
