#include "House.h"

House::House() :Building()
{
	this->SetRooms(0);
	this->SetNameOfOwner("");
}

House::House(int metra, int place, int floors, int rooms, const char * nameOfOwner) :Building(metra, place, floors)
{
	this->SetRooms(rooms);
	this->SetNameOfOwner(nameOfOwner);
}

House::House(const House & h) :Building(h)
{
	CopyFrom(h);
}

House & House::operator=(const House & h)
{
	if (this != &h)
	{
		Building::operator=(h);
		Destroy();
		CopyFrom(h);
	}
	return *this;
}

void House::SetNameOfOwner(const char * name)
{
	int l = strlen(name);
	this->nameOfOwner = new char[l + 1];
	strcpy_s(this->nameOfOwner, l + 1, name);
}

void House::SetRooms(int rooms)
{
	if (rooms >= 0)
	{
		this->rooms = rooms;
	}
	else
	{
		std::cout << "The rooms can't be negative!" << std::endl;
	}
}

const char * House::GetNameOfOwner() const
{
	return this->nameOfOwner;
}

int House::GetRooms() const
{
	return this->rooms;
}

bool House::operator<(const House & h)const
{
	if (this->GetRooms() < h.GetRooms())
	{
		return true;
	}
	return false;
}

House::~House()
{
	Destroy();
}

void House::CopyFrom(const House & h)
{
	this->SetRooms(h.GetRooms());
	this->SetNameOfOwner(h.GetNameOfOwner());
}

void House::Destroy()
{
	delete[]this->nameOfOwner;
}

std::ostream & operator<<(std::ostream & os, const House & h)
{
	os << (const Building&)h;
	os << "Rooms: " << h.GetRooms() << " " << "Name of owner: " << h.GetNameOfOwner() << std::endl;
	return os;
}