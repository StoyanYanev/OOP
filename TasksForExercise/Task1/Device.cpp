#include "Device.h"

Device::Device()
{
	this->SetManufacture("");
}

Device::Device(const char * manufacture)
{
	this->SetManufacture(manufacture);
}

Device::Device(const Device & d)
{
	CopyFrom(d);
}

Device & Device::operator=(const Device & d)
{
	if (this != &d)
	{
		Destroy();
		CopyFrom(d);
	}
	return *this;
}

void Device::SetManufacture(const char * manufacture)
{
	int l = strlen(manufacture);
	this->manufacture = new char[l + 1];
	strcpy_s(this->manufacture, l + 1, manufacture);
}

const char * Device::GetManafacture() const
{
	return this->manufacture;
}

void Device::Print() const
{
	std::cout << "Manufacture: " << this->GetManafacture();
}

void Device::Destroy()
{
	delete[]this->manufacture;
}

Device::~Device()
{
	Destroy();
}

void Device::CopyFrom(const Device & d)
{
	this->SetManufacture(d.GetManafacture());
}