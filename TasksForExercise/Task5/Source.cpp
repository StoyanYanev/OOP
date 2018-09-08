#include <iostream>

#include"Developer.h"
#include"Manager.h"
#include "SoftwareCompany.h"

int main()
{
	SoftwareCompany company;

	company.NewEmployee("developer", "Pesho", 2, 1000);
	company.NewEmployee("developer", "Gosho", 4, 3000);
	company.NewEmployee("manager", "Misho", 6, 5000);
	company.PrintAll();

	std::cout << std::endl;
	std::cout << "Sum of salaries: " << company.SumSalary() << std::endl;
	std::cout << std::endl;

	company.IncreaseSalaryOfAllEmployees();
	company.PrintAll();
	std::cout << std::endl;

	company.RemoveRecentlyEmployed(3);
	company.PrintAll();
	std::cout << std::endl;

	return 0;
}