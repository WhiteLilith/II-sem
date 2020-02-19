4) 
#include <iostream>
using namespace std;
struct employee
{int number;
float salary;
};
int main() {
  int i;
 employee n1, n2, n3;
 cout << "Введите номер сотрудника: " << endl;
 cin >> n1.number;
 cout << "Введите размер оклада сотрудника: " << endl;
 cin >> n1.salary;
 cout << "Введите номер сотрудника: " << endl;
 cin >> n2.number;
 cout << "Введите размер оклада сотрудника: " << endl;
 cin >> n2.salary;
 cout << "Введите номер сотрудника: " << endl;
 cin >> n3.number;
 cout << "Введите размер оклада сотрудника: " << endl;
 cin >> n3.salary;
 cout << "Номер сотрудника: " << n1.number << endl;
 cout << "Оклад сотрудника: " << n1.salary << endl;
 cout << "Номер сотрудника: " << n2.number << endl;
 cout << "Оклад сотрудника: " << n2.salary << endl;
 cout << "Номер сотрудника: " << n3.number << endl;
 cout << "Оклад сотрудника: " << n3.salary << endl;
}




5)
#include <iostream>
using namespace std;
struct date
{ int d, m, y;
};
int main() {
  date n1;
  char a;
cout << "Введите дату в формате день/месяц/год: ";
cin >> n1.d >> a >> n1.m >> a >> n1.y;
if (n1.d < 10)
cout << "Дата: " << "0" << n1.d << a;
else
cout << "Дата: " << n1.d << a;
if (n1.m < 10)
cout << "0" << n1.m << a << n1.y;
else 
cout << n1.m << a << n1.y;
}




6)
#include <iostream> 
using namespace std; 
enum etype { laborer, secretary, manager, accountant, executive, researcher }; 
int main() 
{ 
etype number; 
char a; 
cout << "Введите первую букву должности: "; 
cin >> a; 
switch (a) 
{ 
case 'l': 
number = laborer; 
break; 
case 's': 
number = secretary; 
break; 
case 'm': 
number = manager; 
break; 
case 'a': 
number = accountant; 
break; 
case 'e': 
number = executive; 
break; 
case 'r': 
number = researcher; 
break; 
} 
cout << "Полное название должности: "; 
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
}



7)
#include <iostream> 
using namespace std; 

enum etype { laborer, secretary, manager, accountant, executive, researcher }; 

struct Employee{
int d, m, y, number;
float salary;
char job;
};

int main() 
{ 
etype job; 
Employee n[3];
char a, f; 
int i;
for (i=1; i<=3; i++)
{
cout << "Введите номер сотрудника: ";
cin >> n[i].number;
cout << "Введите величину оклада сотрудника: ";
cin >> n[i].salary;
cout << "Введите первую букву должности: "; 
cin >> a;
switch (a) 
{ 
case 'l': 
n[i].job = laborer; 
break; 
case 's': 
n[i].job = secretary; 
break; 
case 'm': 
n[i].job = manager; 
break; 
case 'a': 
n[i].job = accountant; 
break; 
case 'e': 
n[i].job = executive; 
break; 
case 'r': 
n[i].job = researcher; 
break; 
} 
cout << "Введите дату принятия сотрудника на работу(dd/mm/yyyy): ";
cin >> n[i].d >> f >> n[i].m >> f >> n[i].y;
cout << endl << endl; 
}
cout << endl;
for (i=1; i<=3; i++)
{
cout << "Номер сотрудника: " << n[i].number << endl;
cout << "Зарплата: "  << n[i].salary << endl;
cout << "Должность: "; 
switch (n[i].job) 
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
if (n[i].d < 10)
cout << "Дата: " << "0" << n[i].d << f;
else
cout << "Дата: " << n[i].d << f;
if (n[i].m < 10)
cout << "0" << n[i].m << f << n[i].y;
else 
cout << n[i].m << f << n[i].y; 
cout << endl;
cout << endl << endl; 
}
}




8)
#include <iostream>
using namespace std;

