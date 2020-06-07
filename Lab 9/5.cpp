#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void getarr(float* res_arr, float* arr1, float* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		res_arr[i] = arr1[i] + arr2[i];
	}
}

int main()
{
	const int SIZE = 8;
	float arr1[SIZE];

	int b = 0;
	for (int i = 0; i < SIZE; i++)
	{
		*(arr1 + b++) = i * 2;
	}

	int size = SIZE;
	float* arr2 = new float[size];

	for (int i = 0; i < SIZE; i++)
	{
		arr2[i] = i * i;
	}

	float res_arr[SIZE];
	getarr(res_arr, arr1, arr2, SIZE);
	b = 0;

	for (int i = 0; i < SIZE; i++)
	{
		cout << *(res_arr + b++) << " ";
	}

	return 0;
}
