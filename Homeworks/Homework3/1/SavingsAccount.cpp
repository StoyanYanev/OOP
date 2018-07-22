#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string iban, int ownerId, double amount, double interestRate) :
	Account(iban, ownerId, amount)
{
	SetInterestRate(interestRate);
}

SavingsAccount::SavingsAccount(const SavingsAccount & save)
{
	SetIBAN(save.GetIBAN());
	SetOwnerId(save.GetOwnerId());
	SetBalance(save.GetBalance());
	SetInterestRate(save.GetInterestRate());
}

double SavingsAccount::GetInterestRate() const
{
	return m_interestRate;
}

void SavingsAccount::SetInterestRate(double interestRate)
{
	if (interestRate >= 0)
	{
		m_interestRate = interestRate;
	}
	else
	{
		std::cout << "Interest rate can not be negative!" << std::endl;
	}
}

Account * SavingsAccount::Clone() // Virtual Copy Constructor
{
	return new SavingsAccount(*this);
}

void SavingsAccount::Deposit(double sum)  // add sum in account
{
	Account::Deposit(sum);
}

bool SavingsAccount::Withdraw(double sum)  // withdraw sum from account
{
	if (GetBalance() - sum >= 0 && sum >= 0)
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

void SavingsAccount::Display() const // display information about account
{
	std::cout << "Saving account:" << std::endl;
	Account::Display();
	std::cout << " and interest rate " << GetInterestRate() << std::endl;
}

SavingsAccount::~SavingsAccount()
{
}