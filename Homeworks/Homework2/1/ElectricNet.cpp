#include <iostream>

#include "ElectricNet.h"

ElectricNet::ElectricNet()
{
	this->SetMaxElectricPower(0);
	m_currentPower = 0;
	SetArray();
}

ElectricNet::ElectricNet(int maxElectricPower)
{
	this->SetMaxElectricPower(maxElectricPower);
	m_currentPower = 0;
	SetArray();
}

ElectricNet::ElectricNet(const ElectricNet & electricNet)
{
	CopyFrom(electricNet);
}

ElectricNet& ElectricNet::operator=(const ElectricNet & electricNet)
{
	if (this != &electricNet)
	{
		Destroy();
		CopyFrom(electricNet);
	}
	return *this;
}

ElectricNet& ElectricNet::operator+=(const ElectricDevice & electDev) // add new device
{
	if (this->GetMaxElectricPower() >= m_currentPower + electDev.GetElectricPower())
	{
		AddDevice(*this, electDev);
	}
	else
	{
		std::cout << "Can't add new device! The electric net will be overloaded!" << std::endl;
	}
	return *this;
}

ElectricNet ElectricNet::operator+(const ElectricDevice& electDev) // add new device
{
	ElectricNet elNet(this->m_currentPower + electDev.GetElectricPower()); // creat new electric net
	elNet.m_numberOfDevice = this->m_numberOfDevice + 1;
	elNet.m_size = m_size + 1;
	int i = 0;
	for (i = 0; i <= elNet.m_numberOfDevice - 1; i++)
	{
		AddDevice(elNet, m_electricDevice[i]);
	}
	AddDevice(elNet, electDev);
	return elNet; // return new electric net
}

ElectricNet& ElectricNet::operator-=(const char * nameOfDevice) // remove device
{
	if (IsEmpty() == false)
	{
		ElectricDevice *newElectDev = new ElectricDevice[m_numberOfDevice - 1];
		bool isFindDevice = false;
		int newInd = 0;
		for (int i = 0; i < m_numberOfDevice; i++)
		{
			if (strcmp(m_electricDevice[i].GetNameOfDevice(), nameOfDevice) != 0)
			{
				newElectDev[newInd].SetElectricPower(m_electricDevice[i].GetElectricPower());
				newElectDev[newInd].SetNameOfDevice(m_electricDevice[i].GetNameOfDevice());
				newInd++;
			}
			else
			{
				m_currentPower -= m_electricDevice[i].GetElectricPower(); // decrement current power
				isFindDevice = true;
			}
		}
		Destroy();
		m_electricDevice = newElectDev;
		if (isFindDevice == true)
		{
			m_numberOfDevice--;
			std::cout << "The device " << nameOfDevice << " is remove successful from electric net!" << std::endl;
		}
		else
		{
			std::cout << "Can't find device by name: " << nameOfDevice << std::endl;
		}
	}
	else
	{
		std::cout << "Can't remove device from the electric net!" << std::endl;
	}
	return *this;
}

ElectricNet ElectricNet::operator-(const char * nameOfDevice) // remove device
{
	if (IsEmpty() == false)
	{
		bool isFindDevice = false;
		ElectricNet elNet(this->m_currentPower); // creat new electric net
		elNet.m_size = m_size;
		for (int i = 0; i < m_numberOfDevice; i++)
		{
			if (strcmp(m_electricDevice[i].GetNameOfDevice(), nameOfDevice) != 0)
			{
				AddDevice(elNet, m_electricDevice[i]);
			}
			else
			{
				isFindDevice = true;
			}
		}
		if (isFindDevice == true)
		{
			std::cout << "The device " << nameOfDevice << " is remove successful from electric net!" << std::endl;
		}
		else
		{
			std::cout << "Can't find device by name: " << nameOfDevice << std::endl;
		}
		return elNet;
	}
	else
	{
		std::cout << "Can't remove device from the electric net!" << std::endl;
		return *this;
	}
}

bool ElectricNet::operator!() // Check if there is any device plugged into the network
{
	if (IsEmpty() == true)
	{
		return false;
	}
	return true;
}

