5) 
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  string a = "X";
  int i;
  for (i=1; i<=20; i++)
  {
    cout << setw(21) << a << "\n";
    a = a + "X";
  }
}



6)
#include <iostream>
using namespace std;

int main()
{
unsigned int numb;
unsigned long fact=1;
numb = 1;
while (numb != 0)
{
  cout << "Enter a number: ";
  cin >> numb;
  if (numb != 0)
  { 
  for(int j=numb; j>0; j--)
  fact *= j;
  cout << "Factorial is " << fact << endl;
  }
  else cout << "Factorial is 1" << endl;
}
return 0;
}



7)
#include <iostream>
using namespace std;

int main(){
  float n, p, s;
  int i, y;
  cout << "Введите сумму вклада, процент и количество лет(целое), соответственно:\n";
  cin >> n >> p >> y;
  s = n;
  for (i=1; i<=y; i++){
    s = s + s*0.01*p;
    }
  cout << "Через " << y << " лет вы получите " << s << endl;
  return 0;
}


8)
#include <iostream>
using namespace std;

int main(){
  string a = "£";
  int f_old, s_old, p_old, f_new, s_new, p_new;
  char f = '+';
  while (f != '-')
  {
  cout << "Введите первую сумму:\n";
  cin >> f_old >> s_old >> p_old;
  cout << "Введите вторую сумму:\n";
  cin >> f_new >> s_new >> p_new;
  p_new = p_old + p_new;
  s_new = s_old + s_new;
  f_new = f_old + f_new;
  while(p_new > 11)
  {
    s_new++;
    p_new = p_new - 12;
  }
  while(s_new > 19)
  {
    f_new++;
    s_new = s_new - 20;
  }
  cout << "Всего: " << a << f_new << " " << s_new << " " << p_new << endl;
  cout << "Продолжить сложение?(+/-)\n";
  cin >> f;
  }
  return 0;
}



9)
#include <iostream>
using namespace std;

int main(){
  int a, b, i, s;
  cout << "Вместимость стола: ";
  cin >> a;
  cout << "Количество гостей: ";
  cin >> b;
  s = 1;
  for (i=b; i>=a-1; i--)
  s = s * i;
  cout << s << endl;
  return 0;
}



10)
#include <iostream>
using namespace std;

int main(){
  float n, p, s;
  int i, y;
  cout << "Введите сумму вклада, процент и итог, соответственно:\n";
  cin >> n >> p >> s;
  y = 0;
  while (s > n)
  {
    n = n + n*0.01*p;
    y++;
  }
  cout << "Через " << y << " лет вы получите запрошенную сумму\n";
  return 0;
}



11)
#include <iostream>
using namespace std;

int main(){
  int f, s, p, f1, s1, p1, result;
  float z;
  char oper;
  cout << "Введите сумму: \n";
  cin >> f >> s >> p;
  cout << "Введите операцию: ";
  cin >> oper;
  switch(oper)
  {
    case '*': 
    {
      cout << "Введите число: ";
      cin >> z;
      cout << endl;
      f = f*z;
      s = s*z;
      p = p*z;
      while (p>11){s++; p = p - 12;}
      while (s>19){f++; s = s - 20;}
      break;
    }
    case '+':
    {
      cout << "Введите вторую сумму:\n";
      cin >> f1;
      f = f + f1;
      cin >> s1;
      s = s + s1;
      cin >> p1;
      p = p + p1;
      while (p>11){s++; p = p - 12;}
      while (s>19){f++; s = s - 20;}
      break;
    }
    case '-':
    {
      cout << "Введите вторую сумму:\n";
      cin >> f1 >> s1 >> p1;
      p = f*20*12 + s*12 + p;
      p1 = f1*20*12 + s1*12 + p1;
      p = p - p1;
      f = p/2400;
      s = (p-(p/2400))/12;
      p = p - 2400*f - 12*s;
      break;
    }
  }
  cout << "Ответ: £" << f << " " << s << " " << p << endl;
  return 0;
}


12)
#include <iostream>
using namespace std;

int main(){
  int a,b,c,d;
  char oper, f;
  f = '+';
  while (f != '-')
  {
  cout << "Введите первую дробь: \n";
  cin >> a >> b;
  cout << "Введите операцию: \n";
  cin >> oper;
  cout << "Введите вторую дробь: \n";
  cin >> c >> d;
  switch(oper)
  {
    case '+':
    {
       a = a*d + b*c;
       b = b*d;
       break;
    }
    case '-':
    {
      a = a*d - b*c;
      b = b*d;
      break;
    }
    case '*':
    {
      a = a*c;
      b = b*d;
      break;
    }
    case '/':
    {
      a = a*d;
      b = b*c;
      break;
    }
  }
  cout << "Ответ: " << a << "/" << b << endl;
  cout << "Хотите провести еще одну операцию?(+/-)\n";
  cin >> f;
  }
  return 0;
}
