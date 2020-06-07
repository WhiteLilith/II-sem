#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


class Money
{

private:
	long double money;
	const char dollarChar = '$';
	string digits = "0123456789";

public:
	Money() : money(0)
	{}

	Money(string money) : money(0)
	{
		GetValue(money);
	}

	void GetValue(string val)
	{
		string numbers;
		for (auto c : val)
		{
			if (digits.find(c) != string::npos)
			{
				numbers += c;
			}
		}

		char* numbersCh = new char[numbers.length() + 1];
		strncpy_s(numbersCh, numbers.length()+1, numbers.c_str(), numbers.length());
		money = atof(numbersCh);
		money /= 100;
	}

	void ShowValue()
	{
		cout << dollarChar << " " << money;
	}

};



int main()
{
	setlocale(LC_ALL, "Russian");

	string userResponce;
	Money dollars;
	cout << "Введите сумму в долларах: ";
	cin >> userResponce;
	dollars.GetValue(userResponce);
	dollars.ShowValue();
}
