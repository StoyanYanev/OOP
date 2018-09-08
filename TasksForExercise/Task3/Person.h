#pragma once
#include <iostream>
#include "Date.h"
class Person
{
public:
	Person();
	Person(const char* name, Date d);
	Person(const Person&p);
	Person operator=(const Person&p);
	void SetDate(Date d);
	void SetName(const char* name);
	const char* GetName()const;
	Date GetDate()const;
	friend std::ostream &operator<<(std::ostream &os, const Person&p);
	~Person();
private:
	void CopyFrom(const Person&p);
	void Destroy();

	char* name;
	Date d;
};

