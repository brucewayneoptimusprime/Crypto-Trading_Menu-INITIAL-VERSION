#include "MerkelMain.h"
#include "Cryptobook.h"
#include <iostream>
#include <string>
#include <vector>
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


   orders.push_back(Cryptobook{0.02187163,0.03322569,"2020/03/17 17:01:24.884492","ETH/BTC",Typeoforder::bid}         ); //Storing data//
   orders.push_back(Cryptobook{0.02187008,0.21,"2020/03/17 17:01:24.884492","ETH/BTC",Typeoforder::bid}               );
   orders.push_back(Cryptobook{157647,0.00158102,"2020/03/17 17:01:55.120438","DOGE/USDT",Typeoforder::bid}           );
   orders.push_back(Cryptobook{1940.00219867,0.00154639,"2020/03/17 17:01:55.120438","DOGE/USDT",Typeoforder::bid}    );
   orders.push_back(Cryptobook{7413.21162129,0.00147901,"2020/03/17 17:01:55.120438","DOGE/USDT",Typeoforder::bid}    );
   orders.push_back(Cryptobook{1972.551,0.00145374,"2020/03/17 17:01:55.120438","DOGE/USDT",Typeoforder::bid}         );
   orders.push_back(Cryptobook{212011.13765176,0.00141502,"2020/03/17 17:01:55.120438","DOGE/USDT",Typeoforder::bid}  );


   for(unsigned int i = 0; i < orders.size() ; ++i)                                        //Iteration//
   {cout << "Money in the order book : " << orders[i].money << endl;}


   cout <<"---------------------------------------------------" << endl;


    while (true)
    {
     Printmenu();
     int Useroption = Displayuseroption();
     outputonuser(Useroption);
        }
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

void MerkelMain::Exchangestats(){std::cout << "Order Book contains " << orders.size() << " entries" << std::endl;}

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
