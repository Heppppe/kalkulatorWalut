#include <iostream>
#include <string>
#include <locale.h>

#include "api.h"
#include "menu.h"

using namespace std;


int main() {

    setlocale(LC_CTYPE, "Polish");                                  //Pozwala wy�wietla� polskie znaki w konsoli

    cout << "Pobieranie aktualnych kurs�w..."<<endl;

    string apiKey = "13c8bdeb1c144ec3b3f4422ab3a04f9a";             //podawanie APIkey
    API objapi(apiKey);                                             //stworzenie obiektu do przechwycenia danych

    if (objapi.fetchRates()) {                                      //sprawdzenie po��czenia
        //cout << "Response data: " << objapi.getResponse() << endl;  //wypisanie danych
        menuLoop();                                                 //Przej�cie do menu
    }
    else {
        cout << "Wyst�pi� b��d przy pobieraniu." << endl;          //wypisanie b��du
    }

    return 0;
}