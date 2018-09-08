#include "Currency.h"

Currency::Currency()
{
	SetNameOfCurrency("");
	SetReate(0);
}

Currency::Currency(const std::string nameOfCurrency, double reate)
{
	SetNameOfCurrency(nameOfCurrency);
	SetReate(reate);
}

void Currency::SetNameOfCurrency(const std::string nameOfCurrency)
{
	m_nameOfCurrency = nameOfCurrency;
}

void Currency::SetReate(double reate)
{
	m_reate = reate;
}

void Currency::Print() const
{
	std::cout << "Currency: " << GetNameOfCurrency() << " reate: " << GetReate() << std::endl;
}

const std::string Currency::GetNameOfCurrency() const
{
	return m_nameOfCurrency;
}

double Currency::GetReate() const
{
	return m_reate;
}

Currency::~Currency()
{
}