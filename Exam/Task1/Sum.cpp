#include "Sum.h"

Sum::Sum(Expression * firstExpression, Expression * seconsdExpression)
{
	m_currentElement = 0;
	m_firstExpression = new Expression*[m_currentElement];
	m_seconsdExpression = new Expression*[m_currentElement];

	m_firstExpression[m_currentElement] = firstExpression->Clone();
	m_seconsdExpression[m_currentElement] = seconsdExpression->Clone();
}

Sum::Sum(const Sum & s)
{
	CopyFrom(s);
}

Sum & Sum::operator=(const Sum & s)
{
	if (this != &s)
	{
		Destroy();
		CopyFrom(s);
	}
	return *this;
}

Expression * Sum::Clone()
{
	return new Sum(*this);
}

double Sum::Value() const
{
	double sum = 0;

	sum += m_firstExpression[m_currentElement]->Value();
	sum += m_seconsdExpression[m_currentElement]->Value();

	return sum;
}

void Sum::Print() const
{
	std::cout << m_firstExpression[m_currentElement]->Value() << " + " << m_seconsdExpression[m_currentElement]->Value();
}

void Sum::CopyFrom(const Sum & s)
{
	m_currentElement = s.m_currentElement;
	m_firstExpression = new Expression*[m_currentElement];
	m_seconsdExpression = new Expression*[m_currentElement];
	m_firstExpression[m_currentElement] = s.m_firstExpression[m_currentElement]->Clone();
	m_seconsdExpression[m_currentElement] = s.m_seconsdExpression[m_currentElement]->Clone();
}

void Sum::Destroy()
{
	delete[] m_firstExpression[m_currentElement];
	delete[] m_seconsdExpression[m_currentElement];
}

Sum::~Sum()
{
	Destroy();
}