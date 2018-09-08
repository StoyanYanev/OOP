#pragma once
#include <iostream>
#include <vector>
#include"Person.h"
#include "Patient.h"
class Doctor :public Person
{
public:
	Doctor(const std::string name, const std::string date);
	void AddPatient(const Patient p);
	void DeletePatient(const std::string name);
	void FindPatient(int visits)const;
	double AverageVisits()const;
	int NumberOfPatients()const;
	virtual void Print()const override;
	virtual ~Doctor();
private:
	std::vector<Patient> patient;
};

