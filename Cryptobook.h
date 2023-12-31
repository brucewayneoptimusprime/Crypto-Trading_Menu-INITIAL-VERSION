#pragma once

#include <string>

enum class Typeoforder { bid, ask, unknown };

class Cryptobook {
public:
    double money;
    double frac_ofbitcoin;
    std::string timestamp;
    std::string Type_bitcoin;
    Typeoforder ordertype;

    Cryptobook(); // Default constructor

    static Typeoforder stringToCryptoBookType(std::string);

    Cryptobook(double amoney,
               double afrac_ofbitcoin,
               std::string atimestamp,
               std::string aType_bitcoin,
               Typeoforder aordertype);
};
