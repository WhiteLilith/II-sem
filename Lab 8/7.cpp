#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Counter
{
protected:
	unsigned int count; 
public:
	Counter() : count(0)
	{ }
	Counter(int c) : count(c)
	{ }
	unsigned int GetCount() const 
	{
		return count;
	}
	Counter operator ++ ()
	{
		return Counter(++count);
	}
};

class CountDn : public Counter
{
public:
	CountDn() : Counter()
	{ }

	CountDn(int c) : Counter(c)
	{ }

	CountDn operator-- ()
	{
		return CountDn(--count);
	}
	CountDn operator++ (int)
	{
		return CountDn(count++);
	}
	CountDn operator-- (int)
	{
		return CountDn(count--);
	}

	CountDn operator ++ ()
	{
		return Counter::count++;
	}

	unsigned int GetCount()
	{
		return Counter::GetCount();
	}


};

int main()
{
	CountDn a(18);

	++a;
	cout << a.GetCount() << endl;
	a++;
	cout << a.GetCount() << endl;
	a--;
	cout << a.GetCount() << endl;
	--a;
	cout << a.GetCount() << endl;
	return 0;
}
