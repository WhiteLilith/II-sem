#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Token {
public:
	virtual float GetNum() = 0;
	virtual char GetOper() = 0;
};
class Operator : public Token {
private:
	char oper;
public:
	Operator(char);
	char GetOper() override;
	float GetNum() override;
};
Operator::Operator(char c)
{
	oper = c;
}
char Operator::GetOper()
{
	return oper;
}
float Operator::GetNum()
{
	return NULL;
}
class Number : public Token {
private:
	float fnum;
public:
	Number(float);
	float GetNum() override;
	char GetOper() override;
};
Number::Number(float value)
{
	fnum = value;
}
float Number::GetNum()
{
	return fnum;
}
char Number::GetOper()
{
	return NULL;
}
class TokenStack
{
protected:
	Token **Values;
	int Size;
	int Top;
public:
	TokenStack() : Size(70)
	{
		Top = -1;
		Values = new Token*[Size];
	}
	TokenStack(int s) : Size(s)
	{
		Top = -1;
		Values = new Token*[Size];
	}
	void Push(Token* number)
	{
		Top++;
		Values[Top] = number;
	}
	Token* TopTop()
	{
		return Values[Top];
	}
	Token* Pop()
	{
		return Values[Top--];
	}
	bool IsEmpty()
	{
		if (Top == -1)
		{
			return true;
		}
		return false;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");

	TokenStack s;

	s.Push(new Number(15));
	s.Push(new Operator('/'));
	s.Push(new Number(1.5));

	while (!s.IsEmpty())
	{
		if (s.TopTop()->GetOper() == NULL)
		{
			cout << s.TopTop()->GetNum() << " ";
		}
		else
		{
			cout << s.TopTop()->GetOper() << " ";
		}
		s.Pop();
	}

	cout << endl;

	return 0;
}
