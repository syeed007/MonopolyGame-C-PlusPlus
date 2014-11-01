// specification file for PlayCard

#ifndef PLAYCARD_H
#define PLAYCARD_H

#include<iostream>
#include<string>

using namespace std;

class PlayCard
{
   private:
      string description;
      int money;
      bool prison;
      int move;

   public:
      PlayCard();
      PlayCard(string des, int mon, int pri, int mov);
      ~PlayCard();
      void printCardDescription();
      int getMoneyInCard();
      bool getPrisonInCard();
      int getMove();
};

#endif
