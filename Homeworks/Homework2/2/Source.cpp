#include <iostream>

#include "Settings.h"

int main()
{
	std::cout << std::endl;
	std::cout << "***************************Setting with int***************************" << std::endl;
	Settings<int> settingsInt;
	settingsInt.Set("1111", 8);
	settingsInt.Set("123", 5);
	settingsInt.Print();
	std::cout << std::endl;

	std::cout << "Number of elements: " << settingsInt.Count() << std::endl;
	std::cout << std::endl;

	std::cout << "Change value of element: " << std::endl;
	settingsInt.Set("123", 4);
	settingsInt.Print();
	std::cout << std::endl;

	int val = 0;  // save value
	std::cout << "Is there an such object with key: " << "173? " << settingsInt.Get("173", val) << std::endl;
	std::cout << "It value is: " << val << std::endl;

	int val1 = 0; // save value
	std::cout << "Is there an such object with key: " << "123? " << settingsInt.Get("123", val1) << std::endl;
	std::cout << "It value is: " << val1 << std::endl;
	std::cout << std::endl;

	std::cout << "***************************Setting with char***************************" << std::endl;
	Settings<char> settingsChar;
	settingsChar.Set("541", '8');
	settingsChar.Set("111", '2');
	settingsChar.Print();
	std::cout << std::endl;

	std::cout << "Change value of element: " << std::endl;
	settingsChar.Set("111", '9');
	settingsChar.Print();
	std::cout << std::endl;

	char v = '0'; 
	std::cout << "Is there an such object with key: " << "111? " << settingsChar.Get("111", v) << std::endl;
	std::cout << "It value is: " << v << std::endl;
	std::cout << std::endl;

	return 0;
}