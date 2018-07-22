#include "Truck.h"

Truck::Truck() :Vehicle()
{
	this->SetSize(0);
}

Truck::Truck(const char * brand, const char * model, const char * color, int year, double mileage, int size) :
	Vehicle(brand, model, color, year, mileage)
{
	this->SetSize(size);
}

void Truck::SetSize(int size)
{
	if (size >= 0)
	{
		m_size = size;
	}
	else
	{
		std::cout << "The size can't be negative!" << std::endl;
	}
}

int Truck::GetSize() const
{
	return m_size;
}

void Truck::Details() const
{
	Vehicle::Details();
	std::cout << "Size: " << this->GetSize() << std::endl;
}

Truck::~Truck()
{
}
