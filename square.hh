// specification file for Square

#ifndef SQUARE_H
#define SQUARE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int NO_OF_PLAYERS = 5;

class Square
{
   private:

   protected:
      int street_id;
      string street_name;
      string street_type;
      int shack_price;
      int no_of_shack;
      int no_of_shacks_build;
      vector<int> players;

   public:
      Square();
      Square(int id, string name, string typ, int sh_price, int no_of_sh);
      virtual ~Square();
      void addPlayer(int player_id);
      void removePlayer(int player_id);
      void showPlayerId();

      // return the street id
      int getStreetId();

      // return the street type
      string getStreetType();

      string getStreetName();

      int getNoOfShacks();

      // return total number of shacks currently build
      int getCurrentNoOfShacks();

      void setCurrentNoOfShacks( int no );

      // increment current number of shacks by one
      void incrementNoOfShacks();

      // return street type
      string getType();
};

#endif
