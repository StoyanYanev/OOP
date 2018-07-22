#include <iostream>

#include "BrowserHistory.h"

int main()
{
	int month, numberOfWebsites;
	int index = 0;
	char answer = 'y';

	HistoryEntry h(4, "www.google.com");
	HistoryEntry h1(5, "www.facebook.com");
	HistoryEntry h2(4, "www.youtube.com");
	HistoryEntry h3(7, "www.btv.com");
	HistoryEntry h4(1, "www.zamunda.com");

	BrowserHistory b(5);

	b.AddNewWebSite(h);
	b.AddNewWebSite(h1);
	b.AddNewWebSite(h2);
	b.AddNewWebSite(h3);
	b.AddNewWebSite(h4);

	std::cout << "Added webiste: " << std::endl;
	b.PrintAllWebsites();

	std::cout << "The most visited website by month is: " << b.FindMostVisitedWebsiteByMonth() << " month" << std::endl;

	std::cout << std::endl;
	std::cout << "Enter month to find the number of visited websites: ";
	std::cin >> month;
	std::cout << "The number of the websites visited in month " << month << " are: " << b.FindWebsiteByMonth(month) << std::endl; //print websites";
	std::cout << std::endl;

	std::cout << "Enter how many websitest you want to add: ";
	std::cin >> numberOfWebsites;
	BrowserHistory b1(numberOfWebsites);

	while (index < numberOfWebsites && answer == 'y')
	{
		b1.AddNewWebSite();
		index++;
		if (index < numberOfWebsites)
		{
			std::cout << "Do you want to add more websites ? y/n" << std::endl;
			std::cin >> answer;
			if (answer == 'n')
			{
				break;
			}
		}
	}
	std::cout << "Your entered websites are: " << std::endl;
	b1.PrintAllWebsites();
	std::cout << std::endl;

	BrowserHistory unionSites;
	unionSites = b + b1;
	std::cout << "The union webiste is:" << std::endl;
	unionSites.PrintAllWebsites();

	system("pause");
	return 0;
}