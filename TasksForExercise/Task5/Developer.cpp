#include "Developer.h"

Developer::Developer(std::string name, int period, double salary, bool knowledgeCPlusPlus, bool knowledgeCSharp) :Employee(name, period, salary)
{
	this->knowledgeCPlusPlus = knowledgeCPlusPlus;
	this->knowledgeCSharp = knowledgeCSharp;
}

Developer::Developer(const Developer & developer)
{
	this->SetName(developer.GetName());
	this->SetPeriod(developer.GetPeriod());
	this->SetSalary(developer.GetSalary());
	this->knowledgeCPlusPlus = developer.GetKnowledgeCPlusPlus();
	this->knowledgeCSharp = developer.GetKnowledgeCSharp();
}

bool Developer::GetKnowledgeCPlusPlus() const
{
	return this->knowledgeCPlusPlus;
}

bool Developer::GetKnowledgeCSharp() const
{
	return this->knowledgeCSharp;
}

Employee * Developer::Clone()
{
	return new Developer(*this);
}

Type Developer::type()
{
	return DEVELOPER;
}

void Developer::Print() const
{
	Employee::Print();
	std::cout << " knowledge CPlusPlus: " << this->GetKnowledgeCPlusPlus() << " knowledge CSharp: " <<
		this->GetKnowledgeCSharp() << std::endl;
}

Developer::~Developer()
{
}