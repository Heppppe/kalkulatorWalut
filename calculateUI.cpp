#include "menu.h"
#include <conio.h>
#include <string>
#include <iostream>
#include "api.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void calculateUI(int option, string amount, string currency)
{
    cout << endl;
    switch (option)
    {
        // bez zaznaczenia
    case 0:
        cout << string(5, ' ') << "kwota:" << string(5, ' ') << string(5, ' ') << "waluta:" << endl;
        cout << string(5, ' ') << string(11, '-') << string(5, ' ') << string(7, '-') << string(5, ' ') << string(8, '-') << endl;
        cout << string(5, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|' << string(5 - currency.size(), ' ') << currency << '|' << string(5, ' ') << '|' << string(5, ' ') << "|Policz|" << endl;
        cout << string(5, ' ') << string(11, '-') << string(5, ' ') << string(7, '-') << string(5, ' ') << string(8, '-') << endl;
        break;

        // 1 opcja na niebiesko
    case 1:
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << "kwota:";
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(5, ' ') << "waluta:" << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(7, '-') << string(5, ' ') << string(8, '-') << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|';
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|' << string(5, ' ') << "|Policz|" << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(7, '-') << string(5, ' ') << string(8, '-') << endl;
        break;

        // 2 opcja na niebiesko
    case 2:
        cout << string(5, ' ') << "kwota:";
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(5, ' ') << "waluta:" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(8, '-') << endl;
        cout << string(5, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|';
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|';
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << "|Policz|" << endl;
        cout << string(5, ' ') << string(11, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(8, '-') << endl;
        break;
        // 3 opcja na niebiesko
    case 3:
        cout << string(5, ' ') << "kwota:" << string(5, ' ') << string(5, ' ') << "waluta:" << endl;
        cout << string(5, ' ') << string(11, '-') << string(5, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(8, '-') << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << '|' << string(9 - amount.size(), ' ') << amount << '|' << string(5, ' ') << '|' << string(5 - currency.size(), ' ') << currency << '|';
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << "|Policz|" << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout << string(5, ' ') << string(11, '-') << string(5, ' ') << string(7, '-');
        SetConsoleTextAttribute(hConsole, 11);
        cout << string(5, ' ') << string(8, '-') << endl;
        SetConsoleTextAttribute(hConsole, 15);
        break;
    }
}