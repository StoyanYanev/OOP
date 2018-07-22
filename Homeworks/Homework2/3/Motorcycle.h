#ifndef MOTOCYCLE_H
#define MOTOCYCLE_H

#include <iostream>

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	Motorcycle(const char *brand, const char* model, const char* color, int year, double mileage, const char* typeOfMot);
	Motorcycle(const Motorcycle& m);
	Motorcycle& operator=(const Motorcycle& m);
	void SetType(const char* typeOfMot);
	const char* GetType()const;
	virtual void Details()const;
	~Motorcycle();
private:
	void CopyFrom(const Motorcycle& m);
	void Destroy();

	char* m_typeOfMot;
};
#endif