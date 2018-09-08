#include "Inventory.h"

Inventory::Inventory()
{
	this->maxSize = MAX_SIZE;
	this->devices = new Device*[this->maxSize];
	this->numberOfElements = 0;
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

void Inventory::Print() const
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		this->devices[i]->Print();
	}
}

void Inventory::Add(Device* device)
{
	if (this->numberOfElements + 1 >= maxSize)
	{
		Resize();
	}
	this->devices[this->numberOfElements] = device;
	this->numberOfElements++;
}


void Inventory::Delete(const char * manifacture)
{
	Device **newDevices = new Device*[this->maxSize];
	int index = 0;
	for (int i = 0; i < this->numberOfElements; i++)
	{
		if (strcmp(this->devices[i]->GetManafacture(), manifacture) != 0)
		{
			newDevices[index] = this->devices[i]->Clone();
			index++;
		}
	}
	Destroy();
	this->numberOfElements = index;
	for (int i = 0; i < this->numberOfElements; i++)
	{
		this->devices[i] = newDevices[i]->Clone();
	}
}

Inventory::~Inventory()
{
	Destroy();
}

void Inventory::Resize()
{
	Device **newDevices = new Device*[this->maxSize * 2];
	for (int i = 0; i < this->numberOfElements; i++)
	{
		newDevices[i] = this->devices[i]->Clone();
	}
	Destroy();
	for (int i = 0; i < this->numberOfElements; i++)
	{
		this->devices[i] = newDevices[i]->Clone();
	}
	this->maxSize *= 2;
}

void Inventory::CopyFrom(const Inventory & inv)
{
	this->maxSize = inv.maxSize;
	this->numberOfElements = inv.numberOfElements;
	for (int i = 0; i < inv.numberOfElements; i++)
	{
		this->devices[i] = inv.devices[i]->Clone();
	}
}

void Inventory::Destroy()
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		delete this->devices[i];
	}
	delete[] this->devices;
}