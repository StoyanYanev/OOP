#include "Account.h"

Account::Account()
{
}

Account::Account(const std::string iban, int ownerId, double amount)
{
	SetIBAN(iban);
	SetOwnerId(ownerId);
	SetBalance(amount);
}

double Account::GetBalance() const
{
	return m_amount;
}

const std::string Account::GetIBAN() const
{
	return m_iban;
}

int Account::GetOwnerId() const
{
	return m_ownerId;
}

void Account::SetIBAN(const std::string iban)
{
	m_iban = iban;
}

void Account::SetOwnerId(int id)
{
	if (id >= 0)
	{
		m_ownerId = id;
	}
	else
	{
		std::cout << "Id can not be negative!" << std::endl;
	}
}

void Account::SetBalance(double amount)
{
	m_amount = amount;// the amount can be negative because in privilege account have overdraft
}

void Account::Deposit(double sum) // add sum in account
{
	if (sum >= 0)
	{
		m_amount += sum;
	}
	else
	{
		std::cout << "Can not deposit this sum!" << std::endl;
	}
}

void Account::Display() const // display information about account
{
	std::cout << "Iban " << GetIBAN() << " owner id: " << GetOwnerId() << " with amount " << GetBalance();
}

Account::~Account()
{
}