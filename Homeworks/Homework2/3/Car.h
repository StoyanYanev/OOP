#ifndef Car_H
#define Car_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(const char *m_brand, const char* m_model, const char* m_color, int m_year, double m_mileage);
	Car(const Car&c);
	Car& operator=(const Car&c);
	virtual void Details()const;
	~Car();
};
#endif