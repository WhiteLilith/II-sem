#include "stdafx.h"
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Time

{

private:

	int h, m, s;

	void Check()
	{
		while (s >= 60)
		{
			s -= 60;
			m++;
		}
		while (m >= 60)
		{
			m -= 60;
			h++;
		}

		while (s < 0)
		{
			s += 60;
			m--;
		}
		while (m < 0)
		{
			m += 60;
			h--;
		}
	}

public:

	Time()
	{
		h = 0;
		m = 0;
		s = 0;
	}

	Time(int hrs, int mins, int secs)
	{
		h = hrs;
		m = mins;
		s = secs;
	}

	void display()

	{
		cout << h << ":" << m << ":" << s;
	}

	Time operator -(Time t)
	{
		Time rez(h - t.h, m - t.m, s - t.s);
		rez.Check();
		return rez;
	}

	Time& operator++()
	{
		Time rez(h, m, ++s);
		rez.Check();
		return(rez);
	}
	Time operator++(int)
	{
		Time rez(h, m, s++);
		rez.Check();
		return rez;
	}

	Time& operator--()
	{
		Time rez(h, m, --s);
		rez.Check();
		return rez;
	}

	Time operator--(int)
	{
		Time rez(h, m, s--);
		rez.Check();
		return rez;
	}

	Time operator*(float a)
	{
		Time rez(h * a, m * a, s * a);
		rez.Check();
		return rez;
	}

};

int main()
{
	Time a(12, 15, 10);
	Time b(5, 4, 3);
	Time result;
	float m = 2;

	cout << "a = ";
	a.display();
	cout << endl;
	cout << "b = ";
	b.display();
	cout << endl;

	result = a - b;
	cout << "a - b = ";
	result.display();
	cout << endl;

	result = result * m;
	cout << "(a - b) * 2 = ";
	result.display();
}
