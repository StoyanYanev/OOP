#pragma once
#include "Expression.h"
class Sum : public Expression
{
public:
	Sum( Expression* firstExpression,  Expression* seconsdExpression);
	Sum(const Sum&s);
	Sum &operator=(const Sum&s);
	virtual Expression *Clone() override;
	virtual double Value()const override;
	virtual void Print()const override;
	virtual~Sum();
private:
	void CopyFrom(const Sum&s);
	void Destroy();

	Expression** m_firstExpression;
	Expression** m_seconsdExpression;
	int m_currentElement;
};