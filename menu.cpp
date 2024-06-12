#include "menu.h"
#include <conio.h>			//posiada funkcjê _getch(), która bierze podany znak od u¿ytkownika

void displayMenu()
{
	cout << "Wybierz (1-4):" << endl;
	cout << "1 Przelicz iloœæ pieniêdzy" << endl;
	cout << "2 Wyœwietl wszystkie kursy" << endl;
	cout << "3 Wyœwietl instrukcjê" << endl;
	cout << "4 WyjdŸ z programu" << endl;
}

void menuLoop()
{
	bool inMenu = true;				//gdy inMenu zmieni sie na false, to wyjdz z menu
	bool misinput = false;			//gdy misinput zmieni sie na true, wyswietli sie tekst o zle wprowadzonym znaku
	while (inMenu)
	{
		system("cls");							//czyœci konsole
		displayMenu();
		if (misinput)
		{
			cout << endl << "Nieprawidlowa opcja";
			misinput = false;
		}

		char ch = _getch();

		switch (ch)
		{
		case '1':
			//przeliczaniePieniedzy()
			break;
		case '2':
			//wyswietlKursy()
			break;
		case '3':
			//wyswietlInstrukcje()
			break;
		case '4':
			inMenu = false;
			break;
		default:
			misinput = true;
		}
	}
}