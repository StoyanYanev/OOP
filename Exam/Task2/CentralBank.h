#pragma once
#include<iostream>
#include <vector>
#include <string>

#include "Currency.h"
#include "ConcreteObserver.h"

class CentralBank
{
public:
	CentralBank(const std::string nameOfBank, const Currency& curr);
	CentralBank(const CentralBank& bank);
	CentralBank &operator=(const CentralBank& bank);
	void SetNameOfBank(const std::string nameOfBank);
	void PrintCurrency()const;
	void PrintObservers()const;
	const std::string GetNameOfBank()const;
	void AddCurrency(const Currency& curr);
	void DeleteCurrency(const std::string nameOfCurrency);
	void SetRate(const std::string nameOfCurrency, double reate);
	void Register(Observer* obs);
	void Unregister(const std::string nameOfObservers);
	void Notify(const Currency currency)const;
	~CentralBank();
private:
	void CopyFrom(const CentralBank& bank);
	void Destroy();
	int FindRegistred(const std::string nameOfObservers);

	std::string m_nameOfBank;
	std::vector<Currency> m_currency;
	std::vector<Observer*> m_observers;
};
