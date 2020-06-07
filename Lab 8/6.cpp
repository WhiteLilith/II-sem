#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int lim = 100;

class SafeArray
{
protected:
	int arr[lim];

public:
	int& operator [](int n)
	{
		if (n < 0 || n >= lim)
		{
			cout << "Выход за пределы индексов."; exit(1);
		}
		return arr[n];
	}
};

class SubSafeArray : SafeArray
{
public:
	int LowerIndex;
	int UpperIndex;

	int& operator [](int n)
	{
		if (n < LowerIndex || n > UpperIndex)
		{
			cout << "Выход за пределы индексов."; exit(1);
		}
		return arr[n % 100];
	}

	SubSafeArray(int a, int b)
	{
		if (b - a >= lim)
		{
			cout << "Ошибочка вышла."; exit(1);
		}

		LowerIndex = a;
		UpperIndex = b;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	SubSafeArray ExampleArray(105, 165);

	for (int i = 105; i <= 165; i++)
	{
		ExampleArray[i] = i * 10;
		cout << "a[" << i << "] = " << ExampleArray[i] << endl;
	}

	return 0;
}
