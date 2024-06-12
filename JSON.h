#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <json.hpp>

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

using namespace std; // Dyrektywa using do namespace std

class JSON {
private:
    nlohmann::json jsonData; // Obiekt json u¿ywany do przechowywania danych JSON

public:
    // Konstruktor
    JSON();

};

#endif

