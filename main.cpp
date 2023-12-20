#include <iostream>
#include <vector>
#include "Cryptobook.h"
#include "MerkelMain.h"
#include "CSVReader.h"

int main()
{
    CSVReader reader;
    std::vector<Cryptobook> entries = reader.readCSV("20223.csv");

      MerkelMain app{};
      app.init();

    return 0;
}
