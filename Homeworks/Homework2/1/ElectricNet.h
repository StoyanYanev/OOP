#ifndef ELECTRIC_NET_H
#define ELECTRIC_NET_H

#include"ElectricDevice.h"

class ElectricNet
{
public:
	ElectricNet();
	ElectricNet(int maxElectricPower);
	ElectricNet(const ElectricNet& electricNet);
	ElectricNet& operator=(const ElectricNet& electricNet);
	ElectricNet& operator +=(const ElectricDevice& electDev); //add new device
	ElectricNet operator+(const ElectricDevice& electDev); // add new device
	ElectricNet& operator -=(const char* nameOfDevice);   // remove device
	ElectricNet operator-(const char* nameOfDevice);     // remove device
	bool operator!();	 // Check if there is any device plugged into the network
	ElectricDevice operator[](const char* nameOfDevice); // Get device by name
	ElectricNet& operator++();			//Prefix increment operator
	ElectricNet&  operator++(int num); //Postfix increment operator
	ElectricNet& operator--();		  //Prefix decrement  operator
	ElectricNet& operator--(int num);		 //Postfix decrement  operator
	void SetMaxElectricPower(int maxElectricPower);
	int GetMaxElectricPower()const;
	void PrintDevices()const;
	~ElectricNet();
private:
	void CopyFrom(const ElectricNet& electricNet);
	void Destroy();
	void Resize();
	void SetArray();
	bool IsEmpty()const;
	void AddDevice(ElectricNet& el, const ElectricDevice & electDev);

	enum { MAX_SIZE_OF_DEVICES = 20 };
	int m_maxElectricPower;
	int m_currentPower;		// save current power of device

	ElectricDevice* m_electricDevice;
	int m_numberOfDevice; // index of array
	int m_size;          //size of array
};
#endif