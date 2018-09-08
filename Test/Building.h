#pragma once

#include <iostream>

class Building
{
public:
	Building();
	Building(int metra, int place, int floors);
	void SetMetra(int metra);
	void SetPlace(int place);
	void SetFloors(int floors);
	int GetMetra()const;
	int GetFloors()const;
	int GetPlace()const;
	int GetTotalArea()const;
	bool operator<(const Building&b)const;
	friend std::ostream &operator<<(std::ostream &os, const Building&b);
	~Building();
private:
	int metra;
	int place;
	int floors;
};