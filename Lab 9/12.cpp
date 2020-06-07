#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

static float fmem[1024];
static int pmem[1024];
static int fmem_top = 0;
static int pmem_top = 0;

class Float
{
protected:
	int addr;

public:
	Float(float _input)
	{
		*(fmem + fmem_top) = _input;
		addr = fmem_top;
		fmem_top += 1;
	}

	Float operator=(float change)
	{
		fmem[addr] = change;
	}

	int operator&()
	{
		return addr;
	}
};

class ptrFloat
{
protected:
	int pmem_index;

public:
	ptrFloat(int f_add)
	{
		pmem_index = pmem_top;
		*(pmem + pmem_top) = f_add;
		pmem_top += 1;
	}

	float& operator*()
	{
		return fmem[pmem[pmem_index]];
	}

};

int main()
{
	Float varl = 1.234;
	Float var2 = 5.678;
	ptrFloat ptrl = &varl;
	ptrFloat ptr2 = &var2;

	cout << " *ptrl = " << *ptrl;
	cout << " *ptr2 = " << *ptr2 << endl << endl;

	*ptrl = 7.123;
	*ptr2 = 8.456;

	cout << " *ptrl = " << *ptrl;
	cout << " *ptr2 = " << *ptr2;

	return 0;
}
