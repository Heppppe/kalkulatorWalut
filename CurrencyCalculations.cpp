#include "menu.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "api.h"
#include "JSON.h"
#include <cctype>


#define KEY_LEFT 1
#define KEY_RIGHT 2

void calculateCurrency() {
    bool calculating = true;
    bool misinput = false;
    bool invalidAmount = false;
    int selected = 1;
    string amount = "1";
    string currency = "PLN";
    string secondCurrency = "EUR";

    while (calculating) {
        system("cls");

        transform(currency.begin(), currency.end(), currency.begin(), [](unsigned char c) { return std::toupper(c); });
        transform(secondCurrency.begin(), secondCurrency.end(), secondCurrency.begin(), [](unsigned char c) { return std::toupper(c); });
        calculateUI(selected, amount, currency, secondCurrency);

        if (misinput) {
            cout << "\nNieprawid³owa waluta lub brak kursu." << endl;
            misinput = false;
        }
        if (invalidAmount) {
            cout << "\nPodano niepoprawn¹ kwotê." << endl;
            invalidAmount = false;
        }

        char input = _getch();
        char side;
        switch (selected) {
        case 4:
            switch (input) {
            case 'à':
                side = _getch();
                if (side == 75)
                    selected = 3;
                break;
            case '\b':
                if (secondCurrency.size() > 0)
                    secondCurrency.pop_back();
                break;
            default:
                if (secondCurrency.size() < 5)
                    secondCurrency += input;
            }
            break;
        case 3:
            switch (input) {
            case 'à':
                side = _getch();
                if (side == 77)
                    selected = 4;
                if (side == 75)
                    selected = 2;
                break;
            default:
                if (all_of(amount.begin(), amount.end(), ::isdigit)) {
                    int result = policzButton(stod(amount), currency, secondCurrency);
                    if (result == -1) {
                        misinput = true;
                    }
                    else if (result == 1) {
                        calculating = false;
                    }
                }
                else {
                    invalidAmount = true;
                }
            }
            break;
        case 2:
            switch (input) {
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
                if (currency.size() < 5)
                    currency += input;
            }
            break;
        case 1:
            switch (input) {
            case 'à':
                side = _getch();
                if (side == 77)
                    selected = 2;
                break;
            case '\b':
                if (amount.size() > 0)
                    amount.pop_back();
                break;
            default:
                if (amount.size() < 9 && (isdigit(input) || input == '.'))
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

int policzButton(double amount, string currency, string secondCurrency)
{
    double rate1 = apiobj.getJSONParser().getRate(currency);  // Pobiera kurs waluty
    double rate2 = apiobj.getJSONParser().getRate(secondCurrency);  // Pobiera kurs waluty docelowej
    if (rate1 == 0.0 || rate2 == 0.0) {
        return -1;
    }
    cout << endl << amount << " " << currency << " = " << amount * rate2 / rate1 << ' ' << secondCurrency << endl << endl;

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