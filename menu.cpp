#include "menu.h"
#include <conio.h>
#include <iostream>
#include "api.h"

using namespace std;

// Deklaracja zewnêtrzna globalnego obiektu API

void displayMenu() {
    cout << "Wybierz (1-4):" << endl;
    cout << "1 Przelicz iloœæ pieniêdzy" << endl;
    cout << "2 Wyœwietl wszystkie kursy" << endl;
    cout << "3 Wyœwietl instrukcjê" << endl;
    cout << "4 WyjdŸ z programu" << endl;
}

void menuLoop() {
    bool inMenu = true;  // Gdy inMenu zmieni siê na false, wyjdŸ z menu
    bool misinput = false;  // Gdy misinput zmieni siê na true, wyœwietli siê tekst o Ÿle wprowadzonym znaku
    while (inMenu) {
        system("cls");  // Czyœci konsolê
        displayMenu();
        if (misinput) {
            cout << endl << "Nieprawid³owa opcja";  // Informuje o nieprawid³owej opcji
            misinput = false;
        }

        char ch = _getch();  // Pobiera znak od u¿ytkownika

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
            inMenu = false;  // Ustawia flagê zakoñczenia pêtli menu
            break;
        default:
            misinput = true;  // Ustawia flagê nieprawid³owego wejœcia
        }
    }
}

void displayInstructions()
{
    cout << "Instrukcja u¿ytkownika..." << endl;  // Wyœwietla instrukcjê
    cout << "Wciœnij dowolny przycisk..." << endl;
    _getch();               // Pauza przed wyczyszczeniem konsoli
}