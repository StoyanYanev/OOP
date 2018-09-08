#include <iostream>

#include "Car.h"
#include"Laptop.h"
#include "Inventory.h"

int main()
{
	Inventory inv;

	Device* d = new Car("bmw", 5, 20);
	Device* d1 = new Laptop("toshiba", 40);;
	inv.Add(d);
	inv.Add(d1);

	inv.Print();

	inv.Delete("bmw");
	inv.Print();

	return 0;
}