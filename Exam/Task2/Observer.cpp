#include "Observer.h"

Observer::Observer()
{
}

Observer::Observer(const std::string nameOfObserver)
{
	SetNameOfObserver(nameOfObserver);
}

void Observer::SetNameOfObserver(const std::string nameOfObserver)
{
	m_nameOfObserver = nameOfObserver;
}

const std::string Observer::GetNameOfObserver() const
{
	return m_nameOfObserver;
}

void Observer::Update(const Currency curr) const
{
	std::cout << "Name: " << GetNameOfObserver() << " ";
	curr.Print();
}

Observer::~Observer()
{
}