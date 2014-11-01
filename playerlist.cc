// implementation file for PlayerList

#include "playerlist.hh"
#include "player.hh"

PlayerList::PlayerList()
{
}

PlayerList::~PlayerList()
{
}

int PlayerList::size()
{
   return players.size();
}

Player PlayerList::at(int position)
{
   return players.at(position);
}

void PlayerList::addPlayer(Player new_player)
{
   players.push_back(new_player);
}

void PlayerList::setCurrentSquareById(char p_id, int s_id)
{
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i).getPlayerId() == p_id)
      {
         players.at(i).setCurrentSquare(s_id);
      }
   }
}

void PlayerList::setMonyById(char p_id, int mny)
{
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i).getPlayerId() == p_id)
      {
         players.at(i).setMoney(mny);
      }
   }
}

void PlayerList::setPrisonStatusById(char p_id, int p_status)
{
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i).getPlayerId() == p_id)
      {
         players.at(i).setPrisonStatus(p_status);
      }
   }
}

void PlayerList::removePlayerById(char pl_id)
{
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i).getPlayerId() == pl_id)
      {
         players.erase(players.begin() + i);
	 return;
      }
   }
}

bool PlayerList::verifyPlayer(Player new_player)
{
   bool verification = true;
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i).getPlayerName() == new_player.getPlayerName())
      {
	 cout << "ERROR: The players cannot have same names." << endl;
	 verification = false;
	 break;
      }
   }

   return verification;
}

Player PlayerList::getPlayerById(char id)
{
   Player plr;
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if(players.at(i).getPlayerId() == id)
      {
	 plr = players.at(i);
      }
   }
   return plr;
}

void PlayerList::updateMoneyAndStatus(char id, int amount, bool pri_status)
{
   for(unsigned int i = 0; i < players.size(); i++)
   {
      if( players.at(i).getPlayerId() == id )
      {
         players.at(i).setMoney( amount );
	 players.at(i).setPrisonStatus( pri_status );
         break;
      }
   }

  
}

