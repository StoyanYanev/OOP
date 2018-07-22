#pragma once

const int MAX_SIZE = 50;
char *sku = new char[MAX_SIZE];
Store s;

void DisplayMenu();
void GetInputFromMenu(char letter);

void DisplayMenu()
{
	std::cout << "A    " << "Add new product" << std::endl;
	std::cout << "X    " << "Delete product" << std::endl;
	std::cout << "C    " << "Change product" << std::endl;
	std::cout << "D    " << "Display products" << std::endl;
	std::cout << "Q    " << "Quit" << std::endl;
	std::cout << "Your choose is: ";
}

void GetInputFromMenu(char letter)
{
	Product p;
		switch (toupper(letter))
		{
		case'A':
			std::cin >> p;
			s.AddProduct(p);
			break;
		case'X':
			std::cout << "Enter SKU of the product you want to delete: ";
			std::cin>>sku;
			s.DeleteProduct(sku);
			break;
		case'C':
			std::cout << "Enter SKU of the product you want to change: ";
			std::cin >> sku;
			s.ChangeProductInStore(sku);
			break;
		case'D':
			s.DisplayProducts();
			break;
		case'Q':
			exit(0);
			break;
		default:
			std::cout << "Invalide input!";
			break;
		}
}