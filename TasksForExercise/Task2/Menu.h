#pragma once

Inventory inventory;

void DisplayMenu();
void GetInputFromMenu(int input);
void Add(int choose);

void DisplayMenu()
{
	std::cout << "1. Add inventory" << std::endl;
	std::cout << "2. Print inventory" << std::endl;
	std::cout << "3. Check inventory is increase" << std::endl;
	std::cout << "4. Quit" << std::endl;
	std::cout << "Your choose is: ";
}

void GetInputFromMenu(int input)
{
	switch (input)
	{
	case 1:
	{
		int choose;
		std::cout << "1. Add car" << std::endl;
		std::cout << "2. Add laptop" << std::endl;
		std::cout << "Your choose is: ";
		std::cin >> choose;
		Add(choose);
		break;
	}
	case 2:
		inventory.PrintInventory();
		break;
	case 3:
		std::cout << "Is inventory increase: " << inventory.CheckInventory() << std::endl;
		break;
	case 4:
		exit(0);
	default:
		std::cout << "Invalide input!";
		break;
	}
}

inline void Add(int choose)
{
	std::string manufacturer;
	
	switch (choose)
	{
	case 1:
	{
		std::cout << "Enter manufacturer: ";
		std::cin >> manufacturer;
		inventory.AddInventory(manufacturer, "car");
		break;
	}
	case 2:
	{
		std::cout << "Enter manufacturer: ";
		std::cin >> manufacturer;
		inventory.AddInventory(manufacturer, "laptop");
		break;
	}
	default:
		std::cout << "Invalide input!";
		break;
	}
}