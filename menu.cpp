#include "menu.h"
#include <conio.h>
#include <iostream>
#include "api.h"

using namespace std;

// Deklaracja zewn�trzna globalnego obiektu API

void displayMenu() {
    cout << "Wybierz (1-4):" << endl;
    cout << "1 Przelicz ilo�� pieni�dzy" << endl;
    cout << "2 Wy�wietl wszystkie kursy" << endl;
    cout << "3 Wy�wietl instrukcj�" << endl;
    cout << "4 Wyjd� z programu" << endl;
}

void menuLoop() {
    bool inMenu = true;  // Gdy inMenu zmieni si� na false, wyjd� z menu
    bool misinput = false;  // Gdy misinput zmieni si� na true, wy�wietli si� tekst o �le wprowadzonym znaku
    while (inMenu) {
        system("cls");  // Czy�ci konsol�
        displayMenu();
        if (misinput) {
            cout << endl << "Nieprawid�owa opcja";  // Informuje o nieprawid�owej opcji
            misinput = false;
        }

        char ch = _getch();  // Pobiera znak od u�ytkownika

        switch (ch) {
        case '1': {
            calculateCurrency();
            break;
        }
        case '2': {
            system("cls");
            displayCurrencies();
            break;
        }
        case '3': {
            system("cls");
            displayInstructions();
            break;
        }
        case '4':
            inMenu = false;  // Ustawia flag� zako�czenia p�tli menu
            break;
        default:
            misinput = true;  // Ustawia flag� nieprawid�owego wej�cia
        }
    }
}

void displayInstructions()
{
    cout << "Instrukcja u�ytkownika..." << endl;  // Wy�wietla instrukcj�
    cout << "Wci�nij dowolny przycisk..." << endl;
    _getch();               // Pauza przed wyczyszczeniem konsoli
}