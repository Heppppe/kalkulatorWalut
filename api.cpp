#include "api.h"

API::API(const string& key) : apiKey(key), url("https://openexchangerates.org/api/latest.json?app_id=" + key) {} //konstruktor klasy

size_t API::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool API::fetchRates() {                                                         //funkcja wysy�aj�ca rz�dania i odbieraj�ca kursy
    CURL* curl;                                                             //Wska�nik na obiekt CURL, kt�ry reprezentuje sesj� libcurl
    CURLcode res;                                                           //Zmienna przechowuj�ca kod zwrotny z funkcji libcurl
    curl = curl_easy_init();                                                //Inicjalizacja sekcji libcurl
    if (curl) {                                                             //srawdzenie poprawno�ci inicjalizacji(niepoprawna kiedy warto�� to null
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());                   //Ustawia URL, do kt�rego zostanie wys�ane ��danie
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);       //Ustawia funkcj� zwrotn�, kt�ra b�dzie wywo�ywana za ka�dym razem, gdy libcurl odbierze dane.
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);               // Ustawia wska�nik na dane u�ytkownika

        res = curl_easy_perform(curl);                                      //Wykonuje operacj� transferu
        if (res != CURLE_OK) {                                              //sprawdzenie czy transfer danych si� powi�d� 
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;      //zwraca opis b��du w formie tekstowej
            curl_easy_cleanup(curl);                                        // Zwalnia wszystkie zasoby zwi�zane z sesj� curl
            return false;
        }
        curl_easy_cleanup(curl);
        return true;
    }
    return false;
}

string API::getResponse() const {                                                //metoda wywo�uj�ca przechwycone dane
    return response;
}