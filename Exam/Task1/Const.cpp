#include "Const.h"

Const::Const()
{
	SetConstValue(0);
}

Const::Const(double val)
{
	SetConstValue(val);
}

void Const::SetConstValue(double val)
{
	m_constValue = val;
}

Expression * Const::Clone()
{
	return new Const(*this);
}

double Const::Value() const
{
	return m_constValue;
}

void Const::Print() const
{
	std::cout << "Value: " << Value();
}

Const::~Const()
{
}