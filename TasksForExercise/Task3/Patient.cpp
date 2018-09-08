#include "Patient.h"

Patient::Patient() :Person()
{
	this->SetVisit(0);
}

Patient::Patient(const char * name, Date d, int visit) : Person(name, d)
{
	this->SetVisit(visit);
}

void Patient::SetVisit(int visit)
{
	if (visit >= 0)
	{
		this->visit = visit;
	}
	else
	{
		std::cout << "Visit can't be negative!" << std::endl;
	}
}

int Patient::GetVisit() const
{
	return this->visit;
}

Patient::~Patient()
{
}

std::ostream & operator<<(std::ostream & os, const Patient & p)
{
	os << (const Person&)p;
	os << "Visits: " << p.GetVisit() << std::endl;
	return os;
}
