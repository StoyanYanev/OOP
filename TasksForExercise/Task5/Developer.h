#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee
{
public:
	Developer(std::string name, int period, double salary, bool knowledgeCPluse, bool knowledgeCSharp);
	Developer(const Developer& developer);
	bool GetKnowledgeCPlusPlus()const;
	bool GetKnowledgeCSharp()const;

	virtual Employee *Clone() override;
	virtual Type type() override;
	virtual void Print()const override;
	virtual ~Developer();
private:
	bool knowledgeCPlusPlus;
	bool knowledgeCSharp;
};
#endif