ElectricDevice ElectricNet::operator[](const char * nameOfDevice) // Get device by name
{
	bool isFind = false;
	for (int i = 0; i < m_numberOfDevice; i++)
	{
		if (strcmp(m_electricDevice[i].GetNameOfDevice(), nameOfDevice) == 0)
		{
			isFind = true;
			return m_electricDevice[i]; // return curren device
		}
	}
	if (isFind == false)
	{
		std::cout << "Can't find device by name: " << nameOfDevice << std::endl;
		return ElectricDevice(); // return empty device 
	}
}

ElectricNet& ElectricNet::operator++() //Prefix increment operator
{
	this->SetMaxElectricPower(this->GetMaxElectricPower() * 2);
	return *this;
}

ElectricNet& ElectricNet::operator++(int num) //Postfix increment operator
{
	num = 2;
	this->SetMaxElectricPower(this->GetMaxElectricPower() * num);
	return *this;
}

ElectricNet& ElectricNet::operator--() //Prefix decrement  operator
{
	int newPower = m_maxElectricPower / 2;
	if (m_currentPower <= newPower)
	{
		this->SetMaxElectricPower(newPower);
	}
	else
	{
		std::cout << "Can't reduce the power! The electirc net will be overloaded!" << std::endl;
	}
	return *this;
}

ElectricNet& ElectricNet::operator--(int num) //Postfix decrement  operator
{
	num = 2;
	int newPower = m_maxElectricPower /= 2;
	if (m_currentPower <= newPower)
	{
		this->SetMaxElectricPower(newPower);
	}
	else
	{
		std::cout << "Can't reduce the power! The electirc net will be overloaded!" << std::endl;
	}
	return *this;
}

void ElectricNet::SetMaxElectricPower(int maxElectricPower)
{
	if (maxElectricPower >= 0)
	{
		m_maxElectricPower = maxElectricPower;
	}
	else
	{
		std::cout << "The power of electricity can't be negative number!" << std::endl;
	}
}

int ElectricNet::GetMaxElectricPower() const
{
	return m_maxElectricPower;
}

void ElectricNet::PrintDevices() const
{
	for (int i = 0; i < m_numberOfDevice; i++)
	{
		std::cout << "The name of device: " << m_electricDevice[i].GetNameOfDevice()
			<< " with power: " << m_electricDevice[i].GetElectricPower() << std::endl;
	}
}

ElectricNet::~ElectricNet()
{
	Destroy();
}

void ElectricNet::CopyFrom(const ElectricNet& electricNet)
{
	this->SetMaxElectricPower(electricNet.GetMaxElectricPower());

	m_currentPower = electricNet.m_currentPower;
	m_numberOfDevice = electricNet.m_numberOfDevice;
	m_size = electricNet.m_size;
	m_electricDevice = new ElectricDevice[m_size];

	for (int i = 0; i < m_numberOfDevice; i++)
	{
		m_electricDevice[i].SetElectricPower(electricNet.m_electricDevice[i].GetElectricPower());
		m_electricDevice[i].SetNameOfDevice(electricNet.m_electricDevice[i].GetNameOfDevice());
	}
}

void ElectricNet::Destroy()
{
	delete[] m_electricDevice;
}

void ElectricNet::Resize()
{
	ElectricDevice *newElectDev = new ElectricDevice[2 * m_size];
	for (int i = 0; i < m_numberOfDevice; i++)
	{
		newElectDev[i].SetElectricPower(m_electricDevice[i].GetElectricPower());
		newElectDev[i].SetNameOfDevice(m_electricDevice[i].GetNameOfDevice());
	}
	Destroy();
	m_electricDevice = newElectDev;
	m_size *= 2;
}

void ElectricNet::SetArray()
{
	m_size = MAX_SIZE_OF_DEVICES;
	m_electricDevice = new ElectricDevice[m_size];
	m_numberOfDevice = 0;
}

bool ElectricNet::IsEmpty()const
{
	if (m_numberOfDevice - 1 >= 0)
	{
		return false;
	}
	return true;
}

void ElectricNet::AddDevice(ElectricNet& el, const ElectricDevice & electDev)
{
	if (m_numberOfDevice + 1 >= m_size)
	{
		Resize();
	}
	el.m_electricDevice[el.m_numberOfDevice].SetElectricPower(electDev.GetElectricPower());
	el.m_electricDevice[el.m_numberOfDevice].SetNameOfDevice(electDev.GetNameOfDevice());
	el.m_currentPower += electDev.GetElectricPower();
	el.m_numberOfDevice++;
}