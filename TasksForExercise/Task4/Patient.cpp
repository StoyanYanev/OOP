#include "Patient.h"

Patient::Patient(const std::string name, const std::string date, int visits) :Person(name, date)
{
	this->SetVisits(visits);
}

void Patient::SetVisits(int visits)
{
	this->visits = visits;
}

int Patient::GetVisits() const
{
	return this->visits;
}

void Patient::Print() const
{
	Person::Print();
	std::cout << " visits: " << this->GetVisits() << std::endl;
}

Patient::~Patient()
{
}
