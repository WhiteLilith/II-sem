4)
#include <iostream>
using namespace std;

class employee{
  private:
  int number;
  float salary;
  public:
  void inner(int number_new, float salary_new){
    cout << endl << "Введите номер сотрудника: ";
    cin >> number_new;
    cout << "Введите размер оклада сотрудника: ";
    cin >> salary_new;
    cout << endl;
    number = number_new;
    salary = salary_new;
  }
  void outter(){
    cout << endl << endl << "Номер сотрудника: " << number << endl;
    cout << "Оклад сотрудника: " << salary;
  }
};

int main(){
int number_new;
float salary_new;
employee n1, n2, n3;
n1.inner(number_new, salary_new);
n2.inner(number_new, salary_new);
n3.inner(number_new, salary_new);
n1.outter();
n2.outter();
n3.outter();
}




5)
#include <iostream>
using namespace std;

class date{
private:
int day, month, year;
char dummydum;
public:
void getdate(int day_new, int month_new, int year_new){
  cout << endl << "Введите дату(DD/MM/YY): ";
  cin >> day_new >> dummydum >> month_new >> dummydum >> year_new;
  day = day_new;
  month = month_new;
  year = year_new;
}
void showdate(){
  cout << endl << endl << "Дата: " << day << '/' << month << '/' << year;
}
};

int main(){
int day_new, month_new, year_new;
date d;
d.getdate(day_new, month_new, year_new);
d.showdate();
}



6)
#include <iostream>
using namespace std;

class employee{
  private:
  int number;
  float salary;
  enum etype {laborer, secretary, manager, accountant, executive, researcher};
  etype jobname;
  struct date{
    int day, month, year;
  };
  date d;

  public:
  void inner(int number_new, float salary_new, int day_new, int month_new, int year_new, char j){
    cout << endl << "Введите номер сотрудника: ";
    cin >> number_new;

    cout << "Введите дату приема сотрудника на работу(DD/MM/YY): ";
    cin >> day_new >> j >> month_new >> j >> year_new;
    d.day = day_new;
    d.month = month_new;
    d.year = year_new;

    cout << "Введите первую букву должности(l/s/m/a/e/r): "; 
    cin >> j; 
    switch (j) 
    { 
      case 'l': 
      jobname = laborer; 
      break; 
      case 's': 
      jobname = secretary; 
      break; 
      case 'm': 
      jobname = manager; 
      break; 
      case 'a': 
      jobname = accountant; 
      break; 
      case 'e': 
      jobname = executive; 
      break; 
      case 'r': 
      jobname = researcher; 
      break; 
    }

    cout << "Введите размер оклада сотрудника: ";
    cin >> salary_new;
    number = number_new;
    salary = salary_new;
  }

  void outter(){
    cout << endl  << "Номер сотрудника: " << number << endl;

    cout << "Дата принятия на работу: " << d.day << '/' << d.month << '/' << d.year << endl;

    cout << "Должность: ";
    switch (number) 
    { 
      case (laborer): 
      cout << "laborer"; 
      break; 
      case (secretary): 
      cout << "secretary"; 
      break; 
      case (manager): 
      cout << "manager"; 
      break; 
      case (accountant): 
      cout << "accountant"; 
      break; 
      case (executive): 
      cout << "executive"; 
      break; 
      case (researcher): 
      cout << "researcher"; 
      break; 
    } 
    cout << endl;

    cout << "Оклад сотрудника: " << salary << endl;
  }
};

int main(){
int number_new;
float salary_new;
int day_new, month_new, year_new;
char j_new;
employee n1, n2, n3;
n1.inner(number_new, salary_new, day_new, month_new, year_new, j_new);
n2.inner(number_new, salary_new, day_new, month_new, year_new, j_new);
n3.inner(number_new, salary_new, day_new, month_new, year_new, j_new);
n1.outter();
n2.outter();
n3.outter();
}





7)
#include <iostream>
using namespace std;

class angle{
private:
int deg;
float min;
char dir;
public:
angle(int d, float m, char di){
  deg = d;
  min = m;
  dir = di;
}
void inner(int d, float m, char di){
  cout << "Введите направление(N/S/W/E): ";
  cin >> di;
  cout << "Введите градусы: ";
  cin >> d;
  cout << "Введите минуты: ";
  cin >> m;
  dir = di;
  deg = d;
  min = m;
  cout << endl;
}
void outter(){
  cout << endl << deg << "°" << min << "\' " << dir << endl;
}
};

