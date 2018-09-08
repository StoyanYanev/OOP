#include<iostream>

#include "Sum.h"
#include "Const.h"
#include "Product.h"
#include"Var.h"

int main()
{
	Expression* firstExp = new Const(5);
	Expression* secondExp = new Var("var", 10);

	Sum sum(firstExp, secondExp);
	Product product(firstExp, secondExp);
	
	sum.Print();
	std::cout << " = " << sum.Value() << std::endl;

	product.Print();
	std::cout << " = " << product.Value() << std::endl;

	Expression* thirdExp = new Sum(firstExp, secondExp);
	Expression* fourthExp = new Product(firstExp, secondExp);

	Sum s(thirdExp, fourthExp);
	s.Print();
	std::cout << " = " << s.Value() << std::endl;

	Product p(thirdExp, fourthExp);
	p.Print();
	std::cout << " = " << p.Value() << std::endl;

	return 0;
}