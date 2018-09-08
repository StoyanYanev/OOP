#include "CentralBank.h"

CentralBank::CentralBank(const std::string nameOfBank, const Currency & curr)
{
	SetNameOfBank(nameOfBank);
	m_currency.push_back(curr);
}

CentralBank::CentralBank(const CentralBank & bank)
{
	CopyFrom(bank);
}

CentralBank & CentralBank::operator=(const CentralBank & bank)
{
	if (this != &bank)
	{
		Destroy();
		CopyFrom(bank);
	}
	return *this;
}

void CentralBank::SetNameOfBank(const std::string nameOfBank)
{
	m_nameOfBank = nameOfBank;
}

void CentralBank::PrintCurrency() const
{
	for (int i = 0; i < m_currency.size(); i++)
	{
		m_currency[i].Print();
	}
}

void CentralBank::PrintObservers() const
{
	for (int i = 0; i < m_observers.size(); i++)
	{
		std::cout << "Name of observer: " << m_observers[i]->GetNameOfObserver() << std::endl;
	}
}

const std::string CentralBank::GetNameOfBank() const
{
	return m_nameOfBank;
}

void CentralBank::AddCurrency(const Currency & curr)
{
	m_currency.push_back(curr);
}

void CentralBank::DeleteCurrency(const std::string nameOfCurrency)
{
	for (int i = 0; i < m_currency.size(); i++)
	{
		if (m_currency[i].GetNameOfCurrency() == nameOfCurrency)
		{
			m_currency.erase(m_currency.begin() + i);
		}
	}
}

void CentralBank::SetRate(const std::string nameOfCurrency, double reate)
{
	for (int i = 0; i < m_currency.size(); i++)
	{
		if (m_currency[i].GetNameOfCurrency() == nameOfCurrency)
		{
			m_currency[i].SetReate(reate);
			Notify(m_currency[i]);
			break;
		}
	}
}

void CentralBank::Register(Observer * obs)
{
	m_observers.push_back(obs);
}

void CentralBank::Unregister(const std::string nameOfObservers)
{
	int index = FindRegistred(nameOfObservers);
	if (index >= 0)
	{
		m_observers.erase(m_observers.begin() + index);
	}
	else
	{
		std::cout << "Can not find observer by this name!" << std::endl;
	}
}

void CentralBank::Notify(const Currency currency) const
{
	for (int i = 0; i < m_observers.size(); i++)
	{
		m_observers[i]->Update(currency);
	}
}

void CentralBank::CopyFrom(const CentralBank & bank)
{
	SetNameOfBank(bank.GetNameOfBank());
	m_currency = bank.m_currency;
	for (int i = 0; i < m_observers.size(); i++)
	{
		m_observers.push_back(bank.m_observers[i]->Clone());
	}
}

void CentralBank::Destroy()
{
	for (int i = 0; i < m_observers.size(); i++)
	{
		delete m_observers[i];
	}
}

int CentralBank::FindRegistred(const std::string nameOfObservers)
{
	for (int i = 0; i < m_observers.size(); i++)
	{
		if (m_observers[i]->GetNameOfObserver() == nameOfObservers)
		{
			return i;
		}
	}
	return -1;
}

CentralBank::~CentralBank()
{
	Destroy();
}