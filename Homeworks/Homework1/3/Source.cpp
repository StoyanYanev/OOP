#include <iostream>
#include <cstdlib>

#include "Store.h"
#include "Menu.h"

int main()
{
	while (true)
	{
		DisplayMenu();
		char letter;
		std::cin >> letter;
		std::cout << std::endl;
		GetInputFromMenu(letter);
	}

	system("pause");
	return 0;
}