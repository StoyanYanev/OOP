#pragma once
#include "Car.h"
#include "Laptop.h"

class Inventory
{
public:
	Inventory();
	Inventory(const Inventory& inv);
	Inventory &operator=(const Inventory& inv);
	void Print()const;
	void Add( Device* device);
	void Delete(const char* manifacture);
	~Inventory();
private:
	void Resize();
	void CopyFrom(const Inventory& inv);
	void Destroy();

	enum { MAX_SIZE = 50 };
	Device **devices;
	int maxSize;
	int numberOfElements;
};