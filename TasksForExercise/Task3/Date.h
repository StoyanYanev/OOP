#pragma once
#include <iostream>
class Date
{
public:
	Date();
	Date(int day, int month, int year);
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;
	friend std::ostream &operator<<(std::ostream &os, const Date&d);
	~Date();
private:
	int day;
	int month;
	int year;
};

