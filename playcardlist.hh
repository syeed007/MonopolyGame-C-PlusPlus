// specification file for PlayCard

#ifndef PLAYCARDLIST_H
#define PLAYCARDLIST_H

#include<iostream>
#include<string>
#include<vector>

#include "playcard.hh"

using namespace std;

//const int MAX_CARD = 100;

class PlayCardList
{
   private:
      vector<PlayCard> play_card_list;
      int top;
      int no_of_card;

   public:
      PlayCardList();
      ~PlayCardList();
      void addPlayCard(PlayCard new_playcard);
      void showCardInfo();
      PlayCard getTopCard();
};

#endif
