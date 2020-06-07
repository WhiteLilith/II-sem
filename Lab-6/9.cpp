#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


class queue
{
	static const int lim = 10;
	int head, tail;
	int *arr;
public:
	queue()
	{
		head = -1;
		tail = -1;
		arr = new int[lim];
	}
	void put(int a)
	{
		tail++;
		arr[tail] = a;
		if (tail == lim - 1)
		{
			tail = -1;
		}
	}
	
	void get()
	{
		head++;
		cout << arr[head] << endl;
		if (head == lim - 1)
		{
			head = -1;
		}
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");

	queue q;

	q.put(7);
	q.put(10);
	q.put(13);

	q.get();
	q.get();
	q.get();
}
