#ifndef LAPTOP_H
#define LAPTOP_H

#include "Device.h"

class Laptop : public Device
{
public:
	Laptop(const std::string manufacturer, int speed);
	Laptop(const Laptop& laptop);
	void SetSpeed(int speed);
	virtual Device *Clone() override;
	virtual void Print()const override;
	virtual int GetPerf()const override;
	virtual ~Laptop();
private:
	int speed;
};
#endif