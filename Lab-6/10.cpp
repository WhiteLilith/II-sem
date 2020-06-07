#include "stdafx.h"
#include <iostream>
#include <cstdlib>


using namespace std;


class matrix
{
	int *arr;
	int str = 10, stl = 10;
public:
	matrix()
	{
		str = 10;
		stl = 10;
		arr = new int[str, stl];
	}
	matrix(int a, int b)
	{
		if ((a > 0) && (a <= str) && (b > 0) && (b <= stl))
		{
			str = a;
			stl = b;
			arr = new int[str, stl];
		}
		else
		{
			cout << "Введены неверные индексы матрицы." << endl;
		}
	}
	void putel(int a, int b, int c)
	{
		if ((a > 0) && (a <= str) && (b > 0) && (b <= stl))
		{
			arr[a, b] = c;
		}
		else
		{
			cout << "Введены неверные индексы матрицы." << endl;
		}
	}

	void getel(int a, int b)
	{
		if ((a > 0) && (a <= str) && (b > 0) && (b <= stl))
		{
			cout << "a[" << a << ", " << b << "] = " << arr[a, b] << endl;
		}
		else
		{
			cout << "Введены неверные индексы матрицы." << endl;
		}
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");

	matrix m(7,5);

	m.putel(13, 5, 1);
	m.putel(7, 5, 1);
	m.putel(1, 1, 6);

	m.getel(13, 5);
	m.getel(7, 5);
	m.getel(1, 1);
}
