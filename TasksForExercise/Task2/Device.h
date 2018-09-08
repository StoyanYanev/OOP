#ifndef DEVICE_H
#define DEVICE_H

#include<iostream>
#include <string>

class Device
{
public:
	Device();
	Device(const std::string manufacturer);
	void SetManufacturer(const std::string manufacturer);
	const std::string GetManufacturer()const;
	virtual Device *Clone() = 0;
	virtual void Print()const = 0;
	virtual int GetPerf()const = 0;
	virtual ~Device();
private:
	std::string manufacturer;
};
#endif