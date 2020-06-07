5)
#include <iostream>
using namespace std;

long hms_to_secs(int h, int m, int s){
  long hms = h*3600 + m*60 + s;
  return hms;
}

int main(){
  char a, b = '+';
  int h, m, s;
  while (b != '-'){
  cout << "Введите время в формате HH:MM:SS : ";
  cin >> h >> a >> m >> a >> s;
  cout << endl << "Время в секундах: " << hms_to_secs(h, m, s) << endl << "Хотите перевести еще одно время(+/-)? Ответ: ";
  cin >> b;
  }
}




6)
#include <iostream>
using namespace std;

long hms_to_secs(int h, int m, int s){
  long hms = h*3600 + m*60 + s;
  return hms;
}

int secs_to_time(long seconds){
int h = seconds/3600;
int m = (seconds - h*3600)/60;
int s = seconds - h*3600 - m*60;
cout << h << ":" << m << ":";
return s;
}

struct time{
int h, m, s, longt;
};

int main(){
  char a, b, c;
  struct time t;
  while (b != '-'){
  cout << "Введите операцию(s - seconds to time, t - time to seconds): ";
  cin >> c;
  if (c == 't')
  {
  cout << "Введите время в формате HH:MM:SS : ";
  cin >> t.h >> a >> t.m >> a >> t.s;
  cout << endl << "Время в секундах: " << hms_to_secs(t.h, t.m, t.s) << endl << "Хотите перевести еще одно время(+/-)? Ответ: ";
  cin >> b;
  }
  else
  {
  cout << "Введите количество секунд: ";
  cin >> t.longt;
  cout << "Время: " << secs_to_time(t.longt) << endl << "Хотите перевести еще одно время(+/-)? Ответ: ";
  cin >> b;
  }
  }
}




7)
#include <iostream>
using namespace std;

double power(double n, int p){
double result = 1.0;
for (int j=0; j<p; j++)
result *= n;
return result;
}

int power(int n, int p){
  int result = 1;
  for (int j=0; j<p; j++)
  result *= n;
  return result;
}

char power(char n, int p){
  char result = n;
  for (int j=1; j<p; j++)
  for (int i=0; i<j; i++)
  cout << n;
  return result;
}

float power(float n, int p){
  float result = 1;
  for (int j=0; j<p; j++)
  result *= n;
  return result;
}

long power(long n, int p){
  long result = 1;
  for (int j=0; j<p; j++)
  result *= n;
  return result;
}

int main(){
  double d;
  float f;
  long l;
  int i;
  char c;
  int p;
  cout << "Введите степень: ";
  cin >> p;
  cout << endl;
  cout << "Введите переменную типа double: ";
  cin >> d;
  cout << power(d,p);
  cout << endl << endl;
  cout << "Введите переменную типа float: ";
  cin >> f;
  cout << power(f,p);
  cout << endl << endl;
  cout << "Введите переменную типа long: ";
  cin >> l;
  cout << power(l,p);
  cout << endl << endl;
  cout << "Введите переменную типа int: ";
  cin >> i;
  cout << power(i,p);
  cout << endl << endl;
  cout << "Введите переменную типа char: ";
  cin >> c;
  cout << power(c,p);
  cout << endl;
}




8)
#include <iostream>
using namespace std;

void swap(int&a, int&b){
int c = a;
a = b;
b = c;
}

int main() {
  int a, b;
  cout << "Введите первое число: ";
  cin >> a;
  cout << "Введите второе число: ";
  cin >> b;
  swap(a,b);
  cout << endl << "Первое число: " << a << endl << "Второе число: " << b;
}





9)
#include <iostream>
using namespace std;

struct time{
int h, m, s;
};

