#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include <iostream>
#include <vector>
#include<string>

#include "Developer.h"
#include "Manager.h"

class EmployeeList
{
public:
	EmployeeList();
	EmployeeList(const EmployeeList& employeeList);
	EmployeeList &operator=(const EmployeeList& employeeList);
	void AddEmployee(const std::string typeOfEmployee, const std::string name, int period, double salary);
	void DeleteEmployee(int period);
	double Ãonthly≈xpense()const;
	void IncreaseSalary();
	void PrintEmployee()const;
	~EmployeeList();
private:
	void CopyFrom(const EmployeeList& employeeList);
	void Destroy();

	std::vector <Employee*> employees;
};
#endif