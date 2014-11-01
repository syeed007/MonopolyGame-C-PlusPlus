//implementation file for Start.hh file

#include "Start.hh"

Start::Start()
{

}

Start::Start( int st_id, string st_name, string st_type, int sh_price,
	      int no_of_shakes, int street_price ):
   Street( st_id, st_name, st_type, sh_price, no_of_shakes, street_price )
{

}

void Start::startTrigger( PlayerList *p_list, char p_id )
{
   // if the player is in the prison
   if( (*p_list).getPlayerById( p_id ).getPrisonStatus() )
   {
      cout << "You are in prison." << endl;
   }

   else                // otherwise award the money
   {
      // printing the message if a player arrives or passes the start square
      cout << "Start square: " << getPrice() << endl;

      // awarding the money
      (*p_list).setMonyById( p_id, getPrice() );
   }
}
