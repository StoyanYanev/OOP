#include <iostream>

#include "CentralBank.h"
#include "ConcreteObserver.h"
#include "Currency.h"

int main()
{
	Currency l("leva", 1);
	Currency e("euro", 2);
	Currency u("uk", 3);

	CentralBank bank("DSK", l);

	bank.AddCurrency(e);
	bank.AddCurrency(u);
	bank.PrintCurrency();
	std::cout <<"*******************************" <<std::endl;
	std::cout << "Delete the currency uk!" << std::endl;
	std::cout << std::endl;
	bank.DeleteCurrency("uk");
	bank.PrintCurrency();
	std::cout << "*******************************" <<std::endl;

	Observer* firstObserver = new ConcreteObserver("OBB");
	Observer* secondObserver = new ConcreteObserver("Pireus");
	bank.Register(firstObserver);
	bank.Register(secondObserver);

	bank.PrintObservers();

	std::cout << "*******************************" << std::endl;
	std::cout << "Change the rate of the euro!" << std::endl;
	bank.SetRate("euro", 3);
	std::cout << "*******************************" <<std::endl;

	std::cout << "Unregister OBB!" << std::endl;
	std::cout << std::endl;
	bank.Unregister("OBB");

	bank.PrintObservers();

	std::cout << "*******************************" <<std::endl;
	std::cout << "Change the rate of the leva!" << std::endl;
	bank.SetRate("leva", 5);
	std::cout << std::endl;

	return 0;
}