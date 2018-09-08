#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver(const std::string nameOfObserver):Observer(nameOfObserver)
{
}

void ConcreteObserver::Update(const Currency curr) const
{
	Observer::Update(curr);
}

Observer * ConcreteObserver::Clone()
{
	return new ConcreteObserver(*this);
}

ConcreteObserver::~ConcreteObserver()
{
}