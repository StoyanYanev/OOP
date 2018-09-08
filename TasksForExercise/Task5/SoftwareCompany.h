#ifndef SOFTWARE_COMPANY_H
#define SOFTWARE_COMPANY_H

#include<iostream>

#include"EmployeeList.h"

class SoftwareCompany
{
public:
	SoftwareCompany();
	void NewEmployee(const std::string typeOfEmployee, const std::string name, int period, double salary);
	void RemoveRecentlyEmployed(int period);
	void IncreaseSalaryOfAllEmployees();
	void PrintAll();
	double SumSalary();
	~SoftwareCompany();
private:
	EmployeeList list;
};
#endif