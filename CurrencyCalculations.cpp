#include "menu.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "api.h"
#include "JSON.h"
#include <cctype>

using namespace std;

void calculateCurrency()
{
    bool misinput = false;
    while (true)
    {
        system("cls");
        if (misinput) {
            cout << "Nieprawid³owa waluta lub brak kursu." << endl;
            misinput = false;
        }
        double amount;
        string currency;
        cout << "Wpisz 'm', ¿eby powróciæ do menu" << endl;
        cout << "W jakies walucie masz pieni¹dze? (np. EUR): ";
        cin >> currency;
        if (currency == "m")
            break;

        transform(currency.begin(), currency.end(), currency.begin(),[](unsigned char c) { return std::toupper(c); });
        cout << "Ile pieniêdzy chcesz wymieniæ ? (np. 20) : ";
        cin >> amount;
        double rate = apiobj.getJSONParser().getRate(currency);  // Pobiera kurs waluty
        if (rate == 0.0) {
            misinput = true;
            continue;
        }
        cout << endl << amount << " " << currency << " jest warte: " << endl;
        apiobj.getJSONParser().exchangeToAllCurrencies(amount / rate);
        
        cout << "Wciœnij dowolny przycisk..." << endl;
        _getch();               // Pauza przed wyczyszczeniem konsoli
    }
}

void displayCurrencies()
{
    apiobj.getJSONParser().displayRates();  // Wyœwietla kursy walut
    cout << "Wciœnij dowolny przycisk..." << endl;
    _getch();               // Pauza przed wyczyszczeniem konsoli
}