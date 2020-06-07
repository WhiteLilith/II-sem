#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class publication
{
private:
	string title;
	float price;

public:

	virtual void GetData()
	{
		cout << "\nEnter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
	}

	virtual void PutData()
	{
		cout << "\n\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
};

class book : public publication
{
private:
	int pages;

public:
	void GetData()
	{
		publication::GetData();
		cout << "Enter number of pages: ";
		cin >> pages;
	}

	void PutData()
	{
		publication::PutData();
		cout << "\nPages: " << pages;
	}
};

class tape : public publication
{
private:
	float time;

public:

	void GetData()
	{
		publication::GetData();
		cout << "Enter playing time: ";
		cin >> time;
	}

	void PutData()
	{
		publication::PutData();
		cout << "\nPlaying time: " << time;
	}
};

int main()
{
	publication* pubarr[100];
	int n = 0;
	char choice;

	do {
		cout << "\nEnter data for book or tape (b/t)? ";
		cin >> choice;

		if (choice == 'b')
		{
			pubarr[n] = new book;
		}
		else
		{
			pubarr[n] = new tape;
		}

		pubarr[n++]->GetData();
		cout << "Enter another (+/-)? ";
		cin >> choice;

	} while (choice == '+');
	for (int j = 0; j < n; j++)
	{
		pubarr[j]->PutData();
	}

	cout << endl;
	return 0;
}
