#include "JSON.h"

JSON::JSON() {}

void JSON::parse(const string& response) {
    jsonData = nlohmann::json::parse(response);  // Parsuje dane JSON z odpowiedzi API
}

void JSON::displayRates() const {
    cout << "Kursy walut:" << endl;
    for (auto it = jsonData["rates"].begin(); it != jsonData["rates"].end(); ++it) {  // Iteruje przez kursy walut
        cout << it.key() << ": " << it.value() << endl;  // Wy�wietla kurs waluty
    }
}

double JSON::getRate(const string& currency) const {
    if (jsonData["rates"].contains(currency)) {  // Sprawdza, czy kurs waluty istnieje
        return jsonData["rates"][currency];  // Zwraca kurs waluty
    }
    return 0.0;  // Zwraca 0.0, je�li waluta nie istnieje
}