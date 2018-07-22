#include<iostream>

#include "Store.h"

Store::Store()
{
	/*set defaut size of the store*/
	m_size = SIZE_OF_PRODUCTS;
	m_products = new Product[m_size];
	m_numberOfProducts = 0;
}

Store::Store(const Store & s)
{
	CopyFrom(s);
}

Store Store::operator=(const Store & s)
{
	if (this != &s)
	{
		Destroy();
		CopyFrom(s);
	}
	return *this;
}

void Store::AddProduct(Product product)
{
	if (IsFull() == true)
	{
		Resize(); /* if in the store don't have memory resize it. */
	}
	m_products[m_numberOfProducts] = product;
	m_numberOfProducts++;
}

void Store::DeleteProduct(char * SKU)
{
	if (IsEmpty() == false)
	{
		m_numberOfProducts--;
		Product  *p = new Product[m_numberOfProducts]; /* array with products with length = m_numberOfProducts - 1*/
		int index = 0;
		for (int i = 0; i <= m_numberOfProducts; i++)
		{
			if (strcmp(m_products[i].GetSKU(), SKU) != 0) /*compare char* - if they are equal don't add in the store*/
			{
				p[index] = m_products[i];
				index++;
			}
		}
		Destroy();
		m_products = p;
	}
	else
	{
		std::cout << "The store is empty. You Can't delete any products!" << std::endl;
	}
}

void Store::ChangeProductInStore(const char * SKU)
{
	bool isFindProduct = false;
	if (IsEmpty() == false)
	{
		for (int i = 0; i < m_numberOfProducts; i++)
		{
			if (strcmp(m_products[i].GetSKU(), SKU) == 0) /*search for product, when we find it - change*/
			{
				isFindProduct = true;
				m_products[i].ChangeProduct();
				break;
			}
		}
		if (isFindProduct == false)
		{
			std::cout << "In the store don't have product by this SKU!" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "The product is change success!" << std::endl;
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "The store is empty!" << std::endl;
	}
}

void Store::DisplayProducts() const
{
	if (IsEmpty() == false)
	{
		for (int i = 0; i < m_numberOfProducts; i++)
		{
			std::cout << m_products[i];
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "The store is empty!" << std::endl;
	}
}

Store::~Store()
{
	Destroy();
}

void Store::Destroy()
{
	delete[] m_products;
}

void Store::CopyFrom(const Store &s)
{
	m_size = s.m_size;
	m_numberOfProducts = s.m_numberOfProducts;
	m_products = new Product[m_size];
	for (int i = 0; i < m_numberOfProducts; i++)
	{
		m_products[i].SetSKU(s.m_products[i].GetSKU());
		m_products[i].SetBrand(s.m_products[i].GetBrand());
		m_products[i].SetModel(s.m_products[i].GetModel());
		m_products[i].SetSize(s.m_products[i].GetSize());
		m_products[i].SetColor(s.m_products[i].GetColor());
		m_products[i].SetPrice(s.m_products[i].GetPrice());
		m_products[i].SetCount(s.m_products[i].GetCount());
	}
}

void Store::Resize()
{
	Product *newProducts = new Product[2 * m_size]; /*array with products with length = 2 * m_size*/
	for (int i = 0; i < m_size; i++)
	{
		/*set all products in new array*/
		newProducts[i].SetSKU(m_products[i].GetSKU());
		newProducts[i].SetBrand(m_products[i].GetBrand());
		newProducts[i].SetModel(m_products[i].GetModel());
		newProducts[i].SetSize(m_products[i].GetSize());
		newProducts[i].SetColor(m_products[i].GetColor());
		newProducts[i].SetPrice(m_products[i].GetPrice());
		newProducts[i].SetCount(m_products[i].GetCount());
	}
	Destroy();
	m_products = newProducts;
	m_size *= 2;
}

bool Store::IsFull()const
{
	if (m_numberOfProducts < m_size)
	{
		return false;
	}
	return true;
}

bool Store::IsEmpty()const
{
	if (m_numberOfProducts - 1 >= 0)
	{
		return false;
	}
	return true;
}