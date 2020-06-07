#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

struct link
{
	int data;
	link* next;
};

class linklist
{
private:
	link* first;

public:
	linklist()
	{
		first = NULL;
	}

	void additem(int d);

	void display();

};

void linklist::additem(int d)
{
	link* newlink = new link;
	newlink->data = d;

	if (first != NULL)
	{
		link* current = first;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newlink;
	}
	else
	{
		first = newlink;
	}

	newlink->next = NULL;
}

void linklist::display()

{
	link* current = first;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}

}

int main()

{
	linklist li;

	li.additem(45);
	li.additem(13);
	li.additem(56);
	li.additem(60);
	li.additem(19);
	li.additem(17);
	li.additem(22);

	li.display();

	return 0;
}
