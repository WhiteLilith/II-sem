#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Publication
{
private:
	string title;
	float price;

public:
	void getdata()
	{
		cout << "Введите заголовок: "; 
		cin >> title;
		cout << "Введите цену: "; 
		cin >> price;
	}

	void putdata() const
	{
		cout << "Заголовок: " << title;
		cout << "Цена: " << price;
	}
};

class disk : public Publication
{
private:
	char type;

public:
	void getdata()
	{
		cout << "Введите тип диска(c/d): ";
		cin >> type;
	}

	void putdata()
	{
		switch (type)
		{
		case 'c':
		{
			cout << "Тип диска: CD" << endl;
			break;
		}
		case 'd':
		{
			cout << "Тип диска: DVD" << endl;
			break;
		}
		default:
		{
			cout << "Неверный тип диска." << endl;
		}
		};
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");

	disk a, b;
	a.getdata();
	b.getdata();
	a.putdata();
	b.putdata();

	return 0;
}
