// implementation file for Square

#include "square.hh"

Square::Square()
{
}

Square::Square(int id, string name, string typ, int sh_price, int no_of_sh)
{
   street_id = id;
   street_name = name;
   street_type = typ;
   shack_price = sh_price;
   no_of_shack = no_of_sh;
   no_of_shacks_build = 0;
}

Square::~Square()
{
}


// adds a player to the player list when a player entered into the square
void Square::addPlayer(int player_id)
{
   players.push_back(player_id);
}


// removes the player from player list when he/she left the square
void Square::removePlayer(int player_id)
{
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i) == player_id)
      {
	 players.erase(players.begin() + i);
      }
   }
}


// shows the players who are currently in the square
void Square::showPlayerId()
{
   cout << "Players in " << street_name << " :" << endl;
   for (unsigned int i = 0; i < players.size(); i++)
   {
      cout << players.at(i);
   }
   cout << endl;
}

// return the street id
int Square::getStreetId()
{
   return street_id;
}

// return the street type
string Square::getStreetType()
{
   return street_type;
}

string Square::getStreetName()
{
   return street_name;
}

// return maximum number of shacks that can be build in this square
int Square::getNoOfShacks()
{
   return no_of_shack;
}

// return total number of shacks currently build
int Square::getCurrentNoOfShacks()
{
   return no_of_shacks_build;
}

void Square::setCurrentNoOfShacks( int no )
{
   no_of_shacks_build = no;
}


// increment current number of shacks by one
void Square::incrementNoOfShacks()
{
   no_of_shacks_build++;
}

//returns type of the street
string Square::getType()
{
   return street_type;
}
