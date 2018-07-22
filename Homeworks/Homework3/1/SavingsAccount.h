#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H	

#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(std::string iban, int ownerId, double amount, double interestRate);
	SavingsAccount(const SavingsAccount& save);
	double GetInterestRate()const;
	void SetInterestRate(double interestRate);

	// override functions by class Account
	virtual Account *Clone() override;
	virtual void Deposit(double sum) override;
	virtual bool Withdraw(double sum) override;
	virtual void Display()const override;

	virtual ~SavingsAccount();
private:
	double m_interestRate;
};
#endif