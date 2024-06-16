#include "menu.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "api.h"
#include "JSON.h"
#include <cctype>


#define KEY_LEFT 1
#define KEY_RIGHT 2

void calculateCurrency()
{
    bool calculating = true;
    bool misinput = false;
    int selected = 1;
    string amount = "1";
    string currency = "EUR";
    while (calculating)
    {
        system("cls");
        if (misinput) {
            cout << "Nieprawid³owa waluta lub brak kursu." << endl;
            misinput = false;
        }
        transform(currency.begin(), currency.end(), currency.begin(), [](unsigned char c) { return std::toupper(c); });
        calculateUI(selected, amount, currency);


        char input = _getch();
        char side;
        switch (selected)
        {
        case 3:
            switch (input)
            {
            case 'à':
                side = _getch();
                if (side == 75)
                    selected = 2;
                break;
            default:
                misinput = policzButton(stod(amount), currency);
                if (misinput == 1)
                    calculating = false;
            }
            break;
        case 2:
            switch (input)
            {
            case 'à':
                side = _getch();
                if (side == 77)
                    selected = 3;
                if (side == 75)
                    selected = 1;
                break;
            case '\b':
                if (currency.size() > 0)
                    currency.pop_back();
                break;
            default:
                if(currency.size() < 5)
                    currency += input;
            }
            break;
        case 1:
            switch (input)
            {
            case 'à':
                side = _getch();
                if (side == 77)
                    selected = 2;
                break;
            case '\b':
                if(amount.size() > 0)
                    amount.pop_back();
                break;
            default:
                if(amount.size() < 9)
                    amount += input;
            }
            break;
        case 0:
            selected = 1;
            currency = "EUR";
            if (input != 't')
                calculating = false;
        }
    }
}

int policzButton(double amount, string currency)
{
    double rate = apiobj.getJSONParser().getRate(currency);  // Pobiera kurs waluty
    if (rate == 0.0) {
        return -1;
    }
    cout << endl << amount << " " << currency << " jest warte: " << endl;
    apiobj.getJSONParser().exchangeToAllCurrencies(amount / rate);

    cout << "Czy chcesz policzyæ ponownie? (t/n) " << endl;
    char ch = _getch();               // Pauza przed wyczyszczeniem konsoli
    if(ch == 't')
        return 0;
    return 1;
}

void displayCurrencies()
{
    apiobj.getJSONParser().displayRates();  // Wyœwietla kursy walut
    cout << "Wciœnij dowolny przycisk..." << endl;
    _getch();               // Pauza przed wyczyszczeniem konsoli
}