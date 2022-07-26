#pragma once

#include <vector>
#include "Debts.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

enum Walker
{
	Eva, Timur
};

int Menu(vector <Debt>& Tims, vector <Debt>& Eves)
{
	while (true)
	{
		system("cls");

		ShowTime();
		ShowWhoseDay(Eva);

		cout << endl << "1 - ������������� ���� ������." << endl;
		cout << "2 - ������������� ���� ���." << endl;
		cout << "3 - ���� ���� ������ �����������." << endl;
		cout << "4 - ���� ���� ��� �����������." << endl;
		cout << "5 - ���������� ������ ������ ������" << endl;
		cout << "6 - ���������� ������ ������ ���." << endl;
		cout << "0 - ��������� ��������� � ������� ���������." << endl;

		shared_ptr <double> answer(new double);
		cin >> *answer;

		while (!cin || *answer != int(*answer) || *answer < 0 || *answer > 6)
		{
			if (!cin)
			{
				MsgBox("������!", "����� ���� �� ����� ���� ����� �������!");
				cin.clear();
				cin.ignore(32767, '\n');
				return -1;
			}
			else if (*answer != int(*answer))
			{
				MsgBox("������!", "����� ���� �� ����� ���� ������� ������!");
				return -1;
			}
			else if (*answer < 0 || *answer > 6)
			{
				MsgBox("������!", "������ �������������� ����� ����!");
				return -1;
			}
		}

		switch ((int)*answer)
		{
		case 0: return 0; break;
		case 1: AddDebt(Tims); break;
		case 2: AddDebt(Eves); break;
		case 3: DeleteDebt(Tims, Timur); break;
		case 4: DeleteDebt(Eves, Eva); break;
		case 5: ShowDebtsList(Tims, Timur); break;
		case 6: ShowDebtsList(Eves, Eva); break;
		}
	}
}

void AddDebt(vector <Debt>& whoose)
{
	shared_ptr <Debt> debt (new Debt);

	if (!debt->Add())
		return;
	else
		whoose.push_back(*debt);
	
	return;
}

void DeleteDebt(vector <Debt>& whoose, const Walker& walker)
{
	system("cls");

	if (whoose.empty())
	{
		if (walker == Timur)
			cout << "� ������ ��� ������, ��������� ��� ��������!" << endl << endl;
		else
			cout << "� ��� ��� ������, ��������� ��� ��������!" << endl << endl;

		system("pause");

		return;
	}
	
	shared_ptr <double> ans (new double);

	cout << "0 - �������� �������� � ��������� � ������� ����." << endl;
	cout << "1 - ������� ���� �� ������." << endl;

	cout << "��� �����: ";
	cin >> *ans;

	while (!cin || *ans != int(*ans) || *ans < 0 || *ans > 1)
	{
		if (!cin)
		{
			MsgBox("������!", "����� ���� �� ����� ���� ����� �������!");
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (*ans != int(*ans))
			MsgBox("������!", "����� ���� �� ����� ���� ������� ������!");

		else if (*ans < 0 || *ans > 1)
			MsgBox("������!", "������ �������������� ����� ����!");


		cout << "0 - �������� �������� � ��������� � ������� ����." << endl;
		cout << "1 - ������� ���� �� ������." << endl;

		cout << "��� �����: ";
		cin >> *ans;
	}

	if (*ans == 0)
		return;
	else
	{
		system("cls");

		ShowDebtsList(whoose, walker);

		if (walker == Timur)
			cout << "������� ����� ����� ������, ������� ���������� �������: ";
		else
			cout << "������� ����� ����� ���, ������� ���������� �������: ";

		cin >> *ans;

		while (!cin || *ans != int(*ans) || *ans < 1 || *ans > whoose.size())
		{
			if (!cin)
			{
				MsgBox("������!", "����� ����� �� ����� ���� ����� �������!");
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else if (*ans != int(*ans))
				MsgBox("������!", "����� ����� �� ����� ���� ������� ������!");

			else if (*ans < 1 || *ans > whoose.size())
				MsgBox("������!", "����� �������������� ����� �����!");


			if (walker == Timur)
				cout << "������� ����� ����� ������, ������� ���������� �������: ";
			else
				cout << "������� ����� ����� ���, ������� ���������� �������: ";

			cin >> *ans;
		}

		whoose.erase(whoose.begin() + ((*ans) - 1));

		system("cls");
		
		if (walker == Timur)
			cout << "���� ������ �" << *ans << " ��� ������� �����!" << endl << endl;
		else
			cout << "���� ��� �" << *ans << " ��� ������� �����!" << endl << endl;

		system("pause");
	}

	return;
}

void ShowDebtsList(vector <Debt>& whoose, const Walker& walker)
{
	system("cls");

	if (walker == Timur)
	{
		if (whoose.size())
			cout << "������ ������ ������:" << endl;
		else
			cout << "� ������ ��� ������!" << endl << endl;
	}
	else
	{
		if (whoose.size())
			cout << "������ ������ ���:" << endl;
		else
			cout << "� ��� ��� ������!" << endl << endl;
	}

	for (int i = 0; i < whoose.size(); i++)
	{
		cout << endl;
		

		for (int j = 0; j < 36; j++)
		{
			if (j == 18)
				cout << "�" << i + 1;

			cout << "--";
		}
		cout << endl;

		cout << "��������: " << whoose.at(i).Name() << endl;
		
		cout << "��������: "; printf("%02d.%02d.%04d � %02d:%02d:%02d\n", whoose.at(i).Date().wDay(), whoose.at(i).Date().wMonth(),
			whoose.at(i).Date().wYear(), whoose.at(i).Date().wHour(), whoose.at(i).Date().wMinute(), whoose.at(i).Date().wSecond());
		
		cout << "��������: " << whoose.at(i).Description() << endl << endl;
	}

	system("pause");

	return;
}

void ShowTime()
{   // gets real time and displays it
	shared_ptr <SYSTEMTIME> lt (new SYSTEMTIME);

	GetLocalTime(&(*lt));

	printf("�������: %02d.%02d.%04d\n", lt->wDay, lt->wMonth, lt->wYear);
	printf("������:  %02d:%02d:%02d\n", lt->wHour, lt->wMinute, lt->wSecond);

	return;
}

void ShowWhoseDay(const Walker& walker)
{
	wchar_t Title[100];
	GetConsoleTitle(Title, 100);

	HWND hwnd;
	hwnd = FindWindow(NULL, Title);

	HDC hdc = GetDC(hwnd);  // �������� �������� ��� ���������

	HFONT p1, p2 = CreateFont(50, 20, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Sobaka");

	p1 = (HFONT)SelectObject(hdc, p2);

	if (walker == Eva)
		TextOut(hdc, 550, 5, L"���� ���", 8);  // ������ �����
	else
		TextOut(hdc, 550, 5, L"���� ������", 11);  // ������ �����

	SelectObject(hdc, p1);  // ���������� ������ ��������
	ReleaseDC(hwnd, hdc);   // ����������� �������� ���������
	DeleteObject(p2);       // ������� ��������� ����

	return;
}

void MsgBox(const char* Name, const char* Text)
{
	system("cls");

	wchar_t Title[100];
	GetConsoleTitle(Title, 100);

	HWND hwnd;
	hwnd = FindWindow(NULL, Title);

	MessageBoxA(hwnd, Text, Name, NULL);

	return;
}