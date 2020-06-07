#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Sterling
{
protected:
	long F;
	int S;
	float P;

	double desF;

	void convtoold()
	{
		double pennyTemp, bus1, bus2;

		P = desF * 240;
		F = static_cast<long>(desF);

		pennyTemp = F * 240;
		bus1 = P - pennyTemp;
		bus1 = static_cast<int>(bus1);

		S = bus1 / 12;
		S = static_cast<int>(S);

		bus2 = S * 12;
		P = bus1 - bus2;
	}

	void convtodes()
	{
		desF = F + (P / 12 + S) / 20;
	}

public:
	Sterling() : F(0), S(0), P(0), desF(0)
	{}

	Sterling(double desF) :F(0), S(0), P(0), desF(desF)
	{
		convtoold();
	}

	Sterling(long F, int S, float P) : F(F), S(S), P(P), desF(0.0)
	{
		convtodes();
	}

	void DisplaySterling()
	{
		cout << "\n" << F << "." << S << "." << P << "\n";
	}

	double GetDecimalPounds() const
	{
		return desF;
	}

	Sterling operator+(Sterling s)
	{
		double Fnew = desF + s.desF;
		return Sterling(Fnew);
	}

	Sterling operator-(Sterling s)
	{
		double Fnew = desF - s.desF;
		return Sterling(Fnew);
	}

	Sterling operator/(Sterling s)
	{
		double Fnew = desF / s.desF;
		return Sterling(Fnew);
	}

	Sterling operator*(double d)
	{
		double Fnew = desF * d;
		return Sterling(Fnew);
	}

	Sterling operator/(double d)
	{
		double Fnew = desF / d;
		return Sterling(Fnew);
	}
};


class Sterfac : public Sterling
{
private:
	int a;

public:
	Sterfac() : Sterling(), a(0)
	{ }

	Sterfac(double desF) : Sterling(desF), a(0)
	{ }

	Sterfac(long F, int S, int P, int e) : Sterling(F, S, P + a / 8)
	{
		a = e;
	}

	void DisplaySterling()
	{
		cout << "\n" << F << "." << S << "." << P << "-"
			<< a << "/8" << endl;
	}

	void PutSterlingOld()
	{
		cout << "\nВведите сумму(old system): ";
		char dummydum;
		cin >> F >> dummydum >> S >> dummydum
			>> P >> dummydum >> a >> dummydum >> dummydum;
		convtodes();
	}

	double GetDecimalPounds() const
	{
		return desF;
	}

	Sterfac operator+ (Sterfac s)
	{
		double Fnew = desF + s.desF;
		return Sterfac(Fnew);
	}

	Sterfac operator- (Sterfac s)
	{
		double Fnew = desF - s.desF;
		return Sterfac(Fnew);
	}

	Sterfac operator* (double d)
	{
		double Fnew = desF * d;
		return Sterfac(Fnew);
	}

	Sterfac operator/ (double d)
	{
		double Fnew = desF / d;
		return Sterfac(Fnew);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Sterfac n1;
	n1.PutSterlingOld();

	double _input;
	cout << "Введите десятичные фунты: ";
	cin >> _input;

	Sterfac n2(_input);

	Sterfac result = n1 - n2;
	cout << "- : " << endl;
	result.DisplaySterling();

	cout << endl;
	result = n1 + n2;
	cout << "+ : " << endl;
	result.DisplaySterling();

	cout << endl;
	result = n1 * 2;
	cout << "*2 : " << endl;
	result.DisplaySterling();

	cout << endl;
	result = n1 / 2;
	cout << "/2 : " << endl;
	result.DisplaySterling();

	return 0;
}
