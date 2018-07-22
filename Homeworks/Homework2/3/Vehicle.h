#ifndef Vehicle_H
#define Vehicle_H

class Vehicle // abstract base class
{
public:
	Vehicle();
	Vehicle(const char *brand, const char* model, const char* color, int year, double mileage);
	Vehicle(const Vehicle& v);
	Vehicle& operator=(const Vehicle& v);
	const char* GetBrand()const;
	const char* GetModel()const;
	const char* GetColor()const;
	int GetYear()const;
	double GetMileage()const;
	void SetBrand(const char *brand);
	void SetModel(const char * model);
	void SetColor(const char * color);
	void SetYear(int year);
	void SetMileage(double mileage);

	virtual void Details()const = 0; // pure virtual function

	~Vehicle();
private:
	void CopyFrom(const Vehicle& v);
	void Destroy();

	char* m_brand;
	char* m_model;
	char* m_color;
	int m_year;
	double m_mileage;
};
#endif