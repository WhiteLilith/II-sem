#include <iostream>
#include <cmath>

using namespace std;

void It(double &x, double &y)
{
  double dx, dy, f1, f2;
  int i = 1;

  f1 = cos(x+1) - 0.5;
  f2 = -cos(y) + 3;
  dx = 100;
  dy = 100;
  x = f2;
  y = f1;

  while ((abs(x-dx) > 0.0001) || (abs(y-dy) > 0.0001))
  {
    dx = x;
    dy = y;

    f1 = cos(x+1) - 0.5;
    f2 = -cos(y) + 3;

    cout << "Итерация №" << i << "..." << endl;
    x = f2;
    y = f1;
    i++;
  }
}

int main()
{
  double x = 0, y = 0;
  It(x, y);
  cout << "x = " << x << ", y = " << y;
}
