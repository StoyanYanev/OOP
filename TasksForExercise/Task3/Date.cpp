#include "Date.h"

Date::Date()
{
	this->SetDay(0);
	this->SetMonth(0);
	this->SetYear(0);
}

Date::Date(int day, int month, int year)
{
	this->SetDay(day);
	this->SetMonth(month);
	this->SetYear(year);
}

void Date::SetDay(int day)
{
	this->day = day;
}

void Date::SetMonth(int month)
{
	this->month = month;
}

void Date::SetYear(int year)
{
	this->year = year;
}

int Date::GetDay() const
{
	return this->day;
}

int Date::GetMonth() const
{
	return this->month;
}

int Date::GetYear() const
{
	return this->year;
}

Date::~Date()
{
}

std::ostream & operator<<(std::ostream & os, const Date & d)
{
	os << "Day: "<<d.GetDay()<<" Month: " << d.GetMonth()<<" Year: " << d.GetYear() << std::endl;
	return os;
}
