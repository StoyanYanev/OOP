#include "Motorcycle.h"

Motorcycle::Motorcycle() :Vehicle()
{
	this->SetType("");
}

Motorcycle::Motorcycle(const char * brand, const char * model, const char * color, int year, double mileage, const char * typeOfMot)
	: Vehicle(brand, model, color, year, mileage)
{
	this->SetType(typeOfMot);
}

Motorcycle::Motorcycle(const Motorcycle & m) : Vehicle(m)
{
	CopyFrom(m);
}

Motorcycle & Motorcycle::operator=(const Motorcycle & m)
{
	if (this != &m)
	{
		Vehicle::operator=(m);
		Destroy();
		CopyFrom(m);
	}
	return *this;
}

void Motorcycle::SetType(const char * typeOfMot)
{
	int l = strlen(typeOfMot);
	m_typeOfMot = new char[l + 1];
	strcpy_s(m_typeOfMot, l + 1, typeOfMot);
}

const char * Motorcycle::GetType() const
{
	return m_typeOfMot;
}

void Motorcycle::Details() const
{
	Vehicle::Details();
	std::cout << "Type: " << this->GetType() << std::endl;
}

Motorcycle::~Motorcycle()
{
	Destroy();
}

void Motorcycle::CopyFrom(const Motorcycle & m)
{
	this->SetType(m.GetType());
}

void Motorcycle::Destroy()
{
	delete[] m_typeOfMot;
}