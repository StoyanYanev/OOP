#include <iostream>
#include <cstdlib>
#include <vector>

#include "Bank.h"
#include "CurrentAccount.h"
#include"SavingsAccount.h"
#include"PrivilegeAccount.h"
#include "Menu.h"

int main()
{
	while (true)
	{
		DisplayMenu();
		int digit;
		std::cin >> digit;
		std::cout << std::endl;
		GetInputFromMenu(digit);
	}

	return 0;
}