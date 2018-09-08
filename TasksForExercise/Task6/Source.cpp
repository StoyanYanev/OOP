#include<iostream>

#include"Album.h"

int main()
{
	Album favoriteSongs("Favorite Songs");

	Song firstSong("Time Won't Wait", "Filatov", 2016, 3.15);
	Song secondSong("So Far Away", "Martin Garrix", 2016, 4.15);
	Song thirdSong("Feel It Still", "Portugal", 2016, 3.45);
	Song forthSong("Time Won't Wait", "Filatov", 2016, 3.15);

	favoriteSongs.AddSong(firstSong);
	favoriteSongs.AddSong(secondSong);
	favoriteSongs.AddSong(thirdSong);
	favoriteSongs.AddSong(forthSong);

	std::cout << favoriteSongs << std::endl;
	favoriteSongs.DeleteDuplicates();
	std::cout << favoriteSongs << std::endl;

	Song findedSong = favoriteSongs.FindSong("So Far Away");
	Song findedNoExistentSong = favoriteSongs.FindSong("River");
	std::cout << findedSong << std::endl;
	std::cout << findedNoExistentSong << std::endl;

	int i = 0;
	char** artists = new char*[10];
	artists = favoriteSongs.GetArtist();
	while (artists[i] != '\0')
	{
		std::cout << artists[i] << std::endl;
		i++;
	}
	while (i - 1 >= 0)
	{
		delete[] artists[i - 1];
		i--;
	}

	std::cout << std::endl;
	std::cout << "Length of album: " << favoriteSongs.GetLength() << std::endl;
	std::cout << "Name of album: " << favoriteSongs.GetNameOfAlbum() << std::endl;

	return 0;
}