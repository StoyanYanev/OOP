#pragma once
#include "Device.h"

class Laptop : public Device
{
public:
	Laptop(const char * manufacture, int speed);
	void SetSpeed(int speed);

	virtual  Device* Clone() override;
	virtual void Print()const override;
	virtual int GetPref()const override;
	virtual ~Laptop();

private:
	int speed;
};