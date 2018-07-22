#include "Customer.h"

Customer::Customer(int customerId,std::string name, std::string address)
{
	SetAddressOfCustomer(address);
	SetCustomerId(customerId);
	SetNameOfCustomer(name);
}

int Customer::GetCustomerId() const
{
	return this->customerId;
}

std::string Customer::GetNameOfCustomer() const
{
	return this->nameOfCustomer;
}

std::string Customer::GetAddressOfCustomer() const
{
	return this->addressOfCustomer;
}

void Customer::SetCustomerId(int id)
{
	if (id >= 0)
	{
		this->customerId = id;
	}
	else
	{
		std::cout << "Id can not be negative!" << std::endl;
	}
}

void Customer::SetNameOfCustomer(std::string name)
{
	this->nameOfCustomer = name;
}

void Customer::SetAddressOfCustomer(std::string address)
{
	this->addressOfCustomer = address;
}

void Customer::Display() const
{
	std::cout << "ID: "<<GetCustomerId() << " Name of the user: " << GetNameOfCustomer() << " with address: " << GetAddressOfCustomer() << std::endl;
}

Customer::~Customer()
{
}