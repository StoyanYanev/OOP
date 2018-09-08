#include "Manager.h"

Manager::Manager(std::string name, int period, double salary, int inChargeOf) :Employee(name, period, salary)
{
	this->SetInChargeOf(inChargeOf);
}

Manager::Manager(const Manager & manager)
{
	this->SetName(manager.GetName());
	this->SetPeriod(manager.GetPeriod());
	this->SetSalary(manager.GetSalary());
	this->SetInChargeOf(manager.GetInChargeOf());
}

void Manager::SetInChargeOf(int inChargeOf)
{
	if (inChargeOf >= 0)
	{
		this->inChargeOf = inChargeOf;
	}
	else
	{
		std::cout << "The in charge of can not be negative!" << std::endl;
	}
}

int Manager::GetInChargeOf() const
{
	return this->inChargeOf;
}

Employee * Manager::Clone()
{
	return new Manager(*this);
}

Type Manager::type()
{
	return MANAGER;
}

void Manager::Print() const
{
	Employee::Print();
	std::cout << " in charge of: " << this->GetInChargeOf() << std::endl;
}

Manager::~Manager()
{
}