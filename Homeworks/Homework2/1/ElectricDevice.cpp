#include "ElectricDevice.h"

ElectricDevice::ElectricDevice()
{
	this->SetNameOfDevice("No name");
	this->SetElectricPower(0);
}

ElectricDevice::ElectricDevice(const char * nameOfDevice, int electricPower)
{
	this->SetNameOfDevice(nameOfDevice);
	this->SetElectricPower(electricPower);
}

ElectricDevice::ElectricDevice(const ElectricDevice & electricDev)
{
	CopyFrom(electricDev);
}

ElectricDevice & ElectricDevice::operator=(const ElectricDevice & electricDev)
{
	if (this != &electricDev)
	{
		Destroy();
		CopyFrom(electricDev);
	}
	return *this;
}

void ElectricDevice::SetNameOfDevice(const char * nameOfDevice)
{
	int l = strlen(nameOfDevice);
	m_nameOfDevice = new char[l + 1];
	strcpy_s(m_nameOfDevice, l + 1, nameOfDevice);
}

void ElectricDevice::SetElectricPower(int electricPower)
{
	m_electricPower = electricPower;
}

const char * ElectricDevice::GetNameOfDevice() const
{
	return m_nameOfDevice;
}

int ElectricDevice::GetElectricPower() const
{
	return m_electricPower;
}

void ElectricDevice::CopyFrom(const ElectricDevice & electricDev)
{
	int l = strlen(electricDev.GetNameOfDevice());
	m_nameOfDevice = new char[l + 1];
	strcpy_s(m_nameOfDevice, l + 1, electricDev.GetNameOfDevice());
	m_electricPower = electricDev.GetElectricPower();
}

void ElectricDevice::Destroy()
{
	delete[] m_nameOfDevice;
}

ElectricDevice::~ElectricDevice()
{
	Destroy();
}

std::ostream & operator<<(std::ostream & os, const ElectricDevice & d)
{
	os << "Name of device: " << d.GetNameOfDevice() << " with power: " << d.GetElectricPower();
	return os;
}