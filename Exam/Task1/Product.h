#pragma once
#include "Expression.h"

class Product : public Expression
{
public:
	Product(Expression* firstExpression, Expression* seconsdExpression);
	Product(const Product&p);
	Product &operator=(const Product&p);
	virtual Expression *Clone() override;
	virtual double Value()const override;
	virtual void Print()const override;
	virtual~Product();
private:
	void CopyFrom(const Product&p);
	void Destroy();

	Expression** m_firstExpression;
	Expression** m_seconsdExpression;
	int m_currentElement;
};