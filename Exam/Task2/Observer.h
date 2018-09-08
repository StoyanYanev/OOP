#pragma once
#include <iostream>
#include<string>

#include "Currency.h"

class Observer
{
public:
	Observer();
	Observer(const std::string nameOfObserver);
	void SetNameOfObserver(const std::string nameOfObserver);
	const std::string GetNameOfObserver()const;
	virtual void Update(const Currency curr)const = 0;
	virtual Observer *Clone() = 0;
	~Observer();
private:
	std::string m_nameOfObserver;
};