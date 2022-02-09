#include <iostream>
#include <Windows.h>
#include <time.h>
#include <ctime>
#include <realtimeapiset.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int atTim = 0, atEv = 0;

void Menu(SYSTEMTIME& st, SYSTEMTIME& lt);
void ShowTime(SYSTEMTIME& st, SYSTEMTIME& lt);
void ShowWhoseDay(bool);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SYSTEMTIME st, lt;
	GetSystemTime(&st);
	GetLocalTime(&lt);
	Menu(st, lt);
	return 0;
}

void Menu(SYSTEMTIME& st, SYSTEMTIME& lt)
{
	system("cls");
	ShowTime(st, lt);
	ShowWhoseDay(1);
	do
	{
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
				cout << "Выберите пункт меню от 0 до 6:" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				cin >> answer;
			}
			else if (answer != int(answer))
			{
				cout << "Error: выбран несуществующий пункт меню!" << endl;
				cout << "Выберите пункт меню от 0 до 6:" << endl;
				cin >> answer;
			}
			else if (answer < 0 || answer > 6)
			{
				cout << "Error: выбран несуществующий пункт меню!" << endl;
				cout << "Выберите пункт меню от 0 до 6:" << endl;
				cin >> answer;
			}
		}
		switch ((int)answer)
		{
		case 0: return; break;
		case 1: /*AddDebt(true, lt)*/; break;
		case 2: /*AddDebt(false, lt)*/; break;
		case 3: /*Foo()*/ break;
		case 4: /*Foo()*/ break;
		case 5: /*Foo()*/ break;
		case 6: /*Foo()*/ break;
		}
	} while (true);
}

void ShowTime(SYSTEMTIME& st, SYSTEMTIME& lt)
{
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
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Xyu");
	p1 = (HFONT)SelectObject(hdc, p2);
	if (a)
		TextOut(hdc, 550, 5, L"День Тимура", 11);  // рисуем текст
	else
		TextOut(hdc, 350, 300, L"День Евы", 8);  // рисуем текст
	SelectObject(hdc, p1);  // Возвращаем старое значение
	ReleaseDC(hwnd, hdc);   // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо
}