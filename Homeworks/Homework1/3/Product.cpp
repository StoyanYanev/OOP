#include <iostream>

#include "Product.h"

Product::Product()
{
	this->SetSKU("");
	this->SetBrand("");
	this->SetModel("");
	this->SetColor("");
	this->SetSize(0);
	this->SetPrice(0.0);
	this->SetCount(0);
}

Product::Product(const char * SKU, const char * brand, const char * model, int size, const char * color, double price, int count)
{
	this->SetSKU(SKU);
	this->SetBrand(brand);
	this->SetModel(model);
	this->SetSize(size);
	this->SetColor(color);
	this->SetPrice(price);
	this->SetCount(count);
}

char * Product::GetSKU()const
{
	return m_SKU;
}

char * Product::GetBrand()const
{
	return m_brand;;
}

char *  Product::GetModel() const
{
	return m_model;
}

int  Product::GetSize() const
{
	return m_size;
}

char *  Product::GetColor() const
{
	return m_color;
}


double Product::GetPrice()const
{
	return  m_price;;
}

int Product::GetCount() const
{
	return m_count;
}

void Product::SetSKU(const char *SKU)
{
	int l = strlen(SKU);
	m_SKU = new char[l + 1];
	strcpy_s(m_SKU, l + 1, SKU);
}

void Product::SetBrand(const char * brand)
{
	int l = strlen(brand);
	m_brand = new char[l + 1];
	strcpy_s(m_brand, l + 1, brand);
}

void Product::SetModel(const char * model)
{
	int l = strlen(model);
	m_model = new char[l + 1];
	strcpy_s(m_model, l + 1, model);
}

void Product::SetSize(int size)
{
	m_size = size;
}

void Product::SetColor(const char * color)
{
	int l = strlen(color);
	m_color = new char[l + 1];
	strcpy_s(m_color, l + 1, color);
}

void Product::SetPrice(double price)
{
	if (price < 0)
	{
		std::cout << "Invalide price!" << std::endl;
		return;
	}
	m_price = price;
}

void Product::SetCount(int count)
{
	if (count >= 0)
	{
		m_count = count;
	}
	else
	{
		std::cout << "Invalide count!" << std::endl;
		return;
	}
}

void Product::ChangeProduct()
{
	char* sku = new char[DEFAULT_SIZE];
	char* brand = new char[DEFAULT_SIZE];
	char* model = new char[DEFAULT_SIZE];
	char* color = new char[DEFAULT_SIZE];
	int size, count;
	double price;

	std::cout << "Enter new products: " << std::endl;

	std::cout << "Enter SKU: ";
	std::cin >> sku;
	this->SetSKU(sku);

	std::cout << "Enter brand: ";
	std::cin >> brand;
	this->SetBrand(brand);

	std::cout << "Enter model: ";
	std::cin >> model;
	this->SetModel(model);

	std::cout << "Enter size: ";
	std::cin >> size;
	this->SetSize(size);

	std::cout << "Enter color: ";
	std::cin >> color;
	this->SetColor(color);

	std::cout << "Enter price: ";
	std::cin >> price;
	this->SetPrice(price);

	std::cout << "Enter count: ";
	std::cin >> count;
	this->SetCount(count);
}

std::istream & operator>>(std::istream & is, Product & p)
{
	std::cout << "Enter SKU: ";
	is >> p.m_SKU;
	std::cout << "Enter brand: ";
	is >> p.m_brand;
	std::cout << "Enter model: ";
	is >> p.m_model;
	std::cout << "Enter size: ";
	is >> p.m_size;
	std::cout << "Enter color: ";
	is >> p.m_color;
	std::cout << "Enter price: ";
	is >> p.m_price;
	std::cout << "Enter count: ";
	is >> p.m_count;

	return is;
}
std::ostream & operator<<(std::ostream & os, const Product & p)
{
	os << "SKU: " << p.GetSKU() << "\nBrand: " << p.GetBrand() << "\nModel: " << p.GetModel()
		<< "\nSize: " << p.GetSize() << "\nColor: " << p.GetColor() << "\nPrice: " << p.GetPrice() <<
		"\nNumber of products: " << p.GetCount() << "\n";

	return os;
}