#include <iostream>
#include <string>
#define CURL_STATICLIB

#include "curl/curl.h"

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


class API {         //klasa ��cz�ca z API
private:
    string apiKey;      //zmienna klucza
    string url;         //zmienna stronny
    string response;    //zmienna zwracaj�ca warto�ci

    //  funkcj� zwrotna, kt�ra jest u�ywana przez libcurl do obs�ugi danych otrzymanych z ��dania HTTP
    static size_t WriteCallback(void*, size_t, size_t, void*);

public:
    API(const string&); //konstruktor klasy

    bool fetchRates();

    string getResponse() const;
};