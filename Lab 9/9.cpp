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

	void getel(int number, int i, int j)
	{
		arrays[i][j] = number;
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
	int a0[10], a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10];

	randArr(a0);
	randArr(a1);
	randArr(a2);
	randArr(a3);
	randArr(a4);
	randArr(a5);
	randArr(a6);
	randArr(a7);
	randArr(a8);
	randArr(a9);

	tentoten check(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
	check.Arr();
	
	return 0; 
}
