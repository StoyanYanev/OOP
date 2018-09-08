#pragma once
#include <iostream>
#include "Person.h"
#include "Patient.h"
class Doctor :public Person
{
public:
	Doctor();
	Doctor(const char* name, Date d, int reg);
	Doctor(const Doctor&d);
	Doctor operator=(const Doctor&d);
	void AddPatient(const Patient& p);
	void DeletePatient(const char*name);
	double Average()const;
	void PrintUpper(int visit)const;
	friend std::ostream &operator<<(std::ostream &os, const Doctor&d);
	~Doctor();
private:
	void CopyFrom(const Doctor&d);
	void Destroy();
	void Resize();

	enum { MAX_PATIENT = 100 };
	Patient * p;
	int numberOfPatient;
	int maxPatient;
};

