#include <iostream>

#include "Car.h"
#include "Motorcycle.h"
#include"Truck.h"

int main()
{
	Car car("BMW", "X8", "black", 2010, 150.000);
	Motorcycle motorcycle("Aprilia", "Scarabeo ", "green", 2009, 3.000, "Chopper");
	Truck truck("Mercedes", "850", "blue", 1999, 110.000, 4);
	
	car.Details();
	std::cout << std::endl;
	
	motorcycle.Details();
	std::cout << std::endl;

	truck.Details();
	std::cout << std::endl;

	return 0;
}