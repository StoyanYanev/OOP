#include <iostream>

#include "Stack.h"

Stack::Stack()
{
	/*set defaut size of the stack*/
	m_size = STACK_SIZE;
	m_arr = new double[m_size];
	m_top = -1;
}

Stack & Stack::operator=(Stack const &s)
{
	if (this != &s)
	{
		Destroy();
		CopyFrom(s);
	}
	return *this;
}

Stack::Stack(const Stack & s)
{
	CopyFrom(s);
}

void Stack::Push(double elem) /* put element in the top of the stack*/
{
	if (IsFull() == true)
	{
		ResizeStack();
	}
	m_top++;
	m_arr[m_top] = elem;
}

double Stack::Pop() /* return and delete last added element in the stack*/
{
	if (IsEmpty() == true)
	{
		std::cout << "The stack is empty!" << std::endl;
		return -1;
	}
	double currentElem = m_arr[m_top];
	m_top--;
	return currentElem;
}

double Stack::Peek() const /* return last added element in the stack*/
{
	if (IsEmpty() == true)
	{
		std::cout << "The stack is empty!" << std::endl;
		return -1;
	}
	return m_arr[m_top];
}

int Stack::Size() const
{
	return m_top;
}

bool Stack::IsEmpty() const
{
	if (Size() >= 0)
	{
		return false;
	}
	return true;
}

bool Stack::IsFull() const
{
	if (m_top == m_size - 1)
	{
		return true;
	}
	return false;
}

void Stack::ResizeStack()
{
	double* newArr = new double[2 * m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		newArr[i] = m_arr[i];
	}
	Destroy();
	m_arr = newArr;
	m_size *= 2;
}

void Stack::CopyFrom(const Stack & s)
{
	m_size = s.m_size;
	m_top = s.m_top;
	m_arr = new double[m_size];
	for (int i = 0; i < m_top; i++)
	{
		m_arr[i] = s.m_arr[i];
	}
}

void Stack::Destroy()
{
	delete[] m_arr;
}

Stack::~Stack()
{
	Destroy();
}