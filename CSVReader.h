#pragma once

#include "Cryptobook.h"
#include <vector>
#include <string>

class CSVReader {
public:
    CSVReader();

    std::vector<Cryptobook> readCSV(const std::string& csvFile);
    Cryptobook stringstoOBE(const std::vector<std::string>& tokens);

private:
    std::vector<std::string> tokenize(const std::string& csvLine, char separator);
};
