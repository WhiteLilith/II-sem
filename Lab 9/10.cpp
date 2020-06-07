#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void randArr(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
	}
}

class tentoten
{
protected:
	static const int SIZE = 10;
	int* arrays[SIZE];

public:
	tentoten()
	{
		for (int i = 0; i < SIZE; i++)
		{
			(arrays[i]) = new int[SIZE];
			randArr(arrays[i]);
		}
	}

	tentoten(int* a0, int* a1, int* a2, int* a3, int* a4, int* a5, int* a6, int* a7, int* a8, int* a9)
	{
		for (int i = 0; i < SIZE; i++)
		{
			(arrays[0]) = a0;
			(arrays[1]) = a1;
			(arrays[2]) = a2;
			(arrays[3]) = a3;
			(arrays[4]) = a4;
			(arrays[5]) = a5;
			(arrays[6]) = a6;
			(arrays[7]) = a7;
			(arrays[8]) = a8;
			(arrays[9]) = a9;
		}
	}

	void getel(int num, int i, int j)
	{
		arrays[i][j] = num;
	}

	int putel(int i, int j)
	{
		return arrays[i][j];
	}

	void Arr()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << (arrays[i][j]) << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	tentoten arr;

	arr.Arr();

	return 0; 
}
