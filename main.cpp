#include <iostream>
#include <string>
#include <locale.h>

#include "api.h"
#include "menu.h"

using namespace std;


int main() {

    setlocale(LC_CTYPE, "Polish");                                  //Pozwala wyœwietlaæ polskie znaki w konsoli

    cout << "Pobieranie aktualnych kursów..."<<endl;

    string apiKey = "13c8bdeb1c144ec3b3f4422ab3a04f9a";             //podawanie APIkey
    API objapi(apiKey);                                             //stworzenie obiektu do przechwycenia danych

    if (objapi.fetchRates()) {                                      //sprawdzenie po³¹czenia
        //cout << "Response data: " << objapi.getResponse() << endl;  //wypisanie danych
        menuLoop();                                                 //Przejœcie do menu
    }
    else {
        cout << "Wyst¹pi³ b³¹d przy pobieraniu." << endl;          //wypisanie b³êdu
    }

    return 0;
}