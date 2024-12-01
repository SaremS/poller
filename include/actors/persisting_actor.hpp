#ifndef PERSISTING_ACTOR_HPP
#define PERSISTING_ACTOR_HPP


#include <queue>
#include <type_traits>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include "actor.hpp"
#include "messages/message.hpp"
#include "persisters/persister.hpp"

template <typename T>
concept DerivedFromMessage = std::derived_from<T, Message>

template <typename T>
concept DerivedFromPersister = std::derived_from<T, Persister>


template <DerivedFromMessage DM, DerivedFromPersister DP>
class PersistingActor: public Actor<DM> {
public:
	PersistingActor(const DP &persister) : Actor<DM>(), persister_(persister) {
		std::queue<DM> loadedQueue = persister_.loadPersistedJsonQueue();
		loadIntoQueue(loadedQueue);
	}


protected:
	void executeOnQueueChange(const std::queue<DM> &updatedQueue) const override {
		persister_.persistQueue(updatedQueue)
	} 

private:
	DP persister_
}


#endif
