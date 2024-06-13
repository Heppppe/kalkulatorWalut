#include "api.h"

API::API(const string& key) : apiKey(key), url("https://openexchangerates.org/api/latest.json?app_id=" + key) {}

size_t API::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    // Zapisuje pobrane dane do zmiennej response
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool API::fetchRates() {
    CURL* curl;  // WskaŸnik na obiekt CURL, który reprezentuje sesjê libcurl
    CURLcode res;  // Zmienna przechowuj¹ca kod zwrotny z funkcji libcurl
    curl = curl_easy_init();  // Inicjalizacja sesji libcurl
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());  // Ustawia URL do którego zostanie wys³ane ¿¹danie
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Ustawia funkcjê zwrotn¹
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);  // Ustawia wskaŸnik na dane

        res = curl_easy_perform(curl);  // Wykonuje operacjê transferu
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;  // Wypisuje opis b³êdu
            curl_easy_cleanup(curl);  // Zwalnia zasoby zwi¹zane z sesj¹ curl
            return false;  // Zwraca false w przypadku b³êdu
        }
        curl_easy_cleanup(curl);  // Zwalnia zasoby zwi¹zane z sesj¹ curl
        jsonParser.parse(response);  // Parsuje odpowiedŸ z API
        return true;  // Zwraca true w przypadku powodzenia
    }
    return false;  // Zwraca false w przypadku b³êdu inicjalizacji
}

string API::getResponse() const {
    return response;  // Zwraca odpowiedŸ z API
}

JSON& API::getJSONParser() {
    return jsonParser;  // Zwraca referencjê do obiektu JSON
}