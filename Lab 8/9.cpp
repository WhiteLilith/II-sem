#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Publication
{
protected:
	string Name;
	float Price;

public:
	void GetData()
	{
		cout << "Введите название книги: ";
		cin >> Name;

		cout << "Введите цену книги: ";
		cin >> Price;
	}

	void PutData()
	{
		cout << "Название: " << Name << endl;
		cout << "Цена: " << Price << endl;
	}
};


class Publication2 : public Publication
{
protected:
	string Date;

public:
	void GetData1()
	{
		Publication::GetData();
		cout << "Введите дату публикации: ";
		cin >> Date;
	}

	void PutData()
	{
		Publication::PutData();
		cout << "Дата публикации: " << Date << endl;
	}
};

class Book : public Publication2
{
private:
	int Pages;

public:
	void GetData()
	{
		Publication2::GetData1();
		cout << "Введите количество страниц: ";
		cin >> Pages;
	}

	void PutData()
	{
		Publication2::PutData();
		cout << "Страницы: " << Pages;
	}
};


class Type : public Publication2
{
private:
	float Length;

public:
	void GetData()
	{
		Publication2::GetData1();
		cout << "Введите длительность аудиокниги: ";
		cin >> Length;
	}

	void PutData()
	{
		Publication2::PutData();
		cout << "Длительность: " << Length;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Type AudioBook;
	Book PaperBook;

	AudioBook.GetData();
	cout << endl;
	PaperBook.GetData();
	cout << endl;
	AudioBook.PutData();
	cout << endl;
	PaperBook.PutData();

	return 0;
}
