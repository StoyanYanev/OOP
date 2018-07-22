#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const std::string iban, int ownerId, double amount, double overdraft) :
	Account(iban, ownerId, amount)
{
	SetOverdraft(overdraft);
}

PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount & priv)
{
	SetIBAN(priv.GetIBAN());
	SetOwnerId(priv.GetOwnerId());
	SetBalance(priv.GetBalance());
	SetOverdraft(priv.GetOverdraft());
}

double PrivilegeAccount::GetOverdraft() const
{
	return m_overdraft;
}

void PrivilegeAccount::SetOverdraft(double overdraft)
{
	if (overdraft >= 0)
	{
		m_overdraft = overdraft;
	}
	else
	{
		std::cout << "Overdraft can not be negative!" << std::endl;
	}
}

Account * PrivilegeAccount::Clone() // Virtual Copy Constructor
{
	return new PrivilegeAccount(*this);
}

void PrivilegeAccount::Deposit(double sum) // add sum in account
{
	Account::Deposit(sum);
}

bool PrivilegeAccount::Withdraw(double sum)  // withdraw sum from account
{
	if (GetBalance() + GetOverdraft() >= sum && sum >= 0)
	{
		SetBalance(GetBalance() - sum);
		return true;
	}
	else
	{
		std::cout << "Can not withdraw this sum!" << std::endl;
	}
	return false;
}

void PrivilegeAccount::Display() const // display information about account
{
	std::cout << "Privilege account:" << std::endl;
	Account::Display();
	std::cout << " and overdraft " << GetOverdraft() << std::endl;
}

PrivilegeAccount::~PrivilegeAccount()
{
}