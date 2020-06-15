#include <iostream>
#include <cmath>

using namespace std;

void Prog()
{
  int i;
  double x, dx;
  double a[21], b[21], c[21], d[21], U[21], V[21];

  for (i = 2; i <= 20; i++)
  {
    a[i] = i + 22;
  }
  for (i = 1; i <= 20; i++)
  {
    b[i] = pow(-1, i+22);
    d[i] = 22 - i;
  }
  for (i = 1; i <= 19; i++)
  {
    c[i] = pow(-i + 22, i+22);
  }

  U[1] = -(c[1]/b[1]);
  V[1] = d[1]/b[1];
  
  for (i = 2; i <= 20; i++)
  {
    U[i] = -(c[i] / (a[i] * U[i-1] + b[i]));
    V[i] = ((d[i] - a[i] * V[i-1]) / (a[i] * V[i-1] + b[i]));  
  }

  dx = (d[20] - a[20] * V[i-1]) / (a[20] * U[19] + b[20]);
  cout << "x[20] = " << dx << endl;

  for (i = 19; i >= 1; i--)
  {
    x = U[i]*dx + V[i];
    
    if (i < 10)
    {
      cout << "x[" << i << "]  = " << x << endl;
    }
    else
    {
      cout << "x[" << i << "] = " << x << endl;
    }

    dx = x;
  }
}

int main()
{
  Prog();
}
