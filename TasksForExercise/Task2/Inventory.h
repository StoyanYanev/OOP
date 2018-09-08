#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include <vector>
#include <string>

#include "Car.h"
#include "Laptop.h"

class Inventory
{
public:
	Inventory();
	Inventory(const Inventory& inv);
	Inventory &operator=(const Inventory& inv);
	void AddInventory(const std::string manufacturer, const std::string typeOfDevice);
	void PrintInventory()const;
	bool CheckInventory()const;
	~Inventory();
private:
	void CopyFrom(const Inventory& inv);
	void Destroy();

	std::vector<Device*> devices;
};
#endif