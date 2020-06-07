#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class String
{
protected:
	enum { c = 80 };
	char str[c];

public:
	String()
	{
		str[0] = '\0';
	}

	String(const char s[])
	{
		strcpy_s(str, s);
	}

	void Display() const
	{
		cout << str;
	}

	operator char* ()
	{
		return str;
	}
};

class Pstring : public String
{
public:
	Pstring(const char s[])
	{
		if (strlen(s) > c - 1)
		{
			int i = 0;
			for (i = 0; i < c - 1; i++)
			{
				str[i] = s[i];
			}
			str[i] = '\0';
		}
		else
		{
			strcpy_s(str, s);
		}
	}
};

class Pstring2 : public Pstring
{

public:
	Pstring2(const char s[]) : Pstring(s)
	{ }

	Pstring2 Left(int num)
	{
		Pstring2 substr = "";
		int i;
		for (i = 0; i < num; i++)
		{
			substr[i] = str[i];
		}
		substr[i] = '\0';
		return substr;
	}

	Pstring2 Right(int num)
	{
		Pstring2 substr = "";
		int i;
		int strend = c;
		for (i = 0; i < c; i++)
		{
			if (str[i] == '\0') strend = i;
		}
		for (i = 0; i < num; i++)
		{
			substr[i] = str[i + strend - num];
		}
		substr[i] = '\0';

		return substr;
	}

	Pstring2 Mid(int pos, int num)
	{
		Pstring2 substr = "";
		int i;
		for (i = 0; i < c - pos && i < num; i++)
			substr[i] = str[i + pos];
		substr[i] = '\0';
		return substr;
	}
};

int main()
{
	Pstring2 str = "Moscow Polytech";

	cout << "left = ";
	str.Left(3).Display();
	cout << endl;

	cout << "right = ";
	str.Right(4).Display();
	cout << endl;

	cout << "mid = ";
	str.Mid(3, 3).Display();
	cout << endl;

	return 0;
}
