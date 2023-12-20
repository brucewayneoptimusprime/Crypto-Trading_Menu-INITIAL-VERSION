#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader() {}

std::vector<Cryptobook> CSVReader::readCSV(const std::string& csvFilename)
{
    std::vector<Cryptobook> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;

    if (!csvFile.is_open())
    {
        std::cerr << "Failed to open the CSV file: " << csvFilename << std::endl;
        return entries; // Return an empty vector to indicate an error
    }

    while (std::getline(csvFile, line))
    {
        Cryptobook obe;
        try
        {
            obe = stringstoOBE(tokenize(line, ','));
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error processing line: " << line << std::endl;
            continue; // Skip to the next line if there's an error
        }

        entries.push_back(obe);
    }

    csvFile.close(); // Explicitly close the file

    std::cout << "The number of entries are: " << entries.size() << std::endl;

    return entries;
}

Cryptobook CSVReader::stringstoOBE(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 5)
    {
        std::cerr << "Bad line" << std::endl;
        throw std::runtime_error("Invalid number of tokens in the line");
    }

    double price, amount;
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        std::cerr << "Bad float! " << tokens[3] << std::endl;
        std::cerr << "Bad float! " << tokens[4] << std::endl;
        throw std::runtime_error("Error converting string to numeric value");
    }

    Cryptobook obe{price, amount, tokens[0], tokens[1], Cryptobook::stringToCryptoBookType(tokens[2])};
    return obe;
}

std::vector<std::string> CSVReader::tokenize(const std::string& csvLine, char separator)
{
    std::vector<std::string> tokens;
    size_t start = csvLine.find_first_not_of(separator, 0);
    size_t end;

    do
    {
        end = csvLine.find_first_of(separator, start);
        if (start == std::string::npos || start == end)
            break;
        std::string token = (end != std::string::npos) ? csvLine.substr(start, end - start) : csvLine.substr(start);

        tokens.push_back(token);
        start = (end != std::string::npos) ? end + 1 : std::string::npos;

    } while (end != std::string::npos);

    return tokens;
}
