#pragma once
#include <iostream>

class Device
{
public:
	Device();
	Device(const char* manufacture);
	Device(const Device& d);
	Device &operator=(const Device& d);
	void SetManufacture(const char* manufacture);
	const char* GetManafacture()const;

	virtual  Device* Clone() = 0;
	virtual void Print()const = 0;
	virtual int GetPref()const = 0;
	virtual ~Device();

private:
	void CopyFrom(const Device& d);
	void Destroy();

	enum { SIZE = 50 };
	char* manufacture;
};