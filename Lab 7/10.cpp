#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
	float radius, angle, x, y;
public:
	Polar()
	{
		x = 0;
		y = 0;
		radius = 0;
		angle = 0;
	}

	Polar(float rad, float ang)
	{
		x = rad * cos(ang);
		y = rad * sin(ang);
		radius = rad;
		angle = ang;
	}

	Polar operator+(Polar a)
	{
		double x1 = a.x + x;
		double y1 = a.y + y;
		double rad = sqrt(x1 * x1 + y1 * y1);
		double ang = acos(x1 / rad);
		Polar res(rad, ang);
		return res;
	}

	void getc()
	{
		cout << "Радиус = " << radius << ", Угол = " << angle << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Polar n1(15, 1.5);
	cout << "Первые координаты: ";
	n1.getc();
	Polar n2(2, 6.6);
	cout << "Вторые координаты: ";
	n2.getc();
	Polar result = n1 + n2;
	cout << "Сумма: ";
	result.getc();

	return 0;
}
