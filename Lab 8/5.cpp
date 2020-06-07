#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int LEN = 80;


class employee
{
protected:
	char name[LEN];
	unsigned long number;

public:
	void getdata()
	{
		cout << "Enter last name: "; cin >> name;
		cout << " Enter number: "; cin >> number;
	}

	void putdata() const
	{
		cout << "Name: " << name;
		cout << "Number: " << number;
	}
};

class employee2 : public employee
{
protected:
	double compensation;
	enum period { почасовая, понедельная, помесячная };
	period p;

public: 
	void getdata(double c, int d)
	{
		compensation = c;
		switch (d)
		{
		case 0:
		{
			p = почасовая;
			break;
		}
		case 1:
		{
			p = понедельная;
			break;
		}
		case 2:
		{
			p = помесячная;
			break;
		}
		default:
		{
			cout << "Неверный тип." << endl;
		}
		}
	}

	void putdata()
	{
		cout << "Размер заработной платы: " << compensation << endl;
		cout << "Тип заработной платы: ";
		switch (p)
		{
		case почасовая:
		{
			cout << "почасовая" << endl;
			break;
		}
		case понедельная:
		{
			cout << "понедельная" << endl;
			break;
		}
		case помесячная:
		{
			cout << "помесячная" << endl;
			break;
		}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	employee2 n1, n2;

	n1.getdata(150, 1);
	n2.getdata(10, 0);

	n1.putdata();
	n2.putdata();

	return 0;
}
