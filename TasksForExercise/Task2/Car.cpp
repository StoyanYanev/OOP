#include "Car.h"

Car::~Car()
{
}

Car::Car(const std::string manufacturer, int power, int capacity) :Device(manufacturer)
{
	this->SetPower(power);
	this->SetCapacity(capacity);
}

Car::Car(const Car & car)
{
	this->SetManufacturer(car.GetManufacturer());
	this->SetCapacity(car.GetCapacity());
	this->SetPower(car.GetPerf());
}

void Car::SetPower(int power)
{
	if (power >= 0)
	{
		this->power = power;
	}
	else
	{
		std::cout << "The power can not be negative!" << std::endl;
	}
}

void Car::SetCapacity(int capacity)
{
	if (capacity >= 0)
	{
		this->capacity = capacity;
	}
	else
	{
		std::cout << "The capacity can not be negative!" << std::endl;
	}
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
	std::cout << "Power: " << this->GetPerf() << " Capacity: " << this->GetCapacity() << std::endl;
}

int Car::GetPerf() const
{
	return this->power;
}