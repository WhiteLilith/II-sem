4)
#include "stdafx.h"
#include <iostream>
#include <limits.h>

using namespace std;

int maxint(int a[], int c)
{
	int max = -32676;
	int max_num;
	for (int i = 0; i < c; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			max_num = i;
		}
	}
	return max_num;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов в массиве: ";
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
	int a = maxint(arr, n);
	cout << "Наибольший элемент: " << arr[a] << ", его номер - " << a << endl;
	system("pause");
	return 0;
}
