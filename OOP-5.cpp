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