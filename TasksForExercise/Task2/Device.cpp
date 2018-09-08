#include "Device.h"

Device::Device()
{
}

Device::Device(const std::string manufacturer)
{
	this->SetManufacturer(manufacturer);
}

void Device::SetManufacturer(const std::string manufacturer)
{
	this->manufacturer = manufacturer;
}

const std::string Device::GetManufacturer() const
{
	return this->manufacturer;
}

void Device::Print() const
{
	std::cout << "Manufacturer: " << this->GetManufacturer() << std::endl;
}

Device::~Device()
{
}