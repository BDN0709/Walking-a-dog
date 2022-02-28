#include <iostream>
#include <fstream>
#include <Windows.h>
#include <ctime>
#include "RFunc.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"Выгул Ларча");

	vector <Debt> Eves;
	vector <Debt> Tims;

	SYSTEMTIME lt;

	while (Menu(Tims, Eves, lt) != 0);

	HWND hwnd;
	wchar_t Title[100];
	GetConsoleTitle(Title, 100);
	hwnd = FindWindow(NULL, Title);
	MsgBox("Спасибо!", "Благодарю за использование!");
	CloseWindow(hwnd);

	return 0;
}