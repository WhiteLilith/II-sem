#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int size_val = 2;

class Array
{
protected:
	static const int size = size_val;
	int array[size][size];

public:
	Array()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				*(*(array + i) + j) = 0;
			}
		}
	}

	int& operator[](int index)
	{
		if (index > size * size)
		{
			cout << "Ошибочка вышла.";
			exit(1);
		}

		return *(*(array + index / size) + index % size);
	}
};

int main()
{
	Array check;

	for (int i = 0; i < size_val*size_val; i++)
	{
		check[i] = rand() % 100;
	}

	for (int i = 0; i < size_val*size_val; i++)
	{
		cout << check[i] << " ";
	}

	return 0;
}
