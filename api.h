#include <iostream>
#include <string>
#include "JSON.h"
#include <curl/curl.h>

#define CURL_STATICLIB
#ifdef _DEBUG
#pragma comment (lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment (lib, "curl/libcurl_a.lib")
#endif

#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
#pragma comment (lib, "advapi32.lib")
//to jest potrzebne, zeby dobrze wykrywalo biblioteke curl, gdy nie masz jej w linkerze

using namespace std;


class API {
private:
    string apiKey;      // Przechowuje klucz API
    string url;         // Przechowuje URL API
    string response;    // Przechowuje odpowiedŸ z API w formie stringa
    JSON jsonParser;    // Obiekt klasy JSON do parsowania danych

    static size_t WriteCallback(void*, size_t, size_t, void*);  // Funkcja zwrotna do zapisu danych

public:
    API(const string& key); // Konstruktor klasy

    bool fetchRates();  // Metoda do pobierania kursów walut

    string getResponse() const;  // Metoda zwracaj¹ca odpowiedŸ w formie stringa

    JSON& getJSONParser();  // Publiczna metoda dostêpu do obiektu JSON
};