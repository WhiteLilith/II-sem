#include <iostream>
#include <cmath>

using namespace std;

void New(double &x, double &y)
{
  double dx, dy, f1, f2, dxf1, dyf1, dxf2, dyf2;
  int i = 1;

  f1 = cos(x+1) - y - 0.5;
  f2 = x + cos(y) - 3;
  dxf1 = -sin(x+1);
  dyf1 = -1;
  dxf2 = 1;
  dyf2 = -sin(y);

  dx = ((-f1) * dyf2 - (-f2) * dyf1) / (dxf1 * dyf2 - dxf2 * dyf1);
  dy = ((-f1) * dxf2 - (-f2) * dxf1) / (dyf1 * dxf2 - dyf2 * dxf1);

  while ((dx > 0.01) || (dy > 0.01))
  {
    x = x + dx;
    y = y + dy;

    f1 = cos(x+1) - y - 0.5;
    f2 = x + cos(y) - 3;
    dxf1 = -sin(x+1);
    dyf1 = -1;
    dxf2 = 1;
    dyf2 = -sin(y);

    cout << "Итерация номер " << i << "   dx = " << dx << ", dy = " << dy << endl;

    dx = ((-f1) * dyf2 - (-f2) * dyf1) / (dxf1 * dyf2 - dxf2 * dyf1);
    dy = ((-f1) * dxf2 - (-f2) * dxf1) / (dyf1 * dxf2 - dyf2 * dxf1);
    i++;
  }
}

int main() 
{
  double x, y;
  cout << "Введите х: ";
  cin >> x;
  cout << "Введите у: ";
  cin >> y;
  New(x,y);
  cout << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
}
