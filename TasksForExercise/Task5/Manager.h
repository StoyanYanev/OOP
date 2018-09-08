#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
public:
	Manager(std::string name, int period, double salary, int inChargeOf);
	Manager(const Manager& manager);
	void SetInChargeOf(int inChargeOf);
	int GetInChargeOf()const;
	virtual Employee *Clone() override;
	virtual Type type() override;
	virtual void Print()const override;
	virtual ~Manager();
private:
	int inChargeOf;
};
#endif