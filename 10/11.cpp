#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int len = 80;

class Token
{
public:
	virtual float GetNum() = 0;
	virtual char GetOper() = 0;
};

class Operator : public Token
{
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

class Stack
{
protected:
	Token** Values;
	int Size;
	int Top;

public:
	Stack() : Size(70)
	{
		Top = 0;
		Values = new Token *[Size];
	}

	Stack(int s) : Size(s)
	{
		Top = 0;
		Values = new Token *[Size];
	}

	void Push(Token* element)
	{
		Values[++Top] = element;
	}

	int GetTop()
	{
		return Top;
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

class express                 
{
private:
	Stack s;                 
	char* pStr;                   
	int len;                     

public:
	express(char* ptr)        
	{
		pStr = ptr;            

		len = strlen(pStr);     
	}

	void parse();        
	float solve();                 
};

void express::parse()          
{
	char ch;                
	float lastval;                   
	char lastop;                 

	for (int j = 0; j < len;)       
	{
		ch = pStr[j];                

		if (ch >= '0' && ch <= '9')        
		{
			char* charNumber = new char[40];
			int i = 1;
			while ((pStr[j] >= '0' && pStr[j] <= '39') || pStr[j] == '.')
			{
				*(charNumber + i - 1) = pStr[j];
				i++;
				j++;
			}

			float currentNumber = atof(charNumber);
			s.Push(new Number(currentNumber));
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
		{
			if (s.GetTop() == 1)         
			{
				s.Push(new Operator(ch));        
			}
			else                  
			{
				lastval = s.Pop()->GetNum();      

				lastop = s.Pop()->GetOper();        
												

				if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
				{
					s.Push(new Operator(lastop));    

					s.Push(new Number(lastval));
				}
				else                   
				{
					switch (lastop)  
					{                  
					case '+': 
						s.Push(new Number(s.Pop()->GetNum() + lastval));
						break;
					case '-': 
						s.Push(new Number(s.Pop()->GetNum() - lastval));
						break;
					case '*': 
						s.Push(new Number(s.Pop()->GetNum() * lastval));
						break;
					case '/': 
						s.Push(new Number(s.Pop()->GetNum() / lastval));
						break;
					default:  
						cout << "\nUnknown oper";
						exit(1);
					}  
				}  
				s.Push(new Operator(ch));         
			} 
			j++;
		} 
		else                         
		{
			cout << "\nUnknown input character";
			exit(1);
		}
	} 
} 

float express::solve()         
{
	float lastval;                  

	while (s.GetTop() > 1)
	{
		lastval = s.Pop()->GetNum();             

		switch (s.Pop()->GetOper())         
		{                          
		case '+': 
			s.Push(new Number(s.Pop()->GetNum() + lastval));
			break;
		case '-': 
			s.Push(new Number(s.Pop()->GetNum() - lastval));
			break;
		case '*': 
			s.Push(new Number(s.Pop()->GetNum() * lastval));
			break;
		case '/': 
			s.Push(new Number(s.Pop()->GetNum() / lastval));
			break;
		default:  
			cout << "\nUnknown operator"; 
			exit(1);
		}  
	}  
	return float(s.Pop()->GetNum());            

}  

int main()
{
	char ans;                   
	char string[len];  

	cout << "\nEnter an arithmetic expression"
		"\nof the form 2+3*4/3-2."
		"\nNo number may have more than one digit."
		"\nDon't use any spaces or parentheses.";

	do
	{
		cout << "\nEnter expresssion: ";
		cin >> string;                   
		express* eptr = new express(string); 
		eptr->parse();                       
		cout << "\nThe numerical value is: " << eptr->solve();             
		delete eptr;                         
		cout << "\nDo another (Enter y or n)? ";
		cin >> ans;
	} while (ans == 'y');

	return 0;
}
