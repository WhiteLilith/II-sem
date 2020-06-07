#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


class safearay
{
	const static int lim = 10;
	int *arr;
public:
	safearay()
	{
	    arr = new int [lim];
	}

	void putel(int a, int b)
	{
		if ((a >= 0) && (a < lim))
		{
			arr[a] = b;
		}
		else
		{
			cout << "Введен неверный индекс." << endl;
		}
	}

	void getel(int a)
	{
		if ((a >= 0) && (a < lim))
		{
			cout << "a[" << a << "] = " << arr[a] << endl;
		}
		else
		{
			cout << "Введен неверный индекс." << endl;
		}
	}

};



int main()
{
	setlocale(LC_ALL, "Russian");

	safearay sal;

	sal.putel(6, 15);
	sal.putel(11, 6);

	sal.getel(6);
	sal.getel(11);
}
