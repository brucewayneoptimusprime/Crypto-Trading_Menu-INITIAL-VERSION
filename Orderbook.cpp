#include "Cryptobook.h"

Cryptobook::Cryptobook() : money(0.0), frac_ofbitcoin(0.0), ordertype(Typeoforder::unknown) {
    // Default constructor implementation
}

Typeoforder Cryptobook::stringToCryptoBookType(std::string s)
{
    if (s == "ask")
    {
        return Typeoforder::ask;
    }
    else if (s == "bid")
    {
        return Typeoforder::bid;
    }

    return Typeoforder::unknown;
}

Cryptobook::Cryptobook(double amoney,
                       double afrac_ofbitcoin,
                       std::string atimestamp,
                       std::string aType_bitcoin,
                       Typeoforder aordertype)
    : money(amoney),
      frac_ofbitcoin(afrac_ofbitcoin),
      timestamp(atimestamp),
      Type_bitcoin(aType_bitcoin),
      ordertype(aordertype) {
    // Constructor implementation
}
