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

	wchar_t Title[100];
	GetConsoleTitle(Title, 100);
	HWND hwnd = FindWindow(NULL, Title);

	HANDLE HAND = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 25, 90 };
	SetConsoleScreenBufferSize(HAND, bufferSize);

	vector <Debt> Tims, Eves;

	string pathTim = "D:/Walking a PSINA/Timur.txt", pathEve = "D:/Walking a PSINA/Eva.txt";

	fstream ifsTim, ifsEve, ofsTim, ofsEve;

	try
	{
		ifsTim.open(pathTim, ifstream::in);
		ifsEve.open(pathEve, ifstream::in);

		if (!ifsTim.is_open() || !ifsEve.is_open())
			throw exception();
	}
	catch (const exception& ex)
	{
		MsgBox("КРИТИЧЕСКАЯ ОШИБКА!", "Возникла критическая ошибка на этапе открытия файлов!");

		cout << "Код ошибки: " << ex.what() << endl;
		cout << "Скорее всего, необходимые для работы программы файлы больше не существуют." << endl;

		return -2;
	}

	Debt debt;

	while (ifsTim.read((char*)&debt, sizeof(Debt)))
		Tims.push_back(debt);

	ifsTim.close();

	while (ifsEve.read((char*)&debt, sizeof(Debt)))
		Eves.push_back(debt);

	ifsEve.close();

	while (Menu(Tims, Eves) != 0);

	ofsTim.open(pathTim, ofstream::out);
	for (int i = 0; i < Tims.size(); i++)
		ofsTim.write((char*)&(Tims.at(i)), sizeof(Debt));
	ofsTim.close();


	ofsEve.open(pathEve, ofstream::out);
	for (int i = 0; i < Eves.size(); i++)
		ofsEve.write((char*)&(Eves.at(i)), sizeof(Debt));
	ofsEve.close();

	MsgBox("Спасибо!", "Благодарю за использование!");

	CloseWindow(hwnd);

	return 0;
}