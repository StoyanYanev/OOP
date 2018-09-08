#include "Car.h"

Car::Car(const char * manufacture, int power, int capacity) :Device(manufacture)
{
	this->SetPower(power);
	this->SetCapacity(capacity);
}

void Car::SetPower(int power)
{
	this->power = power;
}

void Car::SetCapacity(int capacity)
{
	this->capacity = capacity;
}

int Car::GetCapacity() const
{
	return this->capacity;
}

Device * Car::Clone()
{
	return new Car(*this);
}

void Car::Print() const
{
	Device::Print();
	std::cout << " Speed: " << this->GetPref() << " Cpacity: " << this->GetCapacity() << std::endl;
}

int Car::GetPref() const
{
	return this->power;
}

Car::~Car()
{
}