#pragma once
#include "Expression.h"

class Const : public Expression
{
public:
	Const();
	Const(double val);
	void SetConstValue(double val);
	virtual Expression *Clone() override;
	virtual double Value()const override;
	virtual void Print()const override;
	virtual~Const();
private:
	double m_constValue;
};