#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <vector>

#include"Customer.h"
#include "CurrentAccount.h"
#include"SavingsAccount.h"
#include"PrivilegeAccount.h"

class Bank
{
public:
	Bank(std::string nameOfBank, const std::string addressOfBank);
	Bank(const Bank& b);
	Bank &operator=(const Bank& b);
	const std::string GetNameOfBank()const;
	const std::string GetAdressOfBank()const;
	void SetNameOfBank(const std::string name);
	void SetAddresOfBank(std::string address);
	void AddCustomer(int customerId, const std::string name, const std::string address);
	void ListCustomers()const;
	void DeleteCustomer(int customerId);
	void AddAccount(const std::string accountType, const std::string iban, int ownerId, double amount);
	void DeleteAccount(const std::string iban);
	void ListAccounts()const;
	void ListCustomerAccounts(int customerId);
	void Transfer(const std::string fromIBAN, const std::string toIBAN, double amount); // transfer sum from iban to iban
	void WithdrawFromAccount(const std::string IBAN, double sum);
	void DepositToAccount(const std::string IBAN, double sum);
	void Display()const;
	~Bank();
private:
	void DeleteCustomerAccounts(int id);
	int FindCustomerById(int customerId);
	int FindOwnerByIBAN(const std::string iban);
	void CopyFrom(const Bank &b);
	void Destroy();

	std::string m_nameOfBank;
	std::string m_addressOfBank;
	std::vector<Customer> m_customers;
	std::vector<Account*> m_accounts;
};
#endif