#pragma once
#include "Device.h"

class Car : public Device
{
public:
	Car(const char* manufacture, int power, int capacity);
	void SetPower(int power);
	void SetCapacity(int capacity);
	int GetCapacity()const;

	virtual  Device* Clone() override;
	virtual void Print()const override;
	virtual int GetPref()const override;
	virtual ~Car();

private:
	int power;
	int capacity;
};