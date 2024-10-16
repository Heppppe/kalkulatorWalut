#include <iostream>
#include <string>
#include <locale.h>
#include "API.h"
#include "menu.h"

using namespace std;

// Definicja globalnego obiektu API
API apiobj("Your API key");

int main() {
    setlocale(LC_CTYPE, "Polish");  // Pozwala wyświetlać polskie znaki w konsoli

    cout << "Pobieranie aktualnych kursów..." << endl;
    
    if (apiobj.fetchRates()) {  // Pobiera kursy walut i sprawdza powodzenie operacji
        menuLoop();  // Przejście do menu
    }
    else {
        cout << "Wystąpił błąd przy pobieraniu." << endl;  // Informuje o błędzie podczas pobierania
    }
    
    return 0;
}
