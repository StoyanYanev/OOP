#include <iostream>
#include <ctype.h>

#include "Stack.h"
#include "Calculate.h"


int main()
{
	char polishNotation[MAX_SIZE];
	std::cout << "Enter expression in reverse polish notation: " << std::endl;
	std::cin.get(polishNotation, MAX_SIZE);

	std::cout << "Result: " << Calculate(polishNotation) << std::endl;

	system("pause");
	return 0;
}