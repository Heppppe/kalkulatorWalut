#include "JSON.h"

JSON::JSON() {}

void JSON::jparse(const string& response) {
    jsonData = nlohmann::json::parse(response);  // Parsuje dane JSON z odpowiedzi API
}

void JSON::displayRates() const {
    cout << "Kursy walut:" << endl;
    for (auto it = jsonData["rates"].begin(); it != jsonData["rates"].end(); ++it) {  // Iteruje przez kursy walut
        cout << it.key() << ": " << it.value() << endl;  // Wyœwietla kurs waluty
    }
}

double JSON::getRate(const string& currency) const {
    if (jsonData["rates"].contains(currency)) {  // Sprawdza, czy kurs waluty istnieje
        return jsonData["rates"][currency];  // Zwraca kurs waluty
    }
    return 0.0;  // Zwraca 0.0, jeœli waluta nie istnieje
}

void JSON::exchangeToAllCurrencies(double dollars) const {
    set<string> desiredCurrencies = { "PLN", "USD", "EUR", "GBP" };                     // Zbiór walut do wyœwietlenia
    for (auto it = jsonData["rates"].begin(); it != jsonData["rates"].end(); ++it) {    // Iteruje przez kursy walut
        if (desiredCurrencies.find(it.key()) != desiredCurrencies.end())                // Warunek sprawdzaj¹cy czy w obiekcie JSON znajduj¹ siê podane waluty
        {
            cout << dollars * (double)it.value() << " " << it.key() << endl;  // Wyœwietla wartosc wpisanej kwoty w inneych walutach
        }
    }
}