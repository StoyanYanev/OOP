#include <iostream>

#include "ElectricNet.h"

int main()
{
	ElectricNet firstElNet(100);

	ElectricDevice p("oven", 50);
	ElectricDevice l("laptop", 20);
	ElectricDevice per("washing machine", 70);
	ElectricDevice h("fridge", 60);

	// add new device
	firstElNet += p; 
	firstElNet += l;
	firstElNet.PrintDevices();
	std::cout << std::endl;

	firstElNet += per;	// try to add new device
	++firstElNet;	   // increment power of electric net and add new device
	firstElNet += h;
	firstElNet.PrintDevices();
	--firstElNet;	 // decrement power of electric net
	std::cout << std::endl;

	std::cout << "If there are any devices plugged into the network? " << !firstElNet << std::endl;
	std::cout << std::endl;

	firstElNet -= "oven";	   // remove device from electric net
	firstElNet.PrintDevices();
	std::cout << std::endl;

	std::cout << firstElNet["1"] << std::endl;  // try to get device by name 1
	std::cout << std::endl;

	std::cout << firstElNet["laptop"] << std::endl; // get device by name laptop
	std::cout <<"__________________________________________________"<< std::endl;

	ElectricNet secondElNet(70);

	secondElNet = firstElNet - "fridge"; // remove device 'fridge' from 'firstElNet' and save new object in 'secondElNet'
	secondElNet.PrintDevices();
	std::cout << std::endl;

	return 0;
}