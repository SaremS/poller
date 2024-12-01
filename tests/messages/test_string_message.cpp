#include <string>

#include "gtest/gtest.h"

#include "../include/messages/string_message.hpp"

TEST(testStringMessage, getAsString) {
	std::string testString = "TEST";
	
	StringMessage message(testString);

	EXPECT_EQ(message.getAsJsonString(), "{\"message\": \""+ testString + "\"}");	
}
