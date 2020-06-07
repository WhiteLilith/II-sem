#include "stdafx.h"
#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
private:
	const char Dollar = '$';
	long double Value;
	string Ustring;
	int j = 1;
	int t = 1;

	const long double Max = 9999999999999990.00;

public:

	Money(long double a)
	{
		if (a <= Max)
		{
			Value = a;
		}
		else
		{
			cout << "ERROR, too big value";
		}
	}

	string ldtoms()
	{
		string uresult;
		string result;
		uresult = to_string(Value);
		int len = uresult.length();
		for (int i = len - 1; i >= 0; i--)
		{
			if (uresult[i-1] == '.')
			{
				result = uresult[i] + result;
				result = "." + result;
				i--;
				for (j = 1; j <= len - 2; j++)
				{
					while (i > 0)
					{
						i--;
						result = uresult[i] + result;
						if ((j % 3 == 0) && (j < len - 3))
						{
							result = "." + result;
						}
					}
				}
				i = -1;
			}
			else
			{
				result = uresult[i] + result;
				if (i % 3 == 0)
				{
					result = "." + result;
				}
			}

		}
		result = Dollar + result;
		Ustring = result;
		return result;
	}
};

int main()
{
	long double a = 329810492;
	Money mon(a);
	string rez;
	rez = mon.ldtoms();
	cout << rez;

}
