#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

#include <process.h>

const int LIMIT = 100;

class Safearray

{

private:
	int arr[LIMIT];

public:

	int index1;
	int index2;

	Safearray()
	{
		index1 = 0;
		index2 = 100;
	};

	Safearray(int a, int b)
	{
		if (abs(a - b) >= 100)
		{
			cout << "Слишком большой интервал." << endl;
		}
		else
		{
			a %= 100;
			b %= 100;
			index1 = a;
			index2 = b;
		}
	}

	int& operator [](int a) //note: return by reference
	{
		if (a < index1 || a >= index2 + 1)
		{
			cout << endl << "Индекс за пределом значений."; 
			exit(1);
		}
		return arr[a];
	}

};

////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "Russian");
	int left_boundary, right_boundary;
	cout << "Введите нижнюю границу массива: ";
	cin >> left_boundary;
	cout << "Введите верхнюю границу массива: ";
	cin >> right_boundary;

	Safearray sa1(left_boundary, right_boundary);

	for (int j = sa1.index1; j <= sa1.index2; j++) //insert elements
	{
		sa1[j] = j * 10; //*left* side of equal sign
	}

	for (int j = sa1.index1; j <= sa1.index2; j++) //display elements
	{
		int temp = sa1[j]; //*right* side of equal sign
		cout << "a[" << j << "] =  " << temp << endl;
	}

	return 0;
}
