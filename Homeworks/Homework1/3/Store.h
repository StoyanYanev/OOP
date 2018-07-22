#ifndef STORE_H
#define STORE_H

#include "Product.h"

class Store
{
public:
	Store();
	Store(const Store &s);
	Store operator=(const Store &s);
	void AddProduct(Product product);
	void DeleteProduct(char *SKU);
	void ChangeProductInStore(const char *SKU);
	void DisplayProducts() const;
	~Store();
private:
	void Destroy();
	void CopyFrom(const Store &s);
	void Resize(); /* if the memory of the store is smaller than it gets bigger*/
	bool IsFull() const; /* check if the store have a memory*/
	bool IsEmpty() const; /* check if the store is empty*/

	enum { SIZE_OF_PRODUCTS = 50 }; /*defaut size of the store*/
	Product * m_products;
	int m_size;
	int m_numberOfProducts;
};
#endif