#pragma once

#include <string>
#include <iostream>
#include <json.hpp>

using namespace std;

class JSON {
private:
    nlohmann::json jsonData;  // Obiekt json u¿ywany do przechowywania danych JSON

public:
    JSON();  // Konstruktor
    void jparse(const string& response);  // Metoda do parsowania danych JSON
    void displayRates() const;  // Metoda do wyœwietlania kursów walut
    double getRate(const string& currency) const;  // Metoda do uzyskania kursu waluty
};
