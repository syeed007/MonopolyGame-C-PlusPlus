// specification file for PlayerList

#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include<iostream>
#include<string>
#include<vector>

#include "player.hh"

using namespace std;

class PlayerList
{
   private:
      vector<Player> players;

   public:
      PlayerList();
      ~PlayerList();
      void addPlayer(Player player);
      void removePlayerById(char pl_id);
      bool verifyPlayer(Player new_player);
      void setCurrentSquareById(char p_id, int s_id);
      void setMonyById(char p_id, int mny);
      void setPrisonStatusById(char p_id, int p_status);
      Player getPlayerById(char player_id);
      void updateMoneyAndStatus(char player_id, int amount, bool pri_status);
      int size(); // returns size of the vector
      Player at(int position);
};

#endif
