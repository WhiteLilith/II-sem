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
		if (s >= 60)
		{
			s -= 60;
			m++;
		}
		if (m >= 60)
		{
			m -= 60;
			h++;
		}

		if (s < 0)
		{
			s += 60;
			m--;
		}
		if (m < 0)
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

};

int main()
{
	Time a(12, 15, 10);

	a++.display();
	cout << endl;
	a.display();
	cout << endl;

	--a;
	a--;
	a.display();

}
