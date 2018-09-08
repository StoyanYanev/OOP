#include "EmployeeList.h"

EmployeeList::EmployeeList()
{
}

EmployeeList::EmployeeList(const EmployeeList & employeeList)
{
	CopyFrom(employeeList);
}

EmployeeList & EmployeeList::operator=(const EmployeeList & employeeList)
{
	if (this != &employeeList)
	{
		Destroy();
		CopyFrom(employeeList);
	}
	return *this;
}

void EmployeeList::AddEmployee(const std::string typeOfEmployee, const std::string name, int period, double salary)
{
	if (typeOfEmployee == "developer")
	{
		std::cout << "Enter information about developer: " << std::endl;
		bool knowledgeCPlusPlus;
		bool knowledgeCSharp;
		std::cout << "Enter 0 or 1 !" << std::endl;
		std::cout << "Knowledge CPlusPlus: ";
		std::cin >> knowledgeCPlusPlus;
		std::cout << "Knowledge CSharp: ";
		std::cin >> knowledgeCSharp;
		this->employees.push_back(new Developer(name, period, salary, knowledgeCPlusPlus, knowledgeCSharp));
	}
	else
	{
		std::cout << "Enter information about manager: " << std::endl;
		int inChargeOf;
		std::cout << "In charge of: ";
		std::cin >> inChargeOf;
		this->employees.push_back(new Manager(name, period, salary, inChargeOf));
	}
}

void EmployeeList::DeleteEmployee(int period)
{
	std::vector<Employee*>newEmployees;
	for (int i = 0; i < this->employees.size(); i++)
	{
		if (this->employees[i]->GetPeriod() > period)
		{
			newEmployees.push_back(this->employees[i]->Clone());
		}
	}
	Destroy();
	this->employees = newEmployees;
}

double EmployeeList::Ãonthly≈xpense() const
{
	double sum = 0;
	for (int i = 0; i < this->employees.size(); i++)
	{
		sum += this->employees[i]->GetSalary();
	}
	return sum;
}

void EmployeeList::IncreaseSalary()
{
	for (int i = 0; i < this->employees.size(); i++)
	{
		if (this->employees[i]->type() == DEVELOPER &&
			((Developer*)this->employees[i])->GetKnowledgeCSharp() == true &&
			((Developer*)this->employees[i])->GetKnowledgeCPlusPlus() == false)
		{
			this->employees[i]->SetSalary(this->employees[i]->GetSalary() + 100);
		}
		if (this->employees[i]->type() == DEVELOPER &&
			((Developer*)this->employees[i])->GetKnowledgeCPlusPlus() == true)
		{
			this->employees[i]->SetSalary(this->employees[i]->GetSalary() + 500);
		}
	}
}

void EmployeeList::PrintEmployee() const
{
	for (int i = 0; i < this->employees.size(); i++)
	{
		this->employees[i]->Print();
	}
}


EmployeeList::~EmployeeList()
{
	Destroy();
}

void EmployeeList::CopyFrom(const EmployeeList & employeeList)
{
	for (int i = 0; i < this->employees.size(); i++)
	{
		this->employees.push_back(employeeList.employees[i]->Clone());
	}
}

void EmployeeList::Destroy()
{
	for (int i = 0; i < this->employees.size(); i++)
	{
		delete this->employees[i];
	}
}