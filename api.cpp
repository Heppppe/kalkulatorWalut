#include "api.h"

API::API(const string& key) : apiKey(key), url("https://openexchangerates.org/api/latest.json?app_id=" + key) {} //konstruktor klasy

size_t API::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool API::fetchRates() {                                                         //funkcja wysy³aj¹ca rz¹dania i odbieraj¹ca kursy
    CURL* curl;                                                             //WskaŸnik na obiekt CURL, który reprezentuje sesjê libcurl
    CURLcode res;                                                           //Zmienna przechowuj¹ca kod zwrotny z funkcji libcurl
    curl = curl_easy_init();                                                //Inicjalizacja sekcji libcurl
    if (curl) {                                                             //srawdzenie poprawnoœci inicjalizacji(niepoprawna kiedy wartoœæ to null
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());                   //Ustawia URL, do którego zostanie wys³ane ¿¹danie
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);       //Ustawia funkcjê zwrotn¹, która bêdzie wywo³ywana za ka¿dym razem, gdy libcurl odbierze dane.
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);               // Ustawia wskaŸnik na dane u¿ytkownika

        res = curl_easy_perform(curl);                                      //Wykonuje operacjê transferu
        if (res != CURLE_OK) {                                              //sprawdzenie czy transfer danych siê powiód³ 
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;      //zwraca opis b³êdu w formie tekstowej
            curl_easy_cleanup(curl);                                        // Zwalnia wszystkie zasoby zwi¹zane z sesj¹ curl
            return false;
        }
        curl_easy_cleanup(curl);
        return true;
    }
    return false;
}

string API::getResponse() const {                                                //metoda wywo³uj¹ca przechwycone dane
    return response;
}