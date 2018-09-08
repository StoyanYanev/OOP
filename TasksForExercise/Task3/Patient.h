#pragma once
#include <iostream>
#include "Person.h"
class Patient :public Person
{
public:
	Patient();
	Patient(const char* name, Date d, int visit);
	void SetVisit(int visit);
	int GetVisit()const;
	friend std::ostream &operator<<(std::ostream &os, const Patient&p);
	~Patient();
private:
	int visit;
};

