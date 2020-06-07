#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class person
{
protected:
	string name;
	float salary;

public:
	void setData()
	{
		cout << endl << "Enter name: ";
		cin >> name;
		cout << "Enter salary: ";
		cin >> salary;
	}

	void printData()
	{
		cout << endl << name << endl;
		cout << salary;
	}

	string getName() //return the name
	{
		return name;
	}

	float getSalary()
	{
		return salary;
	}

};

int main()

{

	void bsort(person**, int);
	person* persPtr[100]; 
	int n = 0; 
	char choice;
	do {
		persPtr[n] = new person;
		persPtr[n]->setData();
		n++;
		cout << "Enter another (+/-)? ";
		cin >> choice;
	}

	while (choice == '+');
	cout << "\nUnsorted list:";
	for (int j = 0; j < n; j++)
	{
		persPtr[j]->printData();
	}

	bsort(persPtr, n);
	cout << "\nSorted list:";
	for (int j = 0; j < n; j++)
	{
		persPtr[j]->printData();
	}

	cout << endl;
	return 0;

}

void bsort(person** pp, int n)
{
	void order(person**, person**);
	int j, k;
	for (j = 0; j < n - 1; j++)
		for (k = j + 1; k < n; k++)
			order(pp + j, pp + k);

}

void order(person** pp1, person** pp2)
{
	if ((*pp1)->getSalary() > (*pp2)->getSalary())
	{
		person* tp = *pp1;
		*pp1 = *pp2;
		*pp2 = tp;
	}

}
