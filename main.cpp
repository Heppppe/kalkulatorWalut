#include <iostream>
#include <string>
#include <locale.h>
#include "API.h"
#include "menu.h"

using namespace std;

// Definicja globalnego obiektu API
API apiobj("13c8bdeb1c144ec3b3f4422ab3a04f9a");

int main() {
    setlocale(LC_CTYPE, "Polish");  // Pozwala wyœwietlaæ polskie znaki w konsoli

    cout << "Pobieranie aktualnych kursów..." << endl;

    if (apiobj.fetchRates()) {  // Pobiera kursy walut i sprawdza powodzenie operacji
        menuLoop();  // Przejœcie do menu
    }
    else {
        cout << "Wyst¹pi³ b³¹d przy pobieraniu." << endl;  // Informuje o b³êdzie podczas pobierania
    }

    return 0;
}