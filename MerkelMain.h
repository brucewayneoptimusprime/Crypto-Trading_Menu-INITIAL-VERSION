#pragma once

#include <vector>
#include "Cryptobook.h"


class MerkelMain
{
    public:
    MerkelMain();
    /** Call this to start the simulation */
    void init();

    private:
    void LoadOrderBook();
    void PrintMarketStats();
    void Printmenu();
    int Displayuseroption();
    void Invalidoption();
    void Helpguide();
    void Exchangestats();    //PRINT MARKET STATS EQUIVALENT//
    void Offer();
    void Bidding();
    void Walletcheck();
    void GotonextTF();
    void outputonuser(int Useroption);

    std::vector<Cryptobook>orders;         //Vector//
};
