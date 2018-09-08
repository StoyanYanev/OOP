#include "Album.h"

Album::Album(const char * nameOfAlbum)
{
	this->SetNameOfAlbum(nameOfAlbum);
	this->maxSize = SIZE;
	this->songs = new Song[this->maxSize];
	this->currentElements = 0;
}

Album::Album(const Album & album)
{
	CopyFrom(album);
}

Album & Album::operator=(const Album & album)
{
	if (this != &album)
	{
		Destroy();
		CopyFrom(album);
	}
	return*this;
}

void Album::SetNameOfAlbum(const char * name)
{
	int l = strlen(name);
	this->nameOfAlbum = new char[l + 1];
	strcpy_s(this->nameOfAlbum, l + 1, name);
}

const char * Album::GetNameOfAlbum() const
{
	return this->nameOfAlbum;
}

void Album::AddSong(const Song & song)
{
	if (this->currentElements + 1 > maxSize)
	{
		Resize();
	}
	this->songs[this->currentElements] = song;
	this->currentElements++;
}

double Album::GetLength() const
{
	double len = 0;
	for (int i = 0; i < this->currentElements; i++)
	{
		len += this->songs[i].GetDuration();
	}
	return len;
}

char** Album::GetArtist()
{
	int i = 0;
	int j = 0;
	int l;
	char** artists = new char*[this->currentElements];
	
	if (IsAnotherArtist() == true)
	{
		DeleteDuplicates();

		for (i; i < this->currentElements; i++)
		{
			l = strlen(this->songs[i].GetSinger()) + 1;
			artists[i] = new char[l];
			strcpy_s(artists[i], l, this->songs[i].GetSinger());
		}
	}
	else
	{
		l = strlen(this->songs[i].GetSinger()) + 1;
		artists[i] = new char[l];
		strcpy_s(artists[i], l, this->songs[0].GetSinger());
		i++;
	}
	artists[i] = 0;

	return artists;
}

Song Album::FindSong(const char * title) const
{
	for (int i = 0; i < this->currentElements; i++)
	{
		if (strcmp(this->songs[i].GetTitle(), title) == 0)
		{
			return this->songs[i];
			break;
		}
	}
	return Song(); // return empty song
}

void Album::DeleteDuplicates()
{
	bool isDublicate = false;
	Song* newSong = new Song[this->maxSize];
	int index = 0;
	SortAlbum();
	for (int i = 0; i <= this->currentElements - 1; i++)
	{
		if (strcmp(this->songs[i].GetTitle(), this->songs[i + 1].GetTitle()) != 0)
		{
			newSong[index] = this->songs[i];
			index++;
		}
	}
	delete[]this->songs;

	this->songs = newSong;
	this->currentElements = index;
}

std::ostream & operator<<(std::ostream & os, const Album & album)
{
	for (int i = 0; i < album.currentElements; i++)
	{
		os << album.songs[i];
	}
	return os;
}

void Album::CopyFrom(const Album & album)
{
	this->SetNameOfAlbum(album.GetNameOfAlbum());
	this->maxSize = album.maxSize;
	this->currentElements = album.currentElements;
	this->songs = new Song[this->maxSize];
	for (int i = 0; i < this->currentElements; i++)
	{
		this->songs[i] = album.songs[i];
	}
}

void Album::Destroy()
{
	delete[]this->nameOfAlbum;
	delete[]this->songs;
}

void Album::Resize()
{
	Song *newSongs = new Song[this->maxSize * 2];
	this->maxSize *= 2;
	for (int i = 0; i < this->currentElements; i++)
	{
		newSongs[i] = this->songs[i];
	}
	delete[] this->songs;
	this->songs = newSongs;
	delete[] newSongs;
}

bool Album::IsAnotherArtist() const
{
	for (int i = 0; i < this->currentElements; i++)
	{
		for (int j = i + 1; j <= this->currentElements - 1; j++)
		{
			if (strcmp(this->songs[i].GetSinger(), this->songs[j].GetSinger()) != 0)
			{
				return true;
				break;
			}
		}
	}
	return false;
}

void Album::SortAlbum()
{
	Song newSong;
	for (int i = 0; i < this->currentElements - 1; i++)
	{
		for (int j = i + 1; j <= this->currentElements - i - 1; j++)
		{
			if (strcmp(this->songs[i].GetSinger(), this->songs[j].GetSinger()) == 0)
			{
				newSong = this->songs[j];
				this->songs[j] = this->songs[i + 1];
				this->songs[i + 1] = newSong;
			}
		}
	}
}

Album::~Album()
{
	Destroy();
}