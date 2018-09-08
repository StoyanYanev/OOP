#include "Person.h"

Person::Person(const std::string name, const std::string date)
{
	this->SetName(name);
	this->SetDate(date);
}

void Person::SetName(const std::string name)
{
	this->name = name;
}

const std::string Person::GetName() const
{
	return this->name;
}

void Person::SetDate(const std::string date)
{
	this->date = date;
}

const std::string Person::GetDate() const
{
	return this->date;
}

void Person::Print() const
{
	std::cout << "Name: " << this->GetName() << " date: " << this->GetDate() << std::endl;
}

Person::~Person()
{
}
