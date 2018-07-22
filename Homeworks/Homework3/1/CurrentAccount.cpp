#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const std::string iban, int ownerId, double amount) :
	Account(iban, ownerId, amount)
{
}

CurrentAccount::CurrentAccount(const CurrentAccount & curr)
{
	SetIBAN(curr.GetIBAN());
	SetOwnerId(curr.GetOwnerId());
	SetBalance(curr.GetBalance());
}

Account * CurrentAccount::Clone() // Virtual Copy Constructor
{
	return new CurrentAccount(*this);
}

void CurrentAccount::Deposit(double sum) // add sum in account
{
	Account::Deposit(sum);
}

bool CurrentAccount::Withdraw(double sum)  // withdraw sum from account
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

void CurrentAccount::Display() const // display information about account
{
	std::cout << "Current account:" << std::endl;
	Account::Display();
}

CurrentAccount::~CurrentAccount()
{
}