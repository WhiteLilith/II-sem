#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int compstr(char* str1, char* str2)
{
	if (strlen(str1) > strlen(str2))
	{
		return 1;
	}
	else if (strlen(str1) > strlen(str2))
	{
		return -1;
	}

	int *len = new int(strlen(str1));
	int* i = new int(0);

	int* app1 = new int(0);
	int* app2 = new int(0);

	for (*i = 0; *i < *len; *i++)
	{
		if ((int)*(str1 + *app1) >(int)*(str2 + *app2))
		{
			return -1;
		}
		else if ((int)*(str1 + *app1) < (int)*(str2 + *app2))
		{
			return 1;
		}

		*app1 += 1;
		*app2 += 1;

	}

	return 0;
}


int main()
{
	char string_1[] = "New York";
	char string_2[] = "Nrw York";
	char string_3[] = "New York";

	cout << compstr(string_1, string_2) << endl;
	cout << compstr(string_2, string_3) << endl;
	cout << compstr(string_1, string_3) << endl;
}
