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
		shared_ptr <SYSTEMTIME> lt (new SYSTEMTIME);

		GetLocalTime(&(*lt));

		Second = lt->wSecond;
		Minute = lt->wMinute;
		Hour = lt->wHour;
		Day = lt->wDay;
		Month = lt->wMonth;
		Year = lt->wYear;

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

	char name[120];
	char description[240];
	Date date;

	void getName()
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "������� �������� �����: ";
		cin.getline(name, 120);
	}

	void getDescription()
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "������� �������� �����: ";
		cin.getline(description, 240);
	}

public:

	bool Add();

	void Delete()
	{

	}

	char* Name()
	{
		return name;
	}

	char* Description()
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

	shared_ptr <double> ans (new double);

	cout << "0 - �������� �������� � ��������� � ������� ����." << endl;
	cout << "1 - ������������ �� ������������." << endl;
	cout << "2 - ������ �������� �����." << endl;

	cout << "��� �����: ";
	cin >> *ans;

	while (!cin || *ans != int(*ans) || *ans < 0 || *ans > 2)
	{
		if (!cin)
		{
			MsgBox("������!", "����� ���� �� ����� ���� ����� �������!");
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (*ans != int(*ans))
			MsgBox("������!", "����� ���� �� ����� ���� ������� ������!");

		else if (*ans < 0 || *ans > 2)
			MsgBox("������!", "������ �������������� ����� ����!");


		cout << "0 - �������� �������� � ��������� � ������� ����." << endl;
		cout << "1 - ������������ �� ������������." << endl;
		cout << "2 - ������ �������� �����." << endl;

		cout << "��� �����: ";
		cin >> *ans;
	}

	switch (int(*ans))
	{
		case 0: return false; break;
		case 1:
		{
			system("cls");

			cout << "�� �������? ��������, � ������� ���� ����������� ������� �������� ���� �������." << endl;
			cout << "1 - ������������ �� ������������." << endl;
			cout << "2 - ������ �������� �����." << endl;

			cout << "��� ������������� �����: ";
			cin >> *ans;
			while (!cin || *ans != int(*ans) || *ans < 1 || *ans > 2)
			{
				if (!cin)
				{
					MsgBox("������!", "����� ���� �� ����� ���� ����� �������!");
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else if (*ans != int(*ans))
					MsgBox("������!", "����� ���� �� ����� ���� ������� ������!");

				else if (*ans < 1 || *ans > 2)
					MsgBox("������!", "������ �������������� ����� ����!");


				cout << "�� �������? ��������, � ������� ���� ����������� ������� �������� ���� �������." << endl;
				cout << "1 - ������������ �� ������������." << endl;
				cout << "2 - ������ �������� �����." << endl;

				cout << "��� ������������� �����: ";
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
	cout << "���� ������� ��������!" << endl;
	system("pause");
	return true;
}