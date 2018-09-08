#pragma once

#include <iostream>
#include "Building.h"

class House :public Building
{
public:
	House();
	House(int metra, int place, int floors,int rooms, const char* nameOfOwner);
	House(const House& h);
	House &operator=(const House&h);
	void SetNameOfOwner(const char*name);
	void SetRooms(int rooms);
	const char* GetNameOfOwner()const;
	int GetRooms()const;
	bool operator<(const House&h)const;
	friend std::ostream &operator<<(std::ostream &os, const House&h);
	~House();
private:
	void CopyFrom(const House&h);
	void Destroy();

	int rooms;
	char* nameOfOwner;
};