#pragma once
#include <iostream>

#include"Song.h"

class Album
{
public:
	Album(const char* nameOfAlbum);
	Album(const Album&album);
	Album &operator=(const Album&album);
	void SetNameOfAlbum(const char*name);
	const char*GetNameOfAlbum()const;
	void AddSong(const Song&song);
	double GetLength()const;
	char** GetArtist();
	Song FindSong(const char* title)const;
	void DeleteDuplicates();
	friend std::ostream&operator<<(std::ostream&os, const Album&album);
	~Album();
private:
	void CopyFrom(const Album&album);
	void Destroy();
	void Resize();
	bool IsAnotherArtist()const;
	void SortAlbum();

	enum { SIZE = 50 };
	char* nameOfAlbum;
	Song* songs;
	int maxSize;
	int currentElements;
};