void mainQ(int d, float m, char di){
angle n1(179, 89.9, 'S');
char a;
a = '+';
n1.outter();
while (a != '-'){
  cout << endl << "Хотите внести другие координаты?(+/-) ";
  cin >> a;
  if (a != '-'){
    n1.inner(d, m, di);
    n1.outter();
  }
}
}

int main() {
  int d;
  float m;
  char di;
  mainQ(d, m, di);
}



8)
#include <iostream>
using namespace std;

class counter{
  int count;
  public:
  static int c;
  counter(int count){
    cout << endl << endl <<  "Задайте объект: ";
    cin >> count;
    cout << endl << "Мой порядковый номер " << ++c << endl;
  }
};

int counter::c = 0;

int main(){
  counter c1(1), c2(2), c3(3);
}




9)
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




10)
#include "stdafx.h"
#include <iostream>
using namespace std;

class ship 
{
private:
	static int n;
	int deg_d, deg_sh;
	float min_d, min_sh;
	char dir_d, dir_sh;
public:
	void angle_sh(int d, float m, char di) 
	{
		deg_sh = d;
		min_sh = m;
		dir_sh = di;
	}

	void angle_d(int d, float m, char di) 
	{
		deg_d = d;
		min_d = m;
		dir_d = di;
	}

	void inner() 
	{
		int d_d, d_sh;
		float m_d, m_sh;
		char di_d, di_sh;

		cout << "Внесение данных о корабле..." << endl << endl;
		cout << "|ШИРОТА| " << endl;
		cout << "Введите направление(N/S/W/E): ";
		cin >> di_sh;
		cout << "Введите градусы: ";
		cin >> d_sh;
		cout << "Введите минуты: ";
		cin >> m_sh;

		dir_sh = di_sh;
		deg_sh = d_sh;
		min_sh = m_sh;
		
		cout << endl;
		
		cout << "|ДОЛГОТА|" << endl;
		cout << "Введите направление(N/S/W/E): ";
		cin >> di_d;
		cout << "Введите градусы: ";
		cin >> d_d;
		cout << "Введите минуты: ";
		cin >> m_d;

		dir_d = di_d;
		deg_d = d_d;
		min_d = m_d;

		cout << endl << "Данные внесены." << endl << endl;
	}

	void outter() 
	{
		cout << "Номер корабля: " << ++n;
		cout << endl << "Широта: " << deg_sh << "°" << min_sh << "\' " << dir_sh;
		cout << endl << "Долгота: " << deg_d << "°" << min_d << "\' " << dir_d << endl << endl;
	}
};

int ship::n = 0;

int mainQ()
{
	setlocale(LC_ALL, "Russian");
	ship n1, n2, n3;
	n1.inner();
	n2.inner();
	n3.inner();
	n1.outter();
	n2.outter();
	n3.outter();
	system("pause");
	return 0;
}

int main()
{
	mainQ();
}


11)
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

class fraction
{
private:
	int num, den;
	char dummydum;

public:

	fraction()
	{
		num = 1;
		den = 1;
	}

	fraction(int a, int b)
	{
		num = a;
		den = b;
	}

	void enter()
	{
		cout << "Введите дробь в формате a/b: ";
		cin >> num >> dummydum >> den;
	}

	void out()
	{
		cout << num << dummydum << den << endl;
	}

