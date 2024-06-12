#include <iostream>
#include <string>
#include "api.h"

using namespace std;


int main() {
    string apiKey = "13c8bdeb1c144ec3b3f4422ab3a04f9a";             //podawanie APIkey
    API objapi(apiKey);                                             //stworzenie obiektu do przechwycenia danych

    if (objapi.fetchRates()) {                                      //sprawdzenie po³¹czenia
        cout << "Response data: " << objapi.getResponse() << endl;  //wypisanie danych
    }
    else {
        cout << "Failed to fetch exchange rates." << endl;          //wypisanie b³êdu
    }

    return 0;
}