struct fraction{
int a;
int b;
};

int main(){
fraction n[2];
char dummydum;
int i;
for (i=0; i<=1; i++)
{
cout << "Введите дробь в формате a/b: ";
cin >> n[i].a >> dummydum >> n[i].b;
cout << endl;
}
if (n[1].b != n[0].b)
cout << "Сумма двух дробей: " << (n[0].a*n[1].b) + (n[1].a*n[0].b) << dummydum << n[0].b*n[1].b;
else
cout << "Сумма двух дробей: " << n[0].a + n[1].a << dummydum << n[1].b;
}




9)
#include <iostream>
using namespace std;

struct time{
int hours, minutes, seconds;
};

int main(){
  struct time t1;
  char dummydum;
  cout << "Введите время в формате HH:MM:SS : ";
  cin >> t1.hours >> dummydum >> t1.minutes >> dummydum >> t1.seconds;
  cout << endl;
  long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds;
  cout << totalsecs;
}



10)
#include <iostream>
using namespace std;

struct sterling{
int F, S, P;
};

int main(){
double D;
sterling bb;
cout << "Введите сумму в десятичных фунтах: £";
cin >> D;
bb.F = (int)D;
bb.S = ((D*100) - bb.F*100)*2.4;
bb.P = bb.S%12;
bb.S = bb.S/12;
cout << endl << "В старой системе сумма сотставляет: £" << bb.F << "." << bb.S << "." << bb.P;
}



11)
#include <iostream>
using namespace std;

struct time{
int h, m, s;
long totalsecs;
};

int main(){
struct time n[3];
char dummydum;
for (int i=0; i<=1; i++)
{
  cout << "Введите время в формате HH:MM:SS : ";
  cin >> n[i].h >> dummydum >> n[i].m >> dummydum >> n[i].s;
  cout << endl;
  n[i].totalsecs = n[i].h * 3600 + n[i].m * 60 + n[i].s;
}
n[2].totalsecs = n[1].totalsecs + n[0].totalsecs;
n[2].h = n[2].totalsecs/3600;
n[2].m = (n[2].totalsecs - n[2].h*3600)/60;
n[2].s = n[2].totalsecs - n[2].h * 3600 - n[2].m * 60;
cout << "Новое время: " << n[2].h << dummydum << n[2].m << dummydum << n[2].s << endl;
}




12)
#include <iostream>
using namespace std;

struct fraction{
int a,b;
};

int main(){
  fraction n[2];
  char r = '+', dummydum, oper;
  while (r == '+')
  {
    cout << "Введите дробь в формате a/b: ";
    cin >> n[0].a >> dummydum >> n[0].b;
    cout << "Введите операцию(+/-/*/:): ";
    cin >> oper;
    cout << "Введите дробь в формате a/b: ";
    cin >> n[1].a >> dummydum >> n[1].b;
    switch (oper){
      case '+': 
      if (n[1].b != n[0].b)
      cout << "Сумма двух дробей: " << (n[0].a*n[1].b) + (n[1].a*n[0].b) << dummydum << n[0].b*n[1].b << endl;
      else
      cout << "Сумма двух дробей: " << n[0].a + n[1].a << dummydum << n[1].b << endl;
      break;
      case '-':
      if (n[1].b != n[0].b)
      cout << "Разность двух дробей: " << (n[0].a*n[1].b) - (n[1].a*n[0].b) << dummydum << n[0].b*n[1].b << endl;
      else
      cout << "Разность двух дробей: " << n[0].a - n[1].a << dummydum << n[1].b << endl;
      break;
      case '*':
      cout << "Произведение двух дробей равно: " << n[0].a*n[1].a << dummydum << n[0].b * n[1].b << endl;
      break;
      case '/':
      cout << "Частное двух дробей равно: " << n[0].a * n[1].b << dummydum << n[0].b * n[1].a << endl;
      break;
    }
      cout << "Хотите провести еще одну операцию(+/-)? Ответ: ";
      cin >> r;
  }
}
