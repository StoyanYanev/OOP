#include "Person.h"

Person::Person()
{
	this->SetName("");
	Date d(0, 0, 0);
	this->SetDate(d);
}

Person::Person(const char * name, Date d)
{
	this->SetName(name);
	this->SetDate(d);
}

Person::Person(const Person & p)
{
	CopyFrom(p);
}

Person Person::operator=(const Person & p)
{
	if (this != &p)
	{
		Destroy();
		CopyFrom(p);
	}
	return *this;
}

void Person::SetDate(Date d)
{
	this->d.SetDay(d.GetDay());
	this->d.SetMonth(d.GetMonth());
	this->d.SetYear(d.GetYear());
}

void Person::SetName(const char * name)
{
	int l = strlen(name);
	this->name = new char[l + 1];
	strcpy_s(this->name, l + 1, name);
}

const char * Person::GetName() const
{
	return this->name;
}

Date Person::GetDate() const
{
	return this->d;
}


Person::~Person()
{
	Destroy();
}

void Person::CopyFrom(const Person & p)
{
	this->SetName(p.GetName());
	this->SetDate(p.GetDate());
}

void Person::Destroy()
{
	delete[]this->name;
}

std::ostream & operator<<(std::ostream & os, const Person & p)
{
	os << "Name: " << p.GetName() << " " << p.GetDate();
	return os;
}
