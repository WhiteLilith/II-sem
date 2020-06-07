#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Array
{
private:
	int* ptr;
	int size;

public:

	Array()
	{
		size = 0;
		ptr = new int[0];
	}
	Array(int s)
	{
		size = s;
		ptr = new int[s];
	}

	Array(Array& arr)
	{
		this->size = arr.size;
		ptr = new int[this->size];
		for (int i = 0; i < size; i++)
		{
			*(ptr + i) = arr[i];
		}
	}

	~Array()
	{
		delete[] ptr;
	}

	int& operator [] (int j)
	{
		return *(ptr + j);
	}

	Array operator =(Array& arr)
	{
		delete[] ptr;
		ptr = new int[arr.size];
		size = arr.size;
		for (int i = 0; i < arr.size; i++)
		{
			*(ptr + i) = arr[i];
		}
		return *this;
	}

};

int main()

{
	const int SIZE = 4;
	Array arr1(SIZE);
	for (int j = 0; j < SIZE; j++)
	{
		arr1[j] = j * j;
	}
	for (int j = 0; j < SIZE; j++)
	{
		cout << arr1[j] << ' ';
	}
	cout << endl;
	Array arr2 = arr1;
	for (int j = 0; j < SIZE; j++)
	{
		cout << arr2[j] << ' ';
	}
	cout << endl;
	Array arr3;
	arr3 = arr1;
	for (int j = 0; j < SIZE; j++)
	{
		cout << arr3[j] << ' ' << endl;
	}

	return 0;
}
