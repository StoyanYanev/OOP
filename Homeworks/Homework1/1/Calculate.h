#pragma once

#include <iostream>
#include "Stack.h"

const int MAX_SIZE = 100;
const int LENGTH_OF_SIGNS = 5;
const int INDEX_OF_ARRAY = 0;
const char SIGNS[LENGTH_OF_SIGNS] = { '+', '-', '*', '/' ,'%' };
const int NUMBER_OF_ARGUMENTS = 2;

double Calculate(const char *expression);
bool CheckIsNumber(const char* num);
int Find(const char* expression, int startPosition, const char s); /* find the possition of the sign*/
char* SubStr(const char* expression, int position, int length);  /*get substring from expression*/
double ClalculateCurrentExpression(double firstNum, double secondNum, char sign);
void GetResult(const char* expression, char operation, Stack &s);

double Calculate(const char *expression)
{
	int lenOfExpression = strlen(expression);
	int lengthOfSubStr;
	int startIndex = 0;
	int length = 0;
	char* subStr;
	char operation;
	Stack s;

	while (length >= 0)
	{
		length = Find(expression, startIndex, ' '); /* find the possition of the sign*/
		if (length >= 0)
		{
			subStr = SubStr(expression, startIndex, length); /* get substring from expression*/
			lengthOfSubStr = strlen(subStr);
			startIndex = length + 1;
			if (lengthOfSubStr >= 2) /* if the length is bigger than 2 than the current substring is a number */
			{
				s.Push(atof(subStr)); /*atof convert char to double*/
			}
			else
			{
				if (CheckIsNumber(subStr) == true) /*if the length of the current substring is 1 check if it is a number */
				{
					s.Push(atof(subStr));
				}
				else
				{
					/* INDEX_OF_ARRAY = 0 */
					operation = subStr[INDEX_OF_ARRAY]; /* if it isn't a number then it is a operator */
					GetResult(expression, operation, s);
				}
			}
		}
		else
		{
			/* checks if in the end of the expression is operator */
			operation = expression[lenOfExpression - 1];
			GetResult(expression, operation, s);
			break;
		}
	}
	if (s.Size() == 0) 
		return s.Pop();
	else
	{
		/* if the size of the stack is bigger than 0 then the expression is invalide */
		std::cout << "Invalid expression!" << std::endl;
		return -1;
	}
}

bool CheckIsNumber(const char* num)
{
	for (int i = 0; i < LENGTH_OF_SIGNS; i++)
	{
		if (num[INDEX_OF_ARRAY] == SIGNS[i])
			return false;
	}
	return true;
}

double ClalculateCurrentExpression(double firstNum, double secondNum, char sign)
{
	double res;
	switch (sign)
	{
	case '+':
		res = secondNum + firstNum;
		break;
	case '-':
		res = secondNum - firstNum;
		break;
	case '*':
		res = secondNum * firstNum;
		break;
	case '/':
		if (firstNum != 0)
		{
			res = secondNum / firstNum;
			break;
		}
		std::cout << "Can't divide by zero!" << std::endl;
		res = -1;
		break;
	case '%':
		if (firstNum != int(firstNum) || secondNum != int(secondNum))
		{
			std::cout << "Invalide operation!" << std::endl;
			res = -1;
			break;
		}
		res = (int)secondNum % (int)firstNum;
		break;
	default:
		res = 0;
		std::cout << "Missing sign!" << std::endl;
		break;
	}
	return res;
}

/* find the possition of the sign */
int Find(const char* expression, int startPosition, const char s)
{
	int lengthOfEx = strlen(expression);
	if (startPosition < lengthOfEx)
	{
		for (int i = startPosition; i < lengthOfEx; i++)
		{
			if (expression[i] == s)
			{
				return i;
				break;
			}
		}
	}
	return -1;
}

/* get substring from expression */
char* SubStr(const char* expression, int position, int length)
{
	int lengthOfEx = strlen(expression);
	if (position < lengthOfEx && length < lengthOfEx)
	{
		int l = length - position;
		int index = 0;
		char *subStr = new char[l];
		for (int i = position; i < length; i++)
		{
			subStr[index] = expression[i];
			index++;
		}
		subStr[l] = '\0';
		return subStr;
	}
	else
	{
		std::cout << "Invalid parametars!" << std::endl;
	}

}

void GetResult(const char* expression, char operation, Stack &s)
{
	double result, firstNum, secondNum;

	if (s.Size() < NUMBER_OF_ARGUMENTS - 1)
	{
		std::cout << "Invalid expression!" << std::endl;
	}
	else
	{
		firstNum = s.Pop();
		secondNum = s.Pop();
		result = ClalculateCurrentExpression(firstNum, secondNum, operation);
		s.Push(result);
	}
}