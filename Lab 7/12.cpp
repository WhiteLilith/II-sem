#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>

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
	int i;

public:
	bMoney()
	{}

	bMoney(long double a)
	{
		if (a <= Max)
		{
			Value = a;
		}
		else
		{
			cout << "Слишком большое значение.";
		}
	}
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
		for (i = 0; i < s.length(); i++)
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
		strncpy_s(numbersCh, money.length() + 1, money.c_str(), money.length());

		Value = atof(numbersCh);
		Value /= 10;
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

	operator long double()
	{
		return Value;
	}

	void getmoney()
	{
		cout << "Введите сумму в долларах: ";
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

	void convtod()
	{
		Value = Value / 50;
	}

};

class Sterling
{
	long F;
	int S, P;
	double D;
	char dummydum;
public:
	Sterling()
	{}

	Sterling(double f)
	{
		D = f;
	}

	Sterling(long Fs, int Ss, int Ps)
	{
		F = Fs;
		S = Ss;
		P = Ps;
		D = Fs + (Ps / 12 + Ss) / 20;
	}

	void getSterling()
	{
		cout << "Введите сумму в формате £FF.SS.PP: £";
		cin >> F >> dummydum >> S >> dummydum >> P;
	}

	void putSterling()
	{
		cout << "Результат: £" << F << "." << S << "." << P << endl;
	}

	Sterling operator + (Sterling a)
	{
		double res = D + a.D;
		F = (int)res;
		S = (res * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}

	Sterling operator - (Sterling a)
	{
		double res = D - a.D;
		F = (int)res;
		S = (res * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}

	Sterling operator * (Sterling a)
	{
		double res = D * a.D;
		F = (int)res;
		S = (res * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}

	Sterling operator / (Sterling a)
	{
		double res = D / a.D;
		F = (int)res;
		S = (res * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}

	Sterling operator * (double a)
	{
		double res = D * a;
		F = (int)res;
		S = (res * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}

	Sterling operator / (double a)
	{
		double res = D / a;
		F = (int)res;
		S = (res * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}

	operator double()
	{
		D = F + (P / 12 + S) / 20;
		return D;
	}

	Sterling operator = (bMoney a)
	{
		D = a;
		F = (int)D;
		S = (D * 100) - F * 100;
		S = S * 240 / 100;
		P = S % 12;
		S = S / 12;
		return Sterling(F, S, P);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	bool tf = true;

	do
	{
		tf = false;

		bMoney AmountToConvert;
		Sterling ConvertedAmount;

		AmountToConvert.getmoney();
		AmountToConvert.convtod();
		ConvertedAmount = AmountToConvert;
		ConvertedAmount.putSterling();


		cout << "Хотите продолжить? (+/-): ";
		char dummydum;
		cin >> dummydum;
		if (dummydum == '+')
		{
			tf = true;
		}

	} while (tf);

	return 0;
}
