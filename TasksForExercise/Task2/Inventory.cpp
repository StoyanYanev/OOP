#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::Inventory(const Inventory & inv)
{
	CopyFrom(inv);
}

Inventory & Inventory::operator=(const Inventory & inv)
{
	if (this != &inv)
	{
		Destroy();
		CopyFrom(inv);
	}
	return *this;
}

void Inventory::AddInventory(const std::string manufacturer, const std::string typeOfDevice)
{
	if (typeOfDevice == "car")
	{
		int power;
		int capacity;
		std::cout << "Power: ";
		std::cin >> power;
		std::cout << "Capacity: ";
		std::cin >> capacity;
		this->devices.push_back(new Car(manufacturer, power, capacity));
	}
	else
	{
		int speed;
		std::cout << "Speed: ";
		std::cin >> speed;
		this->devices.push_back(new Laptop(manufacturer, speed));
	}
}

void Inventory::PrintInventory() const
{
	for (int i = 0; i < this->devices.size(); i++)
	{
		this->devices[i]->Print();
	}
}

bool Inventory::CheckInventory() const
{
	for (int i = 0; i < this->devices.size(); i++)
	{
		for (int j = i+1; j <= this->devices.size() - 1; j++)
		{
			if (this->devices[i]->GetPerf() > this->devices[j]->GetPerf())
			{
				return false;
			}
		}
	}
	return true;
}


Inventory::~Inventory()
{
	Destroy();
}

void Inventory::CopyFrom(const Inventory & inv)
{
	for (int i = 0; i < this->devices.size(); i++)
	{
		this->devices.push_back(inv.devices[i]->Clone());
	}
}

void Inventory::Destroy()
{
	for (int i = 0; i < this->devices.size(); i++)
	{
		delete this->devices[i];
	}
}