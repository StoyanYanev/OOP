#include "Bank.h"

Bank::Bank(const std::string nameOfBank, const std::string addressOfBank)
{
	SetNameOfBank(nameOfBank);
	SetAddresOfBank(addressOfBank);
}

Bank::Bank(const Bank & b)
{
	CopyFrom(b);
}

Bank & Bank::operator=(const Bank & b)
{
	if (this != &b)
	{
		Destroy();
		CopyFrom(b);
	}
	return *this;
}

const std::string Bank::GetNameOfBank() const
{
	return m_nameOfBank;
}

const std::string Bank::GetAdressOfBank() const
{
	return m_addressOfBank;
}

void Bank::SetNameOfBank(const std::string name)
{
	m_nameOfBank = name;
}

void Bank::SetAddresOfBank(const std::string address)
{
	m_addressOfBank = address;
}

void Bank::AddCustomer(int customerId, const std::string name, const std::string address)
{
	if (customerId >= 0)
	{
		if (FindCustomerById(customerId) < 0) // if the customer doesn't exist add it
		{
			Customer c(customerId, name, address);
			m_customers.push_back(c);
		}
		else
		{
			std::cout << "Customer by id " << customerId << " exists!" << std::endl;
		}
	}
	else
	{
		std::cout << "Id can not be negative!" << std::endl;
	}
}

void Bank::ListCustomers() const
{
	if (m_customers.size() > 0)
	{
		for (int i = 0; i < m_customers.size(); i++)
		{
			m_customers[i].Display();
		}
	}
	else
	{
		std::cout << "The bank has no customers!" << std::endl;
	}
}

void Bank::DeleteCustomer(int customerId)
{
	if (m_customers.size() > 0)
	{
		int index = FindCustomerById(customerId); // find the index of the customer with current id
		if (index >= 0) // check if exists customer with the current id
		{
			DeleteCustomerAccounts(m_customers[index].GetCustomerId()); // delete all customer accounts
			m_customers.erase(m_customers.begin() + index); // delete customer
			std::cout << "Customer with id: " << customerId << " is deleted succesfully!" << std::endl;
		}
		else
		{
			std::cout << "Can not find customer by id: " << customerId << std::endl;
		}
	}
	else
	{
		std::cout << "Can not delete customer!The bank has no customers!" << std::endl;
	}
}

void Bank::AddAccount(const std::string accountType, const std::string iban, int ownerId, double amount)
{
	//  check if exists customer with iban. Check if doesn't exist customer with the current iban
	if (FindCustomerById(ownerId) >= 0 && FindOwnerByIBAN(iban) < 0)
	{
		if (accountType == "current")
		{
			m_accounts.push_back(new CurrentAccount(iban, ownerId, amount));
		}
		else if (accountType == "savings")
		{
			double interestRate;
			std::cout << "Enter interest rate: ";
			std::cin >> interestRate;
			m_accounts.push_back(new SavingsAccount(iban, ownerId, amount, interestRate));
		}
		else
		{
			double overdraft;
			std::cout << "Enter overdraft: ";
			std::cin >> overdraft;
			m_accounts.push_back(new PrivilegeAccount(iban, ownerId, amount, overdraft));
		}
		std::cout << "The account is added successfully!" << std::endl;
	}
	else
	{
		std::cout << "There is customer with the same id or iban!" << std::endl;
	}
}

void Bank::DeleteAccount(const std::string iban)
{
	if (m_accounts.size() > 0)
	{
		int index = FindOwnerByIBAN(iban); // Check if exists customer with the current iban
		if (index >= 0)
		{
			m_accounts.erase(m_accounts.begin() + index); // delete account
			std::cout << "Owner with iban: " << iban << " is deleted succesfully!" << std::endl;
		}
		else
		{
			std::cout << "Can not find owner by iban: " << iban << std::endl;
		}
	}
	else
	{
		std::cout << "Can not delete owner! The bank has no customers!" << std::endl;
	}
}

