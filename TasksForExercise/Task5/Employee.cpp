#include "Employee.h"

Employee::Employee()
{
}

Employee::Employee(std::string name, int period, double salary)
{
	this->SetName(name);
	this->SetPeriod(period);
	this->SetSalary(salary);
}

void Employee::SetName(const std::string name)
{
	this->name = name;
}

void Employee::SetPeriod(int period)
{
	if (period >= 0)
	{
		this->period = period;
	}
	else
	{
		std::cout << "The period can not be negative!" << std::endl;
	}
}

void Employee::SetSalary(double salary)
{
	if (salary >= 0)
	{
		this->salary = salary;
	}
	else
	{
		std::cout << "The salary can not be negative!" << std::endl;
	}
}

const std::string Employee::GetName() const
{
	return this->name;
}

int Employee::GetPeriod() const
{
	return this->period;
}

double Employee::GetSalary() const
{
	return this->salary;
}

void Employee::Print() const
{
	std::cout << "Name: " << this->GetName() << " period: " << this->GetPeriod() << " salary: " << this->GetSalary();
}

Employee::~Employee()
{
}