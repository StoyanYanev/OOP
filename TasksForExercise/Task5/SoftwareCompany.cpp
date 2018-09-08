#include "SoftwareCompany.h"

SoftwareCompany::SoftwareCompany()
{
}

void SoftwareCompany::NewEmployee(const std::string typeOfEmployee, const std::string name, int period, double salary)
{
	list.AddEmployee(typeOfEmployee, name, period, salary);
}

void SoftwareCompany::RemoveRecentlyEmployed(int period)
{
	if (period > 0)
	{
		list.DeleteEmployee(period);
	}
	else
	{
		std::cout << "Invalide period!" << std::endl;
	}
}

void SoftwareCompany::IncreaseSalaryOfAllEmployees()
{
	list.IncreaseSalary();
}

void SoftwareCompany::PrintAll()
{
	list.PrintEmployee();
}

double SoftwareCompany::SumSalary()
{
	return list.ÌonthlyÅxpense();
}

SoftwareCompany::~SoftwareCompany()
{
}