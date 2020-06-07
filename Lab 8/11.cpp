#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Stack
{
protected:
	int* value;
	int size;
	int head;

public:
	Stack() : size(10)
	{
		head = -1;
		value = new int[size];
	}

	Stack(int s) : size(s)
	{
		head = -1;
		value = new int[size];
	}

	void push(int number)
	{
		head++;
		value[head] = number;
	}

	int pop()
	{
		return value[head];
		head--;
	}
};

struct Pair
{
	int x;
	int y;
};

class PairStack : public Stack
{
public:

	PairStack()
	{
		Stack(15);
	}

	PairStack(int a)
	{
		Stack::size = a;
		head = -1;
		value = new int[size];
	}

	void push(Pair a)
	{
		Stack::push(a.x);
		Stack::push(a.y);
	}

	Pair pop()
	{
		Pair res;
		res.y = Stack::pop();
		Stack::head--;
		res.x = Stack::pop();
		Stack::head--;
		return(res);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	PairStack show;

	Pair cord;
	cord.x = 15;
	cord.y = -7;

	show.push(cord);

	Pair result = show.pop();

	cout << "x = " << result.x << endl;
	cout << "y = " << result.y << endl;

	return 0;
}
