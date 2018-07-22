#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(const std::string iban, int ownerId, double amount);
	CurrentAccount(const CurrentAccount& curr);

	// override functions by class Account
	virtual Account *Clone() override;
	virtual void Deposit(double sum) override;
	virtual bool Withdraw(double sum) override;
	virtual void Display()const override;

	virtual ~CurrentAccount();
};
#endif