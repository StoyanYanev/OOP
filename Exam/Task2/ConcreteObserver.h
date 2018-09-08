#pragma once
#include<iostream>

#include "Observer.h"
#include "Currency.h"

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(const std::string nameOfObserver);
	virtual void Update(const Currency curr)const override;
	virtual Observer *Clone() override;
	virtual ~ConcreteObserver();	
};