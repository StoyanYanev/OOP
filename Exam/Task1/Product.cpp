#include "Product.h"

Product::Product(Expression * firstExpression, Expression * seconsdExpression)
{
	m_currentElement = 0;
	m_firstExpression = new Expression*[m_currentElement];
	m_seconsdExpression = new Expression*[m_currentElement];

	m_firstExpression[m_currentElement] = firstExpression->Clone();
	m_seconsdExpression[m_currentElement] = seconsdExpression->Clone();
}

Product::Product(const Product & p)
{
	CopyFrom(p);
}

Product & Product::operator=(const Product & p)
{
	if (this != &p)
	{
		Destroy();
		CopyFrom(p);
	}
	return *this;
}

Expression * Product::Clone()
{
	return new Product(*this);
}

double Product::Value() const
{
	double product = 1;

	product *= m_firstExpression[m_currentElement]->Value();
	product *= m_seconsdExpression[m_currentElement]->Value();

	return product;
}

void Product::Print() const
{
	std::cout << m_firstExpression[m_currentElement]->Value() << " * " << m_seconsdExpression[m_currentElement]->Value();
}

void Product::CopyFrom(const Product & p)
{
	m_currentElement = p.m_currentElement;
	m_firstExpression = new Expression*[m_currentElement];
	m_seconsdExpression = new Expression*[m_currentElement];
	m_firstExpression[m_currentElement] = p.m_firstExpression[m_currentElement]->Clone();
	m_seconsdExpression[m_currentElement] = p.m_seconsdExpression[m_currentElement]->Clone();
}

void Product::Destroy()
{
	delete[] m_firstExpression[m_currentElement];
	delete[] m_seconsdExpression[m_currentElement];
}

Product::~Product()
{
	Destroy();
}