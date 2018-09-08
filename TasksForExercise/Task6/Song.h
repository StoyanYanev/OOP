#pragma once
#include <iostream>

class Song
{
public:
	Song();
	Song(const char*title, const char*singer, int year, double duration);
	Song(const Song&song);
	Song &operator=(const Song&song);
	void SetTitle(const char*title);
	void SetSinger(const char*singer);
	void SetYear(int year);
	void SetDuration(double duration);
	const char* GetTitle()const;
	char* GetSinger()const;
	int GetYear()const;
	double GetDuration()const;
	friend std::ostream&operator<<(std::ostream&os, const Song& song);
	~Song();
private:
	void CopyFrom(const Song&song);
	void Destroy();

	char*title;
	char*singer;
	int year;
	double duration;
};