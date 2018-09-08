#include "Laptop.h"

Laptop::Laptop(const char * manufacture, int speed) :Device(manufacture)
{
	this->SetSpeed(speed);
}

void Laptop::SetSpeed(int speed)
{
	this->speed = speed;
}

Device * Laptop::Clone()
{
	return new Laptop(*this);
}

void Laptop::Print() const
{
	Device::Print();
	std::cout << " Speed: " << this->GetPref() << std::endl;
}

int Laptop::GetPref() const
{
	return this->speed;
}

Laptop::~Laptop()
{
}