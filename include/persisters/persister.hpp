#ifndef PERSISTER_HPP
#define PERSISTER_HPP

#include <queue>
#include <type_traits>

#include "messages/message.hpp"
#include "concepts/message_concepts.hpp"


template <DerivedFromMessage DM>
class Persister {
public:
	virtual ~Persister() = default;
	void persistQueue(const std::queue<DM> &messageQueue) {
		persistQueueAsJson(messageQueue);
	}
	virtual void persistQueueAsJson(const std::queue<DM> &messageQueue) = 0;
	virtual std::queue<DM> loadPersistedJsonQueue() const = 0;
};

#endif
