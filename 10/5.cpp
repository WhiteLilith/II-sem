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
	virtual void getdata()
	{
		cout << "\nEnter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
	}
	virtual void putdata()
	{
		cout << "\n\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
	virtual bool isOveersize()
	{
		return false;
	}
};

class book : public publication
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter number of pages: "; cin >> pages;
	}
	void putdata()
	{
		publication::putdata();
		cout << "\nPages: " << pages;
	}
	bool isOversize()
	{
		if (pages > 800)
		{
			return true;
		}
		return false;
	}
};

class tape : public publication
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Enter playing time: "; cin >> time;
	}
	void putdata()
	{
		publication::putdata();
		cout << "\nPlaying time: " << time;
	}
	bool isOversize()
	{
		if (time > 90)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	publication* pubarr[100];
	int n = 0;
	char choice;
	do {
		cout << "\nEnter data for book or tape (b/t)? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new book;
		else
			pubarr[n] = new tape;
		pubarr[n++]->getdata();
		cout << " Enter another (y/n)? ";
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++)
	{
		pubarr[j]->putdata();
		if (!(pubarr[j]->isOveersize()))
		{
			cout << " Превышение размера!" << endl;
		}
	}
	cout << endl;
	return 0;
}
