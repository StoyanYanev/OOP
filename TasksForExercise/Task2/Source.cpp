#include <iostream>
#include <cstdlib>

#include "Car.h"
#include "Laptop.h"
#include "Inventory.h"
#include "Menu.h"

int main()
{
	int choose;
	while (true)
	{
		DisplayMenu();
		std::cin >> choose;
		GetInputFromMenu(choose);
	}
	return 0;
}