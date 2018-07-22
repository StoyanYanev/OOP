#ifndef STACK_H
#define STACK_H

class Stack
{
public:
	Stack();
	Stack& operator=(const Stack  &s);
	Stack(const Stack &s);
	void Push(double elem);
	double Pop();
	double Peek() const;
	int Size() const;
	bool IsEmpty() const;
	~Stack();
private:
	bool IsFull() const;
	void ResizeStack();
	void CopyFrom(const Stack &s);
	void Destroy();

	enum { STACK_SIZE = 50 }; /*defaut size of the stack*/
	double* m_arr;
	int m_top; /* number of the elements in the stack*/
	int m_size; /*size of the stack*/
};
#endif