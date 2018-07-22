#include "Car.h"

Car::Car() :Vehicle()
{
}

Car::Car(const char * brand, const char * model, const char * color, int year, double mileage)
	: Vehicle(brand, model, color, year, mileage)
{
}

Car::Car(const Car & c) : Vehicle(c)
{
}

Car & Car::operator=(const Car & c)
{
	if (this != &c)
	{
		Vehicle::operator=(c);
	}
	return *this;
}

void Car::Details() const
{
	Vehicle::Details();
}

Car::~Car()
{
}