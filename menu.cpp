#include "menu.h"
#include <conio.h>
#include <iostream>
#include "api.h"

using namespace std;

// Deklaracja zewnêtrzna globalnego obiektu API
extern API api;

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
            cout << endl << "Nieprawidlowa opcja";  // Informuje o nieprawid³owej opcji
            misinput = false;
        }

        char ch = _getch();  // Pobiera znak od u¿ytkownika

        switch (ch) {
        case '1': {
            // Przeliczanie pieniêdzy
            string currency;
            double amount;
            cout << "Podaj walutê (np. USD, EUR): ";
            cin >> currency;  // Pobiera walutê od u¿ytkownika
            cout << "Podaj kwotê: ";
            cin >> amount;  // Pobiera kwotê od u¿ytkownika
            double rate = api.getJSONParser().getRate(currency);  // Pobiera kurs waluty
            if (rate != 0.0) {
                cout << "Przeliczona kwota: " << (amount * rate) << endl;  // Wyœwietla przeliczon¹ kwotê
            }
            else {
                cout << "Nieprawid³owa waluta lub brak kursu." << endl;  // Informuje o b³êdnej walucie lub braku kursu
            }
            system("pause");  // Pauza przed wyczyszczeniem konsoli
            break;
        }
        case '2': {
            // Wyœwietl wszystkie kursy
            api.getJSONParser().displayRates();  // Wyœwietla kursy walut
            system("pause");  // Pauza przed wyczyszczeniem konsoli
            break;
        }
        case '3': {
            // Wyœwietl instrukcjê
            cout << "Instrukcja u¿ytkownika..." << endl;  // Wyœwietla instrukcjê
            system("pause");  // Pauza przed wyczyszczeniem konsoli
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