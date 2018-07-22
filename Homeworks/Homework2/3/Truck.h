#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(const char *brand, const char* model, const char* color, int year, double mileage,int size);
	void SetSize(int size);
	int GetSize()const;
	virtual void Details()const;
	~Truck();

private:
	int m_size;
};
#endif