void swap(struct time n1, struct time n2){
struct time n3;
n3.s = n1.s;
n3.m = n1.m;
n3.h = n1.h;
n1.s = n2.s;
n1.m = n2.m;
n1.h = n2.h;
n2.s = n3.s;
n2.m = n3.m;
n2.h = n3.h;
cout << endl;
cout << "Первое время:  " << n1.h << ':' << n1.m << ':' << n1.s << endl;
cout << "Второе время:  " << n2.h << ':' << n2.m << ':' << n2.s;
}

int main() {
  struct time n1, n2;
  char dummydum;
  cout << "Введите первое время(hh:mm:ss): ";
  cin >> n1.h >> dummydum >> n1.m >> dummydum >> n1.s;
  cout << "Введите второе время(hh:mm:ss): ";
  cin >> n2.h >> dummydum >> n2.m >> dummydum >> n2.s;
  swap(n1, n2);
}




10)
#include <iostream>
using namespace std;

void torime(int a){
cout << "Функция была вызвана " << a << " раз(-а)" << endl;
if (a <= 14){
  torime(++a);
}
}

int main(){
int a = 1;
torime(a);
}



11)
#include <iostream>
using namespace std;

struct sterling{
int F, S, P;
};

void inner(struct sterling&n1, struct sterling&n2){
cout << "Введите первую сумму(FF.SS.PP): £";
char dummydum;
cin >> n1.F >> dummydum >> n1.S >> dummydum >> n1.P;
cout << "Введите вторую сумму(FF.SS.PP): £";
cin >> n2.F >> dummydum >> n2.S >> dummydum >> n2.P; 
}

void sum(struct sterling&n1, struct sterling&n2){
n1.F = n1.F + n2.F;
n1.S = n1.S + n2.S;
n1.P = n1.P + n2.P;
while (n1.P >= 12){
  n1.S++;
  n1.P = n1.P - 12;
}
while (n1.S >= 20){
  n1.F++;
  n1.S = n1.S - 20;
}
}

void outter(struct sterling&n1, struct sterling&n2){
  cout << endl << endl << "Сумма равна: £" << n1.F << '.' << n1.S << '.' << n1.P;
}

int main(){
struct sterling n1, n2;
inner(n1, n2);
sum(n1, n2);
outter(n1, n2);
}



12)
#include <iostream>
using namespace std;

struct fraction{
int a,b;
};

void sum(struct fraction&n1, struct fraction&n2){
if (n2.b != n1.b)
      cout << "Сумма двух дробей: " << (n1.a*n2.b) + (n2.a*n1.b) << '/' << n1.b*n2.b << endl;
      else
      cout << "Сумма двух дробей: " << n1.a + n2.a << '/' << n2.b << endl;
}

void min(struct fraction&n1, struct fraction&n2){
if (n2.b != n1.b)
      cout << "Разность двух дробей: " << (n1.a*n2.b) - (n2.a*n1.b) << '/' << n1.b*n2.b << endl;
      else
      cout << "Разность двух дробей: " << n1.a - n2.a << '/' << n2.b << endl;
}

void multiple(struct fraction&n1, struct fraction&n2){
cout << "Произведение двух дробей равно: " << n1.a*n2.a << '/' << n1.b * n2.b << endl;
}

void div(struct fraction&n1, struct fraction&n2){
cout << "Частное двух дробей равно: " << n1.a * n2.b << '/' << n1.b * n2.a << endl;
}

int main(){
  fraction n1, n2;
  char r = '+', dummydum, oper;
  while (r == '+')
  {
    cout << "Введите дробь в формате a/b: ";
    cin >> n1.a >> dummydum >> n1.b;
    cout << "Введите операцию(+/-/*/:): ";
    cin >> oper;
    cout << "Введите дробь в формате a/b: ";
    cin >> n2.a >> dummydum >> n2.b;
    switch (oper){
      case '+': 
      sum(n1,n2);
      break;
      case '-':
      min(n1,n2);
      break;
      case '*':
      multiple(n1,n2);
      break;
      case ':':
      div(n1,n2);
      break;
    }
      cout << "Хотите провести еще одну операцию(+/-)? Ответ: ";
      cin >> r;
  }
}
