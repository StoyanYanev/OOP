#include "Var.h"

Var::Var()
{
	SetName("");
	SetVarValue(0);
}

Var::Var(const char * name, double varValue)
{
	SetName(name);
	SetVarValue(varValue);
}

Var::Var(const Var & v)
{
	CopyFrom(v);
}

Var & Var::operator=(const Var & v)
{
	if (this != &v)
	{
		Destroy();
		CopyFrom(v);
	}
	return *this;
}

void Var::SetName(const char * name)
{
	int l = strlen(name);
	m_name = new char[l+1];
	strcpy_s(m_name, l+1, name);
}

void Var::SetVarValue(double varValue)
{
	m_varValue = varValue;
}

const char * Var::GetName() const
{
	return m_name;
}

Expression * Var::Clone()
{
	return new Var(*this);
}

double Var::Value() const
{
	return m_varValue;
}

void Var::Print() const
{
	std::cout << "Name: " << GetName();
}

void Var::CopyFrom(const Var & v)
{
	SetName(v.GetName());
	SetVarValue(v.Value());
}

void Var::Destroy()
{
	delete[] m_name;
}

Var::~Var()
{
	Destroy();
}