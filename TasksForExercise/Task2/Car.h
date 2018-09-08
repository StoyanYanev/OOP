#ifndef CAR_H
#define CAR_H

#include "Device.h"

class Car : public Device
{
public:
	Car(const std::string manufacturer, int power, int capacity);
	Car(const Car& car);
	void SetPower(int power);
	void SetCapacity(int capacity);
	int GetCapacity()const;
	virtual Device *Clone() override;
	virtual void Print()const override;
	virtual int GetPerf()const override;
	virtual ~Car();
private:
	int power;
	int capacity;
};
#endif