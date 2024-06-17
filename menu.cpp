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
    string instrukcja= "                     \n"
        "                                          Instrukcja u¿ytkownika\n"
        "\n"
        "OPCJA 1\n"
        "Po wybraniu w menu opcji 1 (wciœniêciu klawisza 1) wyœwietli siê kalkulator, który zawiera dwa pola tekstowe oraz przycisk Policz. Pola tekstowe obs³ugiwane s¹ za pomoc¹ klawiatury, pole wybierane jest za pomoc¹ strza³em (lewa lub prawa), obs³uguj¹ one wpisywanie i kasowaæ dane w taki sam sposób jak w ka¿dym edytorze tekstu. W pierwszym polu nale¿y podaæ kwotê(np.100), natomiast w drugim polu skrót waluty z jakiej chcemy przeliczyæ pieni¹dze (np. PLN).\n"
        "Po podaniu danych nale¿y przejechaæ strza³k¹ na przycisk Policz, a program wyœwietli przeliczone kwoty dla PLN, EUR, GBP i USD.\n"
        "Na koniec mo¿emy zdecydowaæ czy chcemy dalej korzystaæ z kalkulatora \n"
        "(po wciœniêciu klawisza „t” bêdziemy mogli ponownie wpisaæ dane, \n"
        "po wciœniêciu „n” zostaniemy przekierowani do menu).\n"
        "\n"
        "OPCJA 2\n"
        "Po wybraniu w menu opcji 2 (wciœniêciu klawisza 2) wyœwietlone zostan¹ wszystkie kurs walut które zosta³y przechwycone z API, aby powróciæ do menu nale¿y wcisn¹æ dowolny klawisz\n"
        "\n"
        "OPCJA 3\n"
        "Po wybraniu w menu opcji 3 (wciœniêciu klawisza 3) wyœwietlona zostanie instukcja u¿ytkowania, aby powróciæ do menu nale¿y wcisn¹æ dowolny klawisz\n"
        "\n"
        "OPCJA 4\n"
        "Po wybraniu w menu opcji 4 (wciœniêciu klawisza 4) aplikacja zostanie wy³¹czona\n\n";
    cout << instrukcja;
    cout << "Wciœnij dowolny przycisk..." << endl;
    _getch();               // Pauza przed wyczyszczeniem konsoli
}

