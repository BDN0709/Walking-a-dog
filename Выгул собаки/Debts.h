#pragma once
using namespace std;

struct Date
{

private:

	unsigned int Second;
	unsigned int Minute;
	unsigned int Hour;
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;

public:

	Date()
	{
		SYSTEMTIME lt;

		GetLocalTime(&lt);

		Second = lt.wSecond;
		Minute = lt.wMinute;
		Hour = lt.wHour;
		Day = lt.wDay;
		Month = lt.wMonth;
		Year = lt.wYear;

	}

	unsigned int wSecond()
	{
		return Second;
	}
	unsigned int wMinute()
	{
		return Minute;
	}
	unsigned int wHour()
	{
		return Hour;
	}
	unsigned int wDay()
	{
		return Day;
	}
	unsigned int wMonth()
	{
		return Month;
	}
	unsigned int wYear()
	{
		return Year;
	}

};

class Debt
{

private:

	string description;
	string name;
	Date date;

	void getDescription()
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Введите описание долга: ";
		getline(cin, description);
	}

	void getName()
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Введите название долга: ";
		getline(cin, name);
	}

public:

	bool Add();

	void Delete()
	{

	}

	string Name()
	{
		return name;
	}

	string Description()
	{
		return description;
	}

	Date Date()
	{
		return date;
	}

};

#include "ProtFunc.h"

bool Debt::Add()
{
	getName();

	system("cls");

	shared_ptr <double> ans(new double);

	cout << "0 - Отменить действие и вернуться в главное меню." << endl;
	cout << "1 - Воздержаться от комментариев." << endl;
	cout << "2 - Ввести описание долга." << endl;

	cout << "Ваш выбор: ";
	cin >> *ans;

	while (!cin || *ans != int(*ans) || *ans < 0 || *ans > 2)
	{
		if (!cin)
		{
			MsgBox("Ошибка!", "Пункт меню не может быть задан строкой!");
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (*ans != int(*ans))
			MsgBox("Ошибка!", "Пункт меню не может быть нецелым числом!");

		else if (*ans < 0 || *ans > 2)
			MsgBox("Ошибка!", "Выбран несуществующий пункт меню!");


		cout << "0 - Отменить действие и вернуться в главное меню." << endl;
		cout << "1 - Воздержаться от комментариев." << endl;
		cout << "2 - Ввести описание долга." << endl;

		cout << "Ваш выбор: ";
		cin >> *ans;
	}

	switch (int(*ans))
	{
		case 0: return false; break;
		case 1:
		{
			system("cls");

			cout << "Вы уверены? Возможно, в будущем этот комментарий поможет отстоять свою позицию." << endl;
			cout << "1 - Воздержаться от комментариев." << endl;
			cout << "2 - Ввести описание долга." << endl;

			cout << "Ваш окончательный выбор: ";
			cin >> *ans;
			while (!cin || *ans != int(*ans) || *ans < 1 || *ans > 2)
			{
				if (!cin)
				{
					MsgBox("Ошибка!", "Пункт меню не может быть задан строкой!");
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else if (*ans != int(*ans))
					MsgBox("Ошибка!", "Пункт меню не может быть нецелым числом!");

				else if (*ans < 1 || *ans > 2)
					MsgBox("Ошибка!", "Выбран несуществующий пункт меню!");


				cout << "Вы уверены? Возможно, в будущем этот комментарий поможет отстоять свою позицию." << endl;
				cout << "1 - Воздержаться от комментариев." << endl;
				cout << "2 - Ввести описание долга." << endl;

				cout << "Ваш окончательный выбор: ";
				cin >> *ans;
			}

			if (*ans == 1)
				break;
			else
				getDescription();

		} break;

		case 2: getDescription(); break;
	}
	system("cls");
	cout << "Долг успешно добавлен!" << endl;
	system("pause");
	return true;
}