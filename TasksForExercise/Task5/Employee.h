#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

enum Type { DEVELOPER = 1, MANAGER };

class Employee
{
public:
	Employee();
	Employee(std::string name, int period, double salary);
	void SetName(const std::string name);
	void SetPeriod(int period);
	void SetSalary(double salary);
	const std::string GetName()const;
	int GetPeriod()const;
	double GetSalary()const;

	virtual Employee *Clone() = 0;
	virtual Type type() = 0;
	virtual void Print()const = 0;
	virtual ~Employee();
protected:
	std::string name;
	int period;
	double salary;
};
#endif