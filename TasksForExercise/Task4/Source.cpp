#include <iostream>
#include "Doctor.h"
#include "Patient.h"
int main()
{
	Doctor d("Pesho", "12.02.2017");

	Patient p1("Gosho", "02.04.2014", 5);
	Patient p2("misho", "08.01.2010", 4);
	Patient p3("lubo", "01.06.2016", 2);
	Patient p4("pepi", "01.01.2011", 7);

	d.AddPatient(p1);
	d.AddPatient(p2);
	d.AddPatient(p3);
	d.AddPatient(p4);
	std::cout << d.NumberOfPatients() << std::endl;
	d.Print();
	std::cout << d.AverageVisits()<<std::endl;
	std::cout <<  std::endl;
	d.FindPatient(5);
	std::cout << std::endl;
	d.DeletePatient("Gosho");
	std::cout << d.NumberOfPatients() << std::endl;
	d.Print();

	return 0;
}