	void sum(fraction n)
	{
		int num_, den_;
		num_ = num*n.den + n.num*den;
		den_ = den*n.den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void min(fraction n)
	{
		int num_, den_;
		num_ = num*n.den - n.num*den;
		den_ = den*n.den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void mult(fraction n)
	{
		int num_, den_;
		num_ = num*n.num;
		den_ = den*n.den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void div(fraction n)
	{
		int num_, den_;
		num_ = num*n.den;
		den_ = den*n.num;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void lowterms();
};

void fraction::lowterms() //Сокращение дроби
{
	long tnum, tden, temp, gcd;
	tnum = labs(num); // Используем неотрицательные значения
	tden = labs(den); // Нужен cmath
	if (tden == 0) 
	{ // Проверка знаменателя
		cout << "Недопустимый знаменатель"; 
		exit(1);
	}
	else if (tnum == 0) 
	{
		num = 0;
		den = 1;
		return;
	}
	// Нахождение наибольшего общего делителя
	while (tnum != 0) 
	{
		if (tnum < tden) 
		{ // Если числитель больше знаменателя, меняем их местами.
			temp = tnum;
			tnum = tden;
			tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;// Делим числитель и знаменатель на НОД.
	num = num / gcd;
	den = den / gcd;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char f;
	fraction n1, n2;
	cout << "Вы хотите произвести операцию?(+/-)  ";
	cin >> f;
	while (f != '-')
	{
		if (f != '-')
		{
			cout << "Какую операцию вы хотите произвести?(+/-/:/*)   ";
			cin >> f;
			switch(f)
			{
			case '+':
				n1.enter();
				n2.enter();
				n1.sum(n2);
				n1.out();
				break;
			case '-':
				n1.enter();
				n2.enter();
				n1.min(n2);
				n1.out();
				break;
			case ':':
				n1.enter();
				n2.enter();
				n1.div(n2);
				n1.out();
				break;
			case '*':
				n1.enter();
				n2.enter();
				n1.mult(n2);
				n1.out();
				break;
			}
			cout << "Хотите произвести следующую операцию?(+/-)  ";
			cin >> f;
		}
	}
    return 0;
}





12)
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

class fraction
{
private:
	char dummydum;

public:
	int num, den;

	fraction()
	{
		num = 1;
		den = 1;
	}

	fraction(int a, int b)
	{
		num = a;
		den = b;
	}

	void enter()
	{
		cout << "Введите дробь в формате a/b: ";
		cin >> num >> dummydum >> den;
	}

	void out()
	{
		cout << num << dummydum << den << endl;
	}

	void sum(fraction n)
	{
		int num_, den_;
		num_ = num*n.den + n.num*den;
		den_ = den*n.den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void min(fraction n)
	{
		int num_, den_;
		num_ = num*n.den - n.num*den;
		den_ = den*n.den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void mult(fraction n)
	{
		int num_, den_;
		num_ = num*n.num;
		den_ = den*n.den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void div(fraction n)
	{
		int num_, den_;
		num_ = num*n.den;
		den_ = den*n.num;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
	}

	void setfraction(int numerator, int denumirator)
    {
		int num_, den_;
        num = numerator;
        den = denumirator;
		num_ = num;
		den_ = den;
		fraction n_(num_, den_);
		n_.lowterms();
		num = n_.num;
		den = n_.den;
    }

    int getnum()
    {
        return num;
    }

    int getden()
    {
        return den;
    }

	void lowterms();
};

void fraction::lowterms() //Сокращение дроби
{
	long tnum, tden, temp, gcd;
	tnum = labs(num); // Используем неотрицательные значения
	tden = labs(den); // Нужен cmath
	if (tden == 0)
	{ // Проверка знаменателя
		cout << "Недопустимый знаменатель";
		exit(1);
	}
	else if (tnum == 0)
	{
		num = 0;
		den = 1;
		return;
	}
	// Нахождение наибольшего общего делителя
	while (tnum != 0)
	{
		if (tnum < tden)
		{ // Если числитель больше знаменателя, меняем их местами.
			temp = tnum;
			tnum = tden;
			tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;// Делим числитель и знаменатель на НОД.
	num = num / gcd;
	den = den / gcd;
}




int main()
{
	setlocale(LC_ALL, "Russian");

	int num, den;
	int newden;
	char dummydum;

	cout << "Введите знаменатель: ";
	cin >> newden;

	fraction n1, n2, n3;

	for (int i = 1; i < newden; i++)
	{
		n1.setfraction(i, newden);
		cout << n1.getnum() << "/" << n1.getden() << " ";
	}

	cout << endl;

	for (int i = 1; i < newden; i++)
	{
		n2.setfraction(i, newden);
		for (int j = 1; j < newden; j++)
		{
			n1.setfraction(j, newden);
			n1.mult(n2);
			n3.num = n1.num;
			n3.den = n1.den;
			cout << n3.getnum() << "/" << n3.getden() << " ";
		}
		cout << "\n";
	}
	system("pause");
}
