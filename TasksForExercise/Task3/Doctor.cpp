#include "Doctor.h"

Doctor::Doctor() :Person()
{
	this->maxPatient = MAX_PATIENT;
	this->p = new Patient[this->maxPatient];
	this->numberOfPatient = 0;
}

Doctor::Doctor(const char * name, Date d, int reg) : Person(name, d)
{
	this->maxPatient = reg;
	this->p = new Patient[this->maxPatient];
	this->numberOfPatient = 0;
}

Doctor::Doctor(const Doctor & d) :Person(d)
{
	CopyFrom(d);
}

Doctor Doctor::operator=(const Doctor & d)
{
	if (this != &d)
	{
		Person::operator=(d);
		Destroy();
		CopyFrom(d);
	}
	return *this;
}

void Doctor::AddPatient(const Patient & p)
{
	if (this->numberOfPatient >= this->maxPatient)
	{
		Resize();
	}
	this->p[this->numberOfPatient] = p;
	this->numberOfPatient++;
}

void Doctor::DeletePatient(const char * name)
{
	Patient * newP = new Patient[this->numberOfPatient - 1];
	int newInd = 0;
	for (int i = 0; i < this->numberOfPatient; i++)
	{
		if (strcmp(this->p[i].GetName(), name) != 0)
		{
			newP[newInd].SetDate(this->p[i].GetDate());
			newP[newInd].SetName(this->p[i].GetName());
			newP[newInd].SetVisit(this->p[i].GetVisit());
			newInd++;
		}
	}
	delete[]this->p;
	this->p = newP;
	this->numberOfPatient--;
}

double Doctor::Average() const
{
	double avg = 0;
	for (int i = 0; i < this->numberOfPatient; i++)
	{
		avg += this->p[i].GetVisit();
	}
	return avg / this->numberOfPatient;
}

void Doctor::PrintUpper(int visit) const
{
	for (int i = 0; i < this->numberOfPatient; i++)
	{
		if (this->p[i].GetVisit() > visit)
		{
			std::cout << this->p[i];
		}
	}
}

Doctor::~Doctor()
{
	Destroy();
}

void Doctor::CopyFrom(const Doctor & d)
{
	this->maxPatient = d.maxPatient;
	this->numberOfPatient = d.numberOfPatient;
	this->p = new Patient[this->maxPatient];
	for (int i = 0; i < this->numberOfPatient; i++)
	{
		p[i].SetDate(d.p[i].GetDate());
		p[i].SetName(d.p[i].GetName());
		p[i].SetVisit(d.p[i].GetVisit());
	}
}

void Doctor::Destroy()
{
	delete[]this->p;
}

void Doctor::Resize()
{
	Patient * newP = new Patient[this->maxPatient * 2];
	for (int i = 0; i < this->numberOfPatient; i++)
	{
		newP[i].SetDate(this->p[i].GetDate());
		newP[i].SetName(this->p[i].GetName());
		newP[i].SetVisit(this->p[i].GetVisit());
	}
	delete[]this->p;
	this->p = newP;
	this->maxPatient *= 2;
}

std::ostream & operator<<(std::ostream & os, const Doctor & d)
{
	for (int i = 0; i < d.numberOfPatient; i++)
	{
		os << d.p[i].GetName() << d.p[i].GetDate() << d.p[i].GetVisit()<<std::endl;
	}
	return os;
}
