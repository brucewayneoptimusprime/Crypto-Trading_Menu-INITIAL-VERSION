#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "CSVReader.h"
#include "Cryptobook.h"

int main()
{
    std::ifstream csvFile{"20223.csv"};
    std::string line;
    std::vector<std::string> tokens;

    CSVReader reader; // Create an instance of CSVReader

    if (csvFile.is_open())
    {
        std::cout << "File opened successfully" << std::endl;

        while (std::getline(csvFile, line))
        {
            std::cout << "The line is: " << line << std::endl;
            tokens = reader.tokenize(line, ',');

            if (tokens.size() != 5)
            {
                std::cout << "Bad line" << std::endl;
                continue;
            }

            try
            {
                Cryptobook book = reader.stringstoOBE(tokens);
                // Do something with the Cryptobook object
            }
            catch (const std::exception& e)
            {
                // Handle exception
                continue;
            }

            // Printing the tokenized string
            for (const std::string& t : tokens)
            {
                std::cout << t << std::endl;
            }
            std::cout << " " << std::endl;
        }

        csvFile.close(); // Don't forget to close the file when you're done.
    }
    else
    {
        std::cerr << "Failed to open the file" << std::endl;
    }

    return 0;
}
