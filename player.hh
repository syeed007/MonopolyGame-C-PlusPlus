// specification file for Player

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

using namespace std;

class Player
{
   private:
      string  name_of_player ;
      int money;
      char player_id;
      bool prison_status;
      int current_square;

   public:
      Player();
      Player(string name, int mon, char id, bool pri_status, int curr_sqr);
      ~Player();
      int getCurrentSquare();
      void setCurrentSquare(int square_id);
      int getMoney();
      void setMoney(int amount);
      bool getPrisonStatus();
      void setPrisonStatus(bool status);
      string getPlayerName();
      char getPlayerId();
};

#endif
