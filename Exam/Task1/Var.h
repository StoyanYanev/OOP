#pragma once
#include "Expression.h"

class Var : public Expression
{
public:
	Var();
	Var(const char* name, double varValue);
	Var(const Var& v);
	Var &operator=(const Var& v);
	void SetName(const char*name);
	void SetVarValue(double varValue);
	const char* GetName()const;
	virtual Expression *Clone() override;
	virtual double Value()const override;
	virtual void Print()const override;
	virtual~Var();
private:
	void CopyFrom(const Var& v);
	void Destroy();

	char* m_name;
	double m_varValue;
};