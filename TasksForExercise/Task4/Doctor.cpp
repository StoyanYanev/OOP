#include "Doctor.h"

Doctor::~Doctor()
{
}

Doctor::Doctor(const std::string name, const std::string date) :Person(name, date)
{
}

void Doctor::AddPatient(const Patient p)
{
	this->patient.push_back(p);
}

void Doctor::DeletePatient(const std::string name)
{
	for (int i = 0; i < this->patient.size(); i++)
	{
		if (this->patient[i].GetName() == name)
		{
			this->patient.erase(this->patient.begin() + i);
		}
	}
}

void Doctor::FindPatient(int visits) const
{
	for (int i = 0; i < this->patient.size(); i++)
	{
		if (this->patient[i].GetVisits() > visits)
		{
			this->patient[i].Print();
		}
	}
}

double Doctor::AverageVisits() const
{
	double sum = 0;
	for (int i = 0; i < this->patient.size(); i++)
	{
		sum += this->patient[i].GetVisits();
	}
	return (sum / this->patient.size());
}

int Doctor::NumberOfPatients() const
{
	return this->patient.size();
}

void Doctor::Print() const
{
	for (int i = 0; i < this->patient.size(); i++)
	{
		this->patient[i].Print();
	}
}