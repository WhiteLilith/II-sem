#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class fraction
{
private:
	int c, z, c1, z1;
	char dummydum;
public:
	void enter()
	{
		cout << "Введите дробь в формате a/b: ";
		cin >> c >> dummydum >> z;
	}

	void out()
	{
		cout << c << dummydum << z << endl;
	}

	void sum()
	{
		cout << "Введите первую дробь в формате a/b: ";
		cin >> c >> dummydum >> z;
		cout << "Введите вторую дробь в формате a/b: ";
		cin >> c1 >> dummydum >> z1;
		cout << "Сумма этих дробей равна: " << (c*z1 + c1*z) << dummydum << (z*z1) << endl;
	}
};

int main() 
{
	setlocale(LC_ALL, "Russian");
	fraction c;
	char f = '+';
	while (f != '-')
	{
		c.sum();
		cout << "Хотите выполнить другое сложение?(+/-)  ";
		cin >> f;
	}
	system("pause");
}
