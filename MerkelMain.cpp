#include "MerkelMain.h"
#include "Cryptobook.h"
#include <iostream>
#include <string>
#include <vector>
#include "CSVReader.h"
using namespace std;


MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{   LoadOrderBook();                                           // ,,bid,,

    int input;
    while(true)
    {
        Printmenu();
        input = Displayuseroption();
        outputonuser(input);
    }
}

void MerkelMain::LoadOrderBook()
{
    CSVReader reader;
    orders = reader.readCSV("20223.csv");
}




void MerkelMain::Printmenu()
{
  std::cout << "1: Print help " << std::endl;           //Printing help//
  std::cout << "2: Print exchange stats " << std::endl; //Printing exchange stats//
  std::cout << "3: Make an offer " << std::endl;        //Making an offer//
  std::cout << "4: Make a bid " << std::endl;           // Making a bid//
  std::cout << "5: Print wallet " << std::endl;         //Printing wallet//
  std::cout << "6: Continue " << std::endl;             //Continue//
  std::cout << "=====================" << std::endl;}


int MerkelMain::Displayuseroption()
{
      std::cout << "Choose between 1-6" << std::endl;
      int Useroption;
      std::cin >> Useroption;
      std::cout << "You chose: " << Useroption << std::endl;
      return Useroption;
}

void MerkelMain::Invalidoption(){std::cout << "Invalid Input, Enter a number between 1-6" << std::endl;}

void MerkelMain::Helpguide(){std::cout << "Help - Your aim is to make money. Analyze the market and make bids and offers" << std::endl;}

void MerkelMain::Exchangestats()
{
    std::cout << "Order Book contains " << orders.size() << " entries" << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;

    for (const Cryptobook& e : orders)
    {
        if (e.ordertype == Typeoforder::ask)
        {
            asks++;
        }

        if (e.ordertype == Typeoforder::bid)
        {
            bids++;
        }
    }

    std::cout << "The OrderBook contains " << bids << " bids and " << asks << " asks." << std::endl;
}


void MerkelMain::Offer(){std::cout << "Make an offer - Enter the amount" << std::endl;}

void MerkelMain::Bidding(){std::cout << "Make a bid - Enter the amount" << std::endl;}

void MerkelMain::Walletcheck(){std::cout << "Your wallet is empty" << std::endl;}

void MerkelMain::GotonextTF(){std::cout << "Going to next Time Frame" << std::endl;}

void MerkelMain::outputonuser(int Useroption)
{
  if (Useroption == 0)
  {
    Invalidoption();
  }
  if (Useroption == 1)
  {
    Helpguide();
  }
  if (Useroption == 2)
  {
    Exchangestats();

  }
  if (Useroption == 3)
  {
    Offer();

  }
  if (Useroption == 4)
  {
    Bidding();

  }
  if (Useroption == 5)
  {
    Walletcheck();

  }
  if (Useroption == 6)
  { GotonextTF();

  }
}
