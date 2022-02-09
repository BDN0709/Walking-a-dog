#include <iostream>
#include <Windows.h>
#include <time.h>
#include <ctime>
#include <vector>
#include <string>
#include <realtimeapiset.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int atTim = 0, atEv = 0;

void Menu(SYSTEMTIME&, SYSTEMTIME&);
void ShowTime(SYSTEMTIME&, SYSTEMTIME&);
void ShowWhoseDay(bool);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"Выгул Ларча");

	SYSTEMTIME st, lt;
	Menu(st, lt);

	return 0;
}

void Menu(SYSTEMTIME& st, SYSTEMTIME& lt)
{
	while (true)
	{
		system("cls");

		ShowTime(st, lt);
		ShowWhoseDay(1);

		double answer;
		cout << endl;
		cout << "1 - Зафиксировать долг Тимура." << endl;
		cout << "2 - Зафиксировать долг Евы." << endl;
		cout << "3 - Дать шанс Тимуру исправиться." << endl;
		cout << "4 - Дать шанс Еве исправиться." << endl;
		cout << "5 - Посмотреть список долгов Тимура" << endl;
		cout << "6 - Посмотреть список долгов Евы." << endl;
		cout << "0 - Сохранить изменения и закрыть программу." << endl;

		cin >> answer;
		while (!cin || answer != int(answer) || answer < 0 || answer > 6)
		{
			if (!cin)
			{
				cout << "Error: ответ не может быть строкой!" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else if (answer != int(answer))
				cout << "Error: пункт меню не может быть нецелым числом!" << endl;
			else if (answer < 0 || answer > 6)
				cout << "Error: выбран несуществующий пункт меню!" << endl;


			cout << "Выберите пункт меню от 0 до 6:" << endl;
			cin >> answer;
		}

		switch ((int)answer)
		{
		case 0: 
		{
			system("cls");
			HWND hwnd;
			wchar_t Title[1024];
			GetConsoleTitle(Title, 1024);
			hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
			MessageBox(hwnd, L"Благодарю за использование! =)", L"Спасибо!", NULL);
			return; break;
		}
		case 1: /*AddDebt(true, lt)*/; break;
		case 2: /*AddDebt(false, lt)*/; break;
		case 3: /*Foo()*/ break;
		case 4: /*Foo()*/ break;
		case 5: /*Foo()*/ break;
		case 6: /*Foo()*/ break;
		}
	}
}

void ShowTime(SYSTEMTIME& st, SYSTEMTIME& lt)
{
	GetSystemTime(&st);
	GetLocalTime(&lt);

	printf("Сегодня: %02d.%02d.%04d\n", lt.wDay, lt.wMonth, lt.wYear);
	printf("Сейчас:  %02d:%02d:%02d\n", lt.wHour, lt.wMinute, lt.wSecond);
}

void ShowWhoseDay(bool a)
{  // не трогать то, за что не шаришь
	HWND hwnd;
	wchar_t Title[1024];
	GetConsoleTitle(Title, 1024); // Узнаем имя окна   // или GetModuleFileName(NULL,Title, sizeof(Title));
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	HDC hdc = GetDC(hwnd);  // Получаем контекст для рисования
	HFONT p1, p2 = CreateFont(50, 20, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Sobaka");
	p1 = (HFONT)SelectObject(hdc, p2);
	if (a)
		TextOut(hdc, 550, 5, L"День Тимура", 11);  // рисуем текст
	else
		TextOut(hdc, 550, 5, L"День Евы", 8);  // рисуем текст
	SelectObject(hdc, p1);  // Возвращаем старое значение
	ReleaseDC(hwnd, hdc);   // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо
}