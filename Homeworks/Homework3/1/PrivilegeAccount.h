#ifndef PRIVILEGE_ACCOUNT_H
#define PRIVILEGE_ACCOUNT_H	

#include "Account.h"

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount(const std::string iban, int ownerId, double amount, double overdraft);
	PrivilegeAccount(const PrivilegeAccount& priv);
	double GetOverdraft()const;
	void SetOverdraft(double overdraft);

	// override functions by class Account
	virtual Account *Clone() override;
	virtual void Deposit(double sum) override;
	virtual bool Withdraw(double sum) override;
	virtual void Display()const override;

	virtual ~PrivilegeAccount();
private:
	double m_overdraft;
};
#endif