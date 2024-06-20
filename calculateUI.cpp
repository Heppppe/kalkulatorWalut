#include "menu.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "api.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void calculateUI(int option, string amount, string currency, string secondCurrency)
{
    cout << endl;
    switch (option)
    {
        // bez zaznaczenia
    case 0:
        cout << string(3, ' ') << "kwota:" << string(3, ' ') << string(3, ' ') << "waluta:" << string(14, ' ') << "docelowa waluta:" << endl;
        cout << string(3, ' ') << string(11, '-') << string(3, ' ') << string(7, '-') << string(3, ' ') << string(8, '-') << string(3, ' ') << string(16, '-') << endl;
        cout << string(3, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|' << string(3, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|' << string(3, ' ') << "|Policz|" << string(3, ' ') << '|' << string(16 - secondCurrency.size(), ' ') << secondCurrency << '|' << endl;
        cout << string(3, ' ') << string(11, '-') << string(3, ' ') << string(7, '-') << string(3, ' ') << string(8, '-') << string(3, ' ') << string(16, '-') << endl;
        break;

        // 1 opcja na niebiesko
    case 1:
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << "kwota:";
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(8, ' ') << "waluta:";
        cout << string(14, ' ') << "docelowa waluta:" << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(7, '-') << string(3, ' ') << string(8, '-') << string(3, ' ') << string(16, '-') << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|';
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|' << string(3, ' ') << "|Policz|" << string(3, ' ') << '|' << string(14 - secondCurrency.size(), ' ') << secondCurrency << '|' << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(7, '-') << string(3, ' ') << string(8, '-') << string(3, ' ') << string(16, '-') << endl;
        break;

        // 2 opcja na niebiesko
    case 2:
        cout << string(3, ' ') << "kwota:";
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(8, ' ') << "waluta:";
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(14, ' ') << "docelowa waluta:" << endl;
        cout << string(3, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(8, '-') << string(3, ' ') << string(16, '-') << endl;
        cout << string(3, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|';
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|';
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << "|Policz|" << string(3, ' ') << '|' << string(14 - secondCurrency.size(), ' ') << secondCurrency << '|' << endl;
        cout << string(3, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(8, '-') << string(3, ' ') << string(16, '-') << endl;
        break;
        // 3 opcja na niebiesko
    case 3:
        cout << string(3, ' ') << "kwota:" << string(8, ' ') << "waluta:" << string(14, ' ') << "docelowa waluta:" << endl;
        cout << string(3, ' ') << string(11, '-') << string(3, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << string(8, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(16, '-') << endl;
        cout << string(3, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|' << string(3, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|';
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << "|Policz|";
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << '|' << string(14 - secondCurrency.size(), ' ') << secondCurrency << '|' << endl;
        cout << string(3, ' ') << string(11, '-') << string(3, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(3, ' ') << string(8, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(16, '-') << endl;
        break;
        // 4 na niebiesko
    case 4:
        cout << string(3, ' ') << "kwota:" << string(8, ' ') << "waluta:" << string(14, ' '); 
        SetConsoleTextAttribute(hConsole, 11);
        cout << "docelowa waluta:" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(11, '-') << string(3, ' ') << string(7, '-') << string(3, ' ') << string(8, '-') << string(3, ' ');
        SetConsoleTextAttribute(hConsole, 11); 
        cout << string(16, '-') << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|' << string(3, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|' << string(3, ' ') << "|Policz|" << string(3, ' ');
        SetConsoleTextAttribute(hConsole, 11); 
        cout << '|' << string(14 - secondCurrency.size(), ' ') << secondCurrency << '|' << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(3, ' ') << string(11, '-') << string(3, ' ') << string(7, '-') << string(3, ' ') << string(8, '-') << string(3, ' ');
        SetConsoleTextAttribute(hConsole, 11); 
        cout << string(16, '-') << endl;
        SetConsoleTextAttribute(hConsole, 15);
        break;
    }

}