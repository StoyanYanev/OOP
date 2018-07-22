#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
	Product(); // constructor without parameters
    // constructor with parameters
	Product(const char * SKU, const char * brand, const char * model, int size, const char * color, double price, int count);
	char * GetSKU()const;
	char * GetBrand()const;
	char* GetModel()const;
	int GetSize()const;
	char* GetColor()const;
	double GetPrice()const;
	int GetCount()const;
	void SetSKU(const char *SKU);
	void SetBrand(const char *brand);
	void SetModel(const char * model);
	void SetSize(int size);
	void SetColor(const char * color);
	void SetPrice(double price);
	void SetCount(int count);
	void ChangeProduct();
	friend std::istream & operator >>(std::istream &is, Product &p);
	friend std::ostream & operator <<(std::ostream &os, const Product &p);
private:

	//member-data for T-shirt
	enum { DEFAULT_SIZE = 50 }; //defaut size of the m_SKU, m_brand, m_model, m_color
	char *m_SKU; // stock keeping unit
	char *m_brand;
	char* m_model;
	int m_size;
	char* m_color;
	double m_price;
	int m_count;
};
#endif