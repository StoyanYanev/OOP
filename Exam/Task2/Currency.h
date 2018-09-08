#pragma once
#include<iostream>
#include <string>

class Currency
{
public:
	Currency();
	Currency(const std::string nameOfCurrency, double reate);
	void SetNameOfCurrency(const std::string nameOfCurrency);
	void SetReate(double reate);
	void Print()const;
	const std::string  GetNameOfCurrency()const;
	double GetReate()const;
	~Currency();
private:
	std::string m_nameOfCurrency;
	double m_reate;
};