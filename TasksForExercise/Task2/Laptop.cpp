#include "Laptop.h"

Laptop::Laptop(const std::string manufacturer, int speed) :Device(manufacturer)
{
	this->SetSpeed(speed);
}

Laptop::Laptop(const Laptop & laptop)
{
	this->SetManufacturer(laptop.GetManufacturer());
	this->SetSpeed(laptop.GetPerf());
}

void Laptop::SetSpeed(int speed)
{
	if (speed >= 0)
	{
		this->speed = speed;
	}
	else
	{
		std::cout << "The speed can not be negative!" << std::endl;
	}
}

Device * Laptop::Clone()
{
	return new Laptop(*this);
}

void Laptop::Print() const
{
	Device::Print();
	std::cout << "Speed: " << this->GetPerf() << std::endl;
}

int Laptop::GetPerf() const
{
	return this->speed;
}

Laptop::~Laptop()
{
}