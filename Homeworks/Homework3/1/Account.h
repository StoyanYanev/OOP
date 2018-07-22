#ifndef ACCOUNT_H
#define ACCOUNT_H	

#include <iostream>
#include <string>

class Account // abstract base class
{
public:
	Account();
	Account(const std::string iban, int ownerId, double amount);
	double GetBalance()const;
	void SetBalance(double amount);
	const std::string GetIBAN()const;
	int GetOwnerId()const;
	void SetIBAN(const std::string iban);
	void SetOwnerId(int id);


	virtual Account *Clone() = 0; // Virtual Copy Constructor

	// pure virtual functions
	virtual void Deposit(double sum) = 0; // add sum in account
	virtual bool Withdraw(double sum) = 0; // withdraw sum from account
	virtual void Display()const = 0; // display information about account
	~Account();
private:
	std::string m_iban;
	int m_ownerId;
	double m_amount;
};
#endif