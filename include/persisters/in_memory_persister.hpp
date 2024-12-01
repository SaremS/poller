#ifndef IN_MEMORY_PERSISTER_HPP
#define IN_MEMORY_PERSISTER_HPP

#include <queue>
#include <type_traits>

#include "messages/message.hpp"
#include "persister.hpp"


template <DerivedFromMessage DM>
class InMemoryPersister : public Persister<DM> {
public:
	void persistQueueAsJson(const std::queue<DM> &messageQueue) override {
		std::ostringstream jsonStream;
		jsonStream << "["; 

		auto q = messageQueue; 
		while (!q.empty()) {
			const DM& message = q.front();
			jsonStream << message.getAsJsonString(); 
			q.pop();
			
			if (!q.empty()) {
				jsonStream << ","; 
			}
		}

		jsonStream << "]"; // End JSON array
		queueJson_ = jsonStream.str();
	}

	std::string getQueueJson() const {return queueJson_;}

	std::queue<DM> loadPersistedJsonQueue() const override {
		std::queue<DM> queue;
		return queue;
	}

private:
	std::string queueJson_;
};

#endif
