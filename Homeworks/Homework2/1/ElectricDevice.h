#ifndef ELECTRIC_DEVICE_H
#define ELECTRIC_DEVICE_H

#include <iostream>

class ElectricDevice
{
public:
	ElectricDevice();
	ElectricDevice(const char* nameOfDevice, int electricPower);
	ElectricDevice(const ElectricDevice& electricDev);
	ElectricDevice &operator=(const ElectricDevice& electricDev);
	void SetNameOfDevice(const char* nameOfDevice);
	void SetElectricPower(int electricPower);
	const char* GetNameOfDevice()const;
	int GetElectricPower()const;
	friend std::ostream &operator<<(std::ostream& os, const ElectricDevice& d);
	~ElectricDevice();
private:
	void CopyFrom(const ElectricDevice& electricDev);
	void Destroy();

	char* m_nameOfDevice;
	int m_electricPower;
};
#endif