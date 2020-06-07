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
	linklist(const linklist &ls)
	{
		if (ls.first == NULL)
		{
			return;
		}
		else
		{
			first = new link;
			first->data = ls.first->data;
			link *nw = first;
			link *old = ls.first;
			while (old->next != NULL)
			{
				old = old->next;
				nw->next = new link;
				nw = nw->next;
				nw->data = old->data;
			}
			nw->next = NULL;
		}
	}
	~linklist();
	void additem(int d);
	void display();
	linklist& operator =(const linklist ls)
	{
		*this = linklist(ls);
		return *this;
	}
};

void linklist::additem(int d)
{
	link* newlink = new link;
	newlink->data = d;
	newlink->next = first;
	first = newlink; 
}

void linklist::display()
{
	link* current = first;
	while (current != NULL)
	{
		cout << endl << current->data;
		current = current->next;
	}
}

linklist::~linklist()
{
	link* current = first;
	while (current != NULL)
	{
		link* temp = current;
		cout << "Now deleting: " << current->data << endl;
		current = current->next;
		delete temp;
	}
}
int main()
{
	linklist *d_check = new linklist;
	d_check->additem(10);
	d_check->additem(6);
	d_check->additem(-17);
	d_check->additem(99);
	d_check->display();
	cout << endl;
	linklist s_check = *d_check;
	delete d_check;
	cout << endl;
	s_check.display();
	cout << endl;
	return 0;
}

