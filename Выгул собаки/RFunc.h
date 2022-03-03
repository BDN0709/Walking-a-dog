#pragma once

#include <vector>
#include "Debts.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

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

		shared_ptr <double> answer (new double);
		cout << endl;
		cout << "1 - Зафиксировать долг Тимура." << endl;
		cout << "2 - Зафиксировать долг Евы." << endl;
		cout << "3 - Дать шанс Тимуру исправиться." << endl;
		cout << "4 - Дать шанс Еве исправиться." << endl;
		cout << "5 - Посмотреть список долгов Тимура" << endl;
		cout << "6 - Посмотреть список долгов Евы." << endl;
		cout << "0 - Сохранить изменения и закрыть программу." << endl;

		cin >> *answer;

		while (!cin || *answer != int(*answer) || *answer < 0 || *answer > 6)
		{
			if (!cin)
			{
				MsgBox("Ошибка!", "Пункт меню не может быть задан строкой!");
				cin.clear();
				cin.ignore(32767, '\n');
				return -1;
			}
			else if (*answer != int(*answer))
			{
				MsgBox("Ошибка!", "Пункт меню не может быть нецелым числом!");
				return -1;
			}
			else if (*answer < 0 || *answer > 6)
			{
				MsgBox("Ошибка!", "Выбран несуществующий пункт меню!");
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

	shared_ptr <double> ans (new double);

	cout << "0 - Отменить действие и вернуться в главное меню." << endl;
	cout << "1 - Удалить долг по номеру." << endl;

	cout << "Ваш выбор: ";
	cin >> *ans;

	while (!cin || *ans != int(*ans) || *ans < 0 || *ans > 1)
	{
		if (!cin)
		{
			MsgBox("Ошибка!", "Пункт меню не может быть задан строкой!");
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (*ans != int(*ans))
			MsgBox("Ошибка!", "Пункт меню не может быть нецелым числом!");

		else if (*ans < 0 || *ans > 1)
			MsgBox("Ошибка!", "Выбран несуществующий пункт меню!");


		cout << "0 - Отменить действие и вернуться в главное меню." << endl;
		cout << "1 - Удалить долг по номеру." << endl;

		cout << "Ваш выбор: ";
		cin >> *ans;
	}

	if (*ans == 0)
		return;
	else
	{
		system("cls");

		if (walker == Timur)
			cout << "Введите номер долга Тимура, который необходимо удалить: ";
		else
			cout << "Введите номер долга Евы, который необходимо удалить: ";

		cin >> *ans;

		while (!cin || *ans != int(*ans) || *ans < 1 || *ans > whoose.size())
		{
			if (!cin)
			{
				MsgBox("Ошибка!", "Номер долга не может быть задан строкой!");
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else if (*ans != int(*ans))
				MsgBox("Ошибка!", "Номер долга не может быть нецелым числом!");

			else if (*ans < 1 || *ans > whoose.size())
				MsgBox("Ошибка!", "Введён несуществующий номер долга!");


			if (walker == Timur)
				cout << "Введите номер долга Тимура, который необходимо удалить: ";
			else
				cout << "Введите номер долга Евы, который необходимо удалить: ";

			cin >> *ans;
		}

		whoose.erase(whoose.begin() + ((*ans) - 1));

		system("cls");
		
		if (walker == Timur)
			cout << "Долг Тимура №" << *ans << " был успешно удалён!" << endl;
		else
			cout << "Долг Евы №" << *ans << " был успешно удалён!" << endl;

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
			cout << "Список долгов Тимура:" << endl;
		else
			cout << "У Тимура нет долгов!" << endl;
	}
	else
	{
		if (whoose.size())
			cout << "Список долгов Евы:" << endl;
		else
			cout << "У Евы нет долгов!" << endl;
	}

	for (int i = 0; i < whoose.size(); i++)
	{
		Date* date = new Date;
		*date = whoose.at(i).Date();

		cout << endl;
		
		cout << '№' << i + 1 << "-------------" << whoose.at(i).Name() << "---------------" << endl;
		cout << "Добавлен: "; printf("%02d.%02d.%04d в %02d:%02d:%02d\n", date->wDay(), date->wMonth(), date->wYear(),
																	date->wHour(), date->wMinute(), date->wSecond());
		cout << "Описание: " << whoose.at(i).Description() << endl;

		delete date;
	}

	cout << endl;

	system("pause");

	return;
}

void ShowTime()
{   // gets real time and displays it
	shared_ptr <SYSTEMTIME> lt (new SYSTEMTIME);

	GetLocalTime(&(*lt));

	printf("Сегодня: %02d.%02d.%04d\n", lt->wDay, lt->wMonth, lt->wYear);
	printf("Сейчас:  %02d:%02d:%02d\n", lt->wHour, lt->wMinute, lt->wSecond);

	return;
}

void ShowWhoseDay(const Walker& walker)
{  // не трогать то, за что не шаришь
	HWND hwnd;
	wchar_t Title[100];
	GetConsoleTitle(Title, 100); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна

	HDC hdc = GetDC(hwnd);  // Получаем контекст для рисования

	HFONT p1, p2 = CreateFont(50, 20, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Sobaka");

	p1 = (HFONT)SelectObject(hdc, p2);

	if (walker == Eva)
		TextOut(hdc, 550, 5, L"День Евы", 8);  // рисуем текст
	else
		TextOut(hdc, 550, 5, L"День Тимура", 11);  // рисуем текст

	SelectObject(hdc, p1);  // Возвращаем старое значение
	ReleaseDC(hwnd, hdc);   // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо

	return;
}

void MsgBox(const char* Name, const char* Text)
{
	system("cls");
	HWND hwnd;
	wchar_t Title[100];
	GetConsoleTitle(Title, 100);
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	MessageBoxA(hwnd, Text, Name, NULL);

	return;
}