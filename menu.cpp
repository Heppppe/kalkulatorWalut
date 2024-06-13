#include "menu.h"
#include <conio.h>
#include <iostream>
#include "api.h"

using namespace std;

// Deklaracja zewn�trzna globalnego obiektu API
extern API api;

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
            cout << endl << "Nieprawidlowa opcja";  // Informuje o nieprawid�owej opcji
            misinput = false;
        }

        char ch = _getch();  // Pobiera znak od u�ytkownika

        switch (ch) {
        case '1': {
            // Przeliczanie pieni�dzy
            string currency;
            double amount;
            cout << "Podaj walut� (np. USD, EUR): ";
            cin >> currency;  // Pobiera walut� od u�ytkownika
            cout << "Podaj kwot�: ";
            cin >> amount;  // Pobiera kwot� od u�ytkownika
            double rate = api.getJSONParser().getRate(currency);  // Pobiera kurs waluty
            if (rate != 0.0) {
                cout << "Przeliczona kwota: " << (amount * rate) << endl;  // Wy�wietla przeliczon� kwot�
            }
            else {
                cout << "Nieprawid�owa waluta lub brak kursu." << endl;  // Informuje o b��dnej walucie lub braku kursu
            }
            system("pause");  // Pauza przed wyczyszczeniem konsoli
            break;
        }
        case '2': {
            // Wy�wietl wszystkie kursy
            api.getJSONParser().displayRates();  // Wy�wietla kursy walut
            system("pause");  // Pauza przed wyczyszczeniem konsoli
            break;
        }
        case '3': {
            // Wy�wietl instrukcj�
            cout << "Instrukcja u�ytkownika..." << endl;  // Wy�wietla instrukcj�
            system("pause");  // Pauza przed wyczyszczeniem konsoli
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