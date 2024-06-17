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
    string instrukcja= "                     \n"
        "                                          Instrukcja u�ytkownika\n"
        "\n"
        "OPCJA 1\n"
        "Po wybraniu w menu opcji 1 (wci�ni�ciu klawisza 1) wy�wietli si� kalkulator, kt�ry zawiera dwa pola tekstowe oraz przycisk Policz. Pola tekstowe obs�ugiwane s� za pomoc� klawiatury, pole wybierane jest za pomoc� strza�em (lewa lub prawa), obs�uguj� one wpisywanie i kasowa� dane w taki sam spos�b jak w ka�dym edytorze tekstu. W pierwszym polu nale�y poda� kwot�(np.100), natomiast w drugim polu skr�t waluty z jakiej chcemy przeliczy� pieni�dze (np. PLN).\n"
        "Po podaniu danych nale�y przejecha� strza�k� na przycisk Policz, a program wy�wietli przeliczone kwoty dla PLN, EUR, GBP i USD.\n"
        "Na koniec mo�emy zdecydowa� czy chcemy dalej korzysta� z kalkulatora \n"
        "(po wci�ni�ciu klawisza �t� b�dziemy mogli ponownie wpisa� dane, \n"
        "po wci�ni�ciu �n� zostaniemy przekierowani do menu).\n"
        "\n"
        "OPCJA 2\n"
        "Po wybraniu w menu opcji 2 (wci�ni�ciu klawisza 2) wy�wietlone zostan� wszystkie kurs walut kt�re zosta�y przechwycone z API, aby powr�ci� do menu nale�y wcisn�� dowolny klawisz\n"
        "\n"
        "OPCJA 3\n"
        "Po wybraniu w menu opcji 3 (wci�ni�ciu klawisza 3) wy�wietlona zostanie instukcja u�ytkowania, aby powr�ci� do menu nale�y wcisn�� dowolny klawisz\n"
        "\n"
        "OPCJA 4\n"
        "Po wybraniu w menu opcji 4 (wci�ni�ciu klawisza 4) aplikacja zostanie wy��czona\n\n";
    cout << instrukcja;
    cout << "Wci�nij dowolny przycisk..." << endl;
    _getch();               // Pauza przed wyczyszczeniem konsoli
}

