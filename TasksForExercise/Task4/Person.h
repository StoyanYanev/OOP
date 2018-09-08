#pragma once
#include <iostream>
#include <string>
class Person
{
public:
	Person(const std::string name, const std::string date);
	void SetName(const std::string name);
	const std::string GetName()const;
	void SetDate(const std::string date);
	const std::string GetDate()const;
	virtual void Print()const = 0;
	virtual ~Person();
private:
	std::string name;
	std::string date;
};