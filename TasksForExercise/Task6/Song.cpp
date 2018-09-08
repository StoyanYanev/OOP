#include "Song.h"

Song::Song()
{
	this->SetTitle("");
	this->SetSinger("");
	this->SetYear(0);
	this->SetDuration(0);
}

Song::Song(const char * title, const char * singer, int year, double duration)
{
	this->SetTitle(title);
	this->SetSinger(singer);
	this->SetYear(year);
	this->SetDuration(duration);
}

Song::Song(const Song & song)
{
	CopyFrom(song);
}

Song & Song::operator=(const Song & song)
{
	if (this != &song)
	{
		Destroy();
		CopyFrom(song);
	}
	return *this;
}

void Song::SetTitle(const char * title)
{
	int l = strlen(title);
	this->title = new char[l + 1];
	strcpy_s(this->title, l + 1, title);
}

void Song::SetSinger(const char * singer)
{
	int l = strlen(singer);
	this->singer = new char[l + 1];
	strcpy_s(this->singer, l + 1, singer);
}

void Song::SetYear(int year)
{
	if (year >= 0)
	{
		this->year = year;
	}
	else
	{
		std::cout << "Year can not be negative" << std::endl;
	}
}

void Song::SetDuration(double duration)
{
	if (duration >= 0)
	{
		this->duration = duration;
	}
	else
	{
		std::cout << "Duration can not be negative" << std::endl;
	}
}

const char * Song::GetTitle() const
{
	return this->title;
}

char * Song::GetSinger() const
{
	return this->singer;
}

int Song::GetYear() const
{
	return this->year;
}

double Song::GetDuration() const
{
	return this->duration;
}

void Song::CopyFrom(const Song & song)
{
	this->SetTitle(song.GetTitle());
	this->SetDuration(song.GetDuration());
	this->SetYear(song.GetYear());
	this->SetSinger(song.GetSinger());
}

void Song::Destroy()
{
	delete[] this->singer;
	delete[] this->title;
}

Song::~Song()
{
	Destroy();
}

std::ostream & operator<<(std::ostream & os, const Song & song)
{
	os << "Title: " << song.GetTitle() << " singer: " << song.GetSinger() << " year: " << song.GetYear() << " duration: " << song.GetDuration() << std::endl;
	return os;
}