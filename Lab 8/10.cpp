#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int length = 80;

class student
{
protected:
	char school[length];
	char degree[length];

public:

	void getedu()
	{
		cout << " Enter name of school or university: ";
		cin >> school;
		cout << " Enter highest degree earned \n";
		cout << " (Highschool, Bachelor's, Master's, PhD): ";
		cin >> degree;
	}

	void putedu() const
	{
		cout << "\n School or university: " << school;
		cout << "\n Highest degree earned: " << degree;
	}
};

class employee

{
protected:
	char name[length];
	unsigned long number;

public:
	void getdata()
	{
		cout << "\n Enter last name: "; cin >> name;
		cout << " Enter number: "; cin >> number;
	}

	void putdata() const
	{
		cout << "\n Name: " << name;
		cout << "\n Number: " << number;
	}

};

class manager : public employee, public student
{
protected:
	char title[length];
	double dues;

public:
	void getdata()
	{
		employee::getdata();
		cout << " Enter title: "; cin >> title;
		cout << " Enter golf club dues: "; cin >> dues;
		student::getedu();
	}

	void putdata() const
	{
		employee::putdata();
		cout << "\n Title: " << title;
		cout << "\n Golf club dues: " << dues;
		student::putedu();
	}
};

class scientist : public employee, public student
{
protected:
	int pubs;

public:
	void getdata()
	{
		employee::getdata();
		cout << " Enter number of pubs: "; cin >> pubs;
		student::getedu();
	}

	void putdata() const
	{
		employee::putdata();
		cout << "\n Number of publications: " << pubs;
		student::putedu();
	}

};

class laborer : public employee

{
};

class executive : public manager
{
protected:
	float Premium;
	float Stocks;
public:

	void PutData()
	{
		manager::getdata();
		cout << "Input premium: ";
		cin >> Premium;
		cout << "Input amount of stocks: ";
		cin >> Stocks;
	}

	void GetData()
	{
		manager::putdata();
		cout << "\n Premium = " << Premium;
		cout << "\n Amount of stocks = " << Stocks;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	executive person;

	person.PutData();
	person.GetData();

	cout << endl;

	return 0;
}
