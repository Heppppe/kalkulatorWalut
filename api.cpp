#include "api.h"

API::API(const string& key) : apiKey(key), url("https://openexchangerates.org/api/latest.json?app_id=" + key) {}

size_t API::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    // Zapisuje pobrane dane do zmiennej response
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool API::fetchRates() {
    CURL* curl;  // Wska�nik na obiekt CURL, kt�ry reprezentuje sesj� libcurl
    CURLcode res;  // Zmienna przechowuj�ca kod zwrotny z funkcji libcurl
    curl = curl_easy_init();  // Inicjalizacja sesji libcurl
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());  // Ustawia URL do kt�rego zostanie wys�ane ��danie
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Ustawia funkcj� zwrotn�
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);  // Ustawia wska�nik na dane

        res = curl_easy_perform(curl);  // Wykonuje operacj� transferu
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;  // Wypisuje opis b��du
            curl_easy_cleanup(curl);  // Zwalnia zasoby zwi�zane z sesj� curl
            return false;  // Zwraca false w przypadku b��du
        }
        curl_easy_cleanup(curl);  // Zwalnia zasoby zwi�zane z sesj� curl
        jsonParser.parse(response);  // Parsuje odpowied� z API
        return true;  // Zwraca true w przypadku powodzenia
    }
    return false;  // Zwraca false w przypadku b��du inicjalizacji
}

string API::getResponse() const {
    return response;  // Zwraca odpowied� z API
}

JSON& API::getJSONParser() {
    return jsonParser;  // Zwraca referencj� do obiektu JSON
}