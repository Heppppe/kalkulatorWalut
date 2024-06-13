#include <iostream>
#include <string>
#include <locale.h>
#include "API.h"
#include "menu.h"

using namespace std;

// Definicja globalnego obiektu API
API apiobj("13c8bdeb1c144ec3b3f4422ab3a04f9a");

int main() {
    setlocale(LC_CTYPE, "Polish");  // Pozwala wy�wietla� polskie znaki w konsoli

    cout << "Pobieranie aktualnych kurs�w..." << endl;

    if (apiobj.fetchRates()) {  // Pobiera kursy walut i sprawdza powodzenie operacji
        menuLoop();  // Przej�cie do menu
    }
    else {
        cout << "Wyst�pi� b��d przy pobieraniu." << endl;  // Informuje o b��dzie podczas pobierania
    }

    return 0;
}