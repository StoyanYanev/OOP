#include <iostream>

#include"House.h"

int main()
{
	House firstHouse(100, 50, 3, 6, "Gosho");
	House secondHouse(150, 75, 4, 8, "Pesho");

	std::cout << "First house: "<<std::endl;
	std::cout << firstHouse << std::endl;

	std::cout << "Seconsd house: " << std::endl;
	std::cout << secondHouse << std::endl;
	std::cout << std::endl;
	
	if (firstHouse < secondHouse) //compare by number of rooms
	{
		std::cout << "The rooms of the second house is bigger than first!" << std::endl;
	}
	else
	{
		std::cout << "The rooms of the first house is bigger than second!" << std::endl;
	}

	std::cout << std::endl;
	if (firstHouse.GetTotalArea() < secondHouse.GetTotalArea())//compare by total area
	{
		std::cout << "Total area of the second house is bigger!" << std::endl;
	}
	else
	{
		std::cout << "Total area of the first house is bigger!" << std::endl;
	}
	std::cout << std::endl;

	system("pause");
}