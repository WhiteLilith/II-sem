#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

class Money
{

private:
	long double money;
	string moneyStr;
	string numbersStr;
	string digits = "0123456789";

	void FormateMoneyStr()
	{
		size_t moneyStrLength = moneyStr.length();
		for (size_t i = moneyStrLength - 1; i > 0; i--)
		{
			if (moneyStrLength - i == 2 && moneyStr[i] != '.')
			{
				moneyStr.insert(i, ".");
			}

			if ((moneyStrLength - i + 1) % 3 == 0 && moneyStrLength - i != 3 && moneyStr[i] != '.')
			{
				moneyStr.insert(i, ".");
			}
		}

		moneyStr.insert(0, "$");
	}

public:

	Money() : money(0)
	{}

	Money(string money) : money(0)
	{
		SetValue(money);
	}

	void SetValue(string val)
	{
		string numbers;
		for (auto c : val)
		{
			if (digits.find(c) != string::npos)
			{
				numbers += c;
			}
		}
		numbersStr = moneyStr = numbers;
		FormateMoneyStr();
		char* numbersCh = new char[numbers.length() + 1];
		strncpy_s(numbersCh, numbers.length()+1, numbers.c_str(), numbers.length());
		money = atof(numbersCh);
		money /= 10;
	}

	double GetValueD() const
	{
		return money;
	}

	string GetValueS()
	{
		return moneyStr;
	}

	Money operator + (Money m)
	{
		double newMoney = money + m.money;
		string newMoneyStr = to_string(newMoney);
		return Money(newMoneyStr.substr(0, newMoneyStr.find(",") + 3));
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
  
	string userResponce;
	Money dollars_1, dollars_2, dollars_3;
	cout << "Введите сумму в долларах: ";
	cin >> userResponce;
	dollars_1.SetValue(userResponce);
	cout << "Введите другую сумму в долларах: ";
	cin >> userResponce;
	dollars_2.SetValue(userResponce);
	dollars_3 = dollars_1 + dollars_2;
	cout << "Итого получилось: " << dollars_3.GetValueS();
}