void Bank::ListAccounts() const
{
	if (m_accounts.size() > 0)
	{
		for (int i = 0; i < m_accounts.size(); i++)
		{
			m_accounts[i]->Display();
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "The Bank doesn't have registred accounts!" << std::endl;
	}
}

void Bank::ListCustomerAccounts(int customerId)
{
	if (FindCustomerById(customerId) >= 0)
	{
		bool isFind = false;
		std::cout << "The customer with id " << customerId << " has accounts: " << std::endl;
		for (int i = 0; i < m_accounts.size(); i++)
		{
			if (m_accounts[i]->GetOwnerId() == customerId)
			{
				m_accounts[i]->Display();
				std::cout << std::endl;
				isFind = true;
			}
		}
		if (isFind == false)
		{
			std::cout << "This customer doesn't have accounts!" << std::endl;
		}
	}
	else
	{
		std::cout << "The Bank doesn't have customer by id " << customerId << std::endl;
	}
}

void Bank::Transfer(const std::string fromIBAN, const std::string toIBAN, double amount) // transfer sum from iban to iban
{
	int indexFromIban = this->FindOwnerByIBAN(fromIBAN);
	int indexToIban = this->FindOwnerByIBAN(toIBAN);
	if (indexFromIban >= 0 && indexToIban >= 0)
	{
		if (m_accounts[indexFromIban]->GetBalance() - amount >= 0)
		{
			m_accounts[indexToIban]->Deposit(amount);
			m_accounts[indexFromIban]->Withdraw(amount);
		}
	}
	else
	{
		std::cout << "Can not find owner!" << std::endl;
	}
}

void Bank::WithdrawFromAccount(const std::string IBAN, double sum)
{
	int ind = FindOwnerByIBAN(IBAN);
	if (ind >= 0)
	{
		m_accounts[ind]->Withdraw(sum);
	}
	else
	{
		std::cout << "The iban doesn't exsist!" << std::endl;
	}
}

void Bank::DepositToAccount(const std::string IBAN, double sum)
{
	int ind = FindOwnerByIBAN(IBAN);
	if (ind >= 0)
	{
		m_accounts[ind]->Deposit(sum);
	}
	else
	{
		std::cout << "The iban doesn't exsist!" << std::endl;
	}
}

void Bank::Display() const
{
	std::cout << "Name of the bank: " << GetNameOfBank() << " with adress " << GetAdressOfBank() << std::endl;
	std::cout << "The bank has " << m_customers.size() << " customers and " << m_accounts.size() << " accounts!" << std::endl;
}

void Bank::DeleteCustomerAccounts(int id)
{
	std::vector<Account*>newAccounts;
	if (m_accounts.size() > 0)
	{
		for (int i = 0; i < m_accounts.size(); i++)
		{
			if (m_accounts[i]->GetOwnerId() != id)
			{
				newAccounts.push_back(m_accounts[i]->Clone());
			}
		}
		Destroy();
		m_accounts = newAccounts;
	}
}

int Bank::FindCustomerById(int customerId)
{
	for (int i = 0; i < m_customers.size(); i++)
	{
		if (m_customers[i].GetCustomerId() == customerId)
		{
			return i;
		}
	}
	return -1;
}

int Bank::FindOwnerByIBAN(const std::string iban)
{
	for (int i = 0; i < m_accounts.size(); i++)
	{
		if (m_accounts[i]->GetIBAN() == iban)
		{
			return i;
		}
	}
	return -1;
}

void Bank::CopyFrom(const Bank & b)
{
	SetNameOfBank(b.GetNameOfBank());
	SetAddresOfBank(b.GetAdressOfBank());
	m_customers = b.m_customers;
	for (int i = 0; i < b.m_accounts.size(); i++)
	{
		m_accounts.push_back(b.m_accounts[i]->Clone());
	}
}

void Bank::Destroy()
{
	for (int i = 0; i < m_accounts.size(); i++)
	{
		delete m_accounts[i];
	}
}

Bank::~Bank()
{
	Destroy();
}