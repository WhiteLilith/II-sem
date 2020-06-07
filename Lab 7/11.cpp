#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

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
		return Sterling(F,S,P);
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
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Sterling a(7.89), b(7, 17, 9), c;
	double z = 2.5;

	c = a + b;
	c.putSterling();

	c = a - b;
	c.putSterling();

	c = a * b;
	c.putSterling();

	c = a / b;
	c.putSterling();

	c = a * z;
	c.putSterling();

	c = a / z;
	c.putSterling();

	return 0;
}
