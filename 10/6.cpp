#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class bMoney
{
private:
	char Dollar = '$';
	long double Value;
	string Ustring;
	string money;
	string digits = "0123456789";
	long double Max = 9999999999999990.00;
public:
	bMoney(long double a)
	{
		if (a <= Max)
		{
			Value = a;
		}
		else
		{
			cout << "ERROR, too big value";
		}
	}
	bMoney()
	{}
	bMoney(char s[])
	{
		mstold(s);
	}
	bMoney(string s)
	{
		mstold(s);
	}
	bool Find(char c, string s)
	{
		bool result = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (c == s[i])
			{
				result = true;
			}
		}
		return result;
	}
	void mstold(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (Find(c, digits))
			{
				money.push_back(c);
			}
		}
		char* numbersCh = new char[money.length() + 1];
		strncpy_s(numbersCh, money.length()+1, money.c_str(), money.length());
		Value = atof(numbersCh);
		Value /= 100;
	}
	string ldtoms()
	{
		string uresult;
		string result;
		uresult = to_string(Value);
		int len = uresult.length();
		for (int i = len - 1; i >= 0; i--)
		{
			result = uresult[i] + result;
			if (i % 3 == 0 && (i > 2))
			{
				result = " " + result;
			}
		}
		result = Dollar + result;
		Ustring = result;
		return result;
	}
	bMoney operator+(bMoney a)
	{
		bMoney res(a.Value + Value);
		return res;
	}
	bMoney operator-(bMoney a)
	{
		bMoney res(Value - a.Value);
		return res;
	}
	bMoney operator*(long double a)
	{
		bMoney res(Value * a);
		return res;
	}
	bMoney operator/(long double a)
	{
		bMoney res(Value / a);
		return res;
	}
	long double operator/(bMoney a)
	{
		long double res = Value / a.Value;
		return res;
	}
	friend bMoney operator*(long double, bMoney);
	friend bMoney operator/(long double, bMoney);
	operator long double()
	{
		return Value;
	}
	void getmoney()
	{
		cout << "Input the amount of money: ";
		cin >> Value;
	}
	void putmoney()
	{
		cout << ldtoms();
	}
	void print_value()
	{
		cout << Value;
	}
};
bMoney operator*(long double a, bMoney object)
{
	return bMoney(a * object.Value);
}
bMoney operator/(long double a, bMoney object)
{
	return bMoney(a / object.Value);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	long double num = 150;
	bMoney money(2);
	cout << num << " / " << money << " = " << num / money << endl;
	cout << num << " * " << money << " = " << num * money << endl;
	return 0;
}
