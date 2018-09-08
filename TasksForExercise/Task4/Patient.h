#pragma once
#include "Person.h"
class Patient :public Person
{
public:
	Patient(const std::string name, const std::string date, int visits);
	void SetVisits(int visits);
	int GetVisits()const;
	virtual void Print()const override;
	virtual ~Patient();
private:
	int visits;
};

