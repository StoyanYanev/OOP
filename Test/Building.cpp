#include "Building.h"

Building::Building()
{
	this->SetMetra(0);
	this->SetPlace(0);
	this->SetFloors(0);
}

Building::Building(int metra, int place, int floors)
{
	this->SetMetra(metra);
	this->SetPlace(place);
	this->SetFloors(floors);
}

void Building::SetMetra(int metra)
{
	if (metra >= 0)
	{
		this->metra = metra;
	}
	else
	{
		std::cout << "The metra can't be negative!" << std::endl;
	}
}

void Building::SetPlace(int place)
{
	if (place >= 0)
	{
		this->place = place;
	}
	else
	{
		std::cout << "The place can't be negative!" << std::endl;
	}

}

void Building::SetFloors(int floors)
{
	if (floors >= 0)
	{
		this->floors = floors;
	}
	else
	{
		std::cout << "The floors can't be negative!" << std::endl;
	}
}

int Building::GetMetra() const
{
	return this->metra;
}

int Building::GetFloors() const
{
	return this->floors;
}

int Building::GetPlace() const
{
	return this->place;
}

int Building::GetTotalArea() const
{
	return this->place * this->floors;
}

bool Building::operator<(const Building & b)const
{
	if (this->GetTotalArea() < b.GetTotalArea())
	{
		return true;
	}
	return false;
}

std::ostream & operator<<(std::ostream & os, const Building & b)
{
	os << "Metra: " << b.GetMetra() << " " << "Place: " << b.GetPlace() << " " << "Floors: " << b.GetFloors() << std::endl;
	return os;
}

Building::~Building()
{
}