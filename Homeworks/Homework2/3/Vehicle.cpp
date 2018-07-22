#include <iostream>

#include "Vehicle.h"

Vehicle::Vehicle()
{
	this->SetBrand("");
	this->SetModel("");
	this->SetColor("");
	this->SetYear(0);
	this->SetMileage(0);
}

Vehicle::Vehicle(const char * brand, const char * model, const char * color, int year, double mileage)
{
	this->SetBrand(brand);
	this->SetModel(model);
	this->SetColor(color);
	this->SetYear(year);
	this->SetMileage(mileage);
}

Vehicle::Vehicle(const Vehicle & v)
{
	CopyFrom(v);
}

Vehicle & Vehicle::operator=(const Vehicle & v)
{
	if (this != &v)
	{
		Destroy();
		CopyFrom(v);
	}
	return *this;
}

const char * Vehicle::GetBrand() const
{
	return m_brand;
}

const char * Vehicle::GetModel() const
{
	return m_model;
}

const char * Vehicle::GetColor() const
{
	return m_color;
}

int Vehicle::GetYear() const
{
	return m_year;
}

double Vehicle::GetMileage() const
{
	return m_mileage;
}

void Vehicle::SetBrand(const char * brand)
{
	int l = strlen(brand);
	m_brand = new char[l + 1];
	strcpy_s(m_brand, l + 1, brand);
}

void Vehicle::SetModel(const char * model)
{
	int l = strlen(model);
	m_model = new char[l + 1];
	strcpy_s(m_model, l + 1, model);
}

void Vehicle::SetColor(const char * color)
{
	int l = strlen(color);
	m_color = new char[l + 1];
	strcpy_s(m_color, l + 1, color);
}

void Vehicle::SetYear(int year)
{
	if (year >= 0)
	{
		m_year = year;
	}
	else
	{
		std::cout << "The year can't be negative!" << std::endl;
	}

}

void Vehicle::SetMileage(double mileage)
{
	if (mileage >= 0)
	{
		m_mileage = mileage;
	}
	else
	{
		std::cout << "The mileage can't be negative!" << std::endl;
	}
}

Vehicle::~Vehicle()
{
	Destroy();
}

void Vehicle::CopyFrom(const Vehicle & v)
{
	this->SetBrand(v.GetBrand());
	this->SetModel(v.GetModel());
	this->SetColor(v.GetColor());
	this->SetYear(v.GetYear());
	this->SetMileage(v.GetMileage());
}

void Vehicle::Details()const
{
	std::cout << "Brand: " << this->GetBrand() << "\nModel: " << this->GetModel() << "\nColor: " << this->GetColor()
		<< "\nYear: " << this->GetYear() << "\nMileage: " << this->GetMileage() << std::endl;
}

void Vehicle::Destroy()
{
	delete[] m_brand;
	delete[] m_model;
	delete[] m_color;
}