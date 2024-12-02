#ifndef PERSISTER_CONCEPTS_HPP
#define PERSISTER_CONCEPTS_HPP

#include "message_concepts.hpp"
#include "persisters/persister.hpp"

template <typename T, typename DM>
concept DerivedFromPersister = DerivedFromMessage<DM> and std::derived_from<T, Persister<DM>>;

#endif
