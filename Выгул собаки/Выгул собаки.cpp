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

	vector <Debt> Tims;
	vector <Debt> Eves;

	string pathTim = "Timuraz.txt";
	string pathEve = "Evochkafa.txt";

	ifstream ifsTim, ifsEve;
	ofstream ofsTim, ofsEve;

	try
	{
		ifsTim.open(pathTim, ifstream::in);
		ifsEve.open(pathEve, ifstream::in);
	}
	catch (const exception& ex)
	{
		MsgBox("КРИТИЧЕСКАЯ ОШИБКА!", "Возникла критическая ошибка на этапе открытия файлов!");
		cout << "Код ошибки: " << ex.what() << endl;
		cout << "Скорее всего, у Вас недостаточно прав для выполнения этой операции." << endl;
		return -1;
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

	wchar_t Title[100];
	GetConsoleTitle(Title, 100);
	HWND hwnd = FindWindow(NULL, Title);

	MsgBox("Спасибо!", "Благодарю за использование!");

	CloseWindow(hwnd);

	return 0;
}