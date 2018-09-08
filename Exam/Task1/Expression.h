#pragma once
#include <iostream>

class Expression
{
public:
	Expression();
	virtual Expression *Clone() = 0;
	virtual double Value()const = 0;
	virtual void Print()const = 0;
	virtual ~Expression();
};