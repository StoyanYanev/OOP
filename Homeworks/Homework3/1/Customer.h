#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer
{
public:
	Customer(int customerId,std::string name, std::string address);
	int GetCustomerId()const;
	std::string GetNameOfCustomer()const;
	std::string GetAddressOfCustomer()const;
	void SetCustomerId(int id);
	void SetNameOfCustomer(std::string name);
	void SetAddressOfCustomer(std::string address);
	void Display()const;
	~Customer();
private:
	int customerId;
	std::string nameOfCustomer;
	std::string addressOfCustomer;
};
#endif