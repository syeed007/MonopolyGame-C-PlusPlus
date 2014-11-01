// implementation file for Street.hh

#include "Street.hh" 

const int RENT_DIV_1 = 4; 
const int RENT_DIV_2 = 10; 

const int SQ_NOT_OWN = 1; 
const int MAX_SQUARE_IS = 2;
const int NO_MON_TOBUILD = 3;
const int SHACK_BUILD = 0; 


const int ALREADY_SOLD = 1;
const int NO_MON_TOBUY = 2;
const int SUS_BUY = 0;

// constructor..

Street::Street()
{

}

Street::Street( int st_id, string st_name, string st_type, int sh_price,
		 int no_of_shakes, int street_price ):
   Square( st_id, st_name, st_type, sh_price, no_of_shakes ), 
   owner( '0' ), price( street_price )
{
}

// calculate the rent of the street
int Street::calculateRent()
{
   int rent = 0;
   int total_shacks = getNoOfShacks(); // getting total number of shacks

   // calculating rent
   rent = ( price / RENT_DIV_1  ) + 
      total_shacks * total_shacks * price  / RENT_DIV_2;

   return rent;
}


// return curren price of the street
int Street::getPrice()
{
   return price;
}


// return current owner id
char Street::getOwner()
{
   return owner;
}

// set the owner id for a new owner or change the owner id
bool Street::setOwner( char p_id )
{
   owner = p_id;
   return true;
}


// build Shack in a street by maintaining certain conditions
int Street::buildShack( PlayerList *p_list, char p_id )
{
   // if the player does not own the square or the square has now owner yet
   if( owner == '0' || owner != p_id )
   {
      return SQ_NOT_OWN; // 1 = error code for not owning the square 
   }

   else if( getCurrentNoOfShacks() >= getNoOfShacks() )
   {
      return MAX_SQUARE_IS; // 2 = error code for max no of shacks 
   }

   else if( (*p_list).getPlayerById( p_id ).getMoney() < price )
   {
      return NO_MON_TOBUILD; // 3 = error code for not having enough money
   }

   else
   {
      (*p_list).setMonyById( p_id, -price ); // deducting the money
      return SHACK_BUILD; // 0 = code for successfully build a shack
   }
}

// buy the street for the player where he is currently in
int Street::buyStreet( PlayerList *p_list, char p_id )
{
   // if the player does not own the square or the square has now owner yet
   if( owner != '0' )
   {
      return ALREADY_SOLD; // 1 = error code for the square already sold
   }

   else if(  (*p_list).getPlayerById( p_id ).getMoney() < price )
   {
      return NO_MON_TOBUY; // 2 = error code for not having enough money
   }

   else
   {      
      (*p_list).setMonyById(p_id, -price );
      return SUS_BUY;             // 0 = code for successfully buy of the square
   }
}


// pay rent to the owner of the square..
void Street::payRent( PlayerList *p_list, char p_id )
{
   // getting the player object who currently own the Street
   Player p_owner = (*p_list).getPlayerById( owner );

   // check whether the Street is already has a owner and
   // owner is different..
   if( owner != '0' && owner != p_id )
   {
      int rent = calculateRent(); // getting the rent for this Street

      (*p_list).setMonyById(p_id, -rent ); // current player pays rent
      (*p_list).setMonyById( owner, rent ); // owner gets the rent

      cout << getStreetName() <<" owned by " << p_owner.getPlayerName()
	   << ": " << rent << "$" << endl;
   }
}



bool Street::drawCard(PlayCardList &pc_lst, PlayerList &pl_lst, char pl_id)
{
   int money = pc_lst.getTopCard().getMoneyInCard();
   bool prison = pc_lst.getTopCard().getPrisonInCard();
   pc_lst.showCardInfo();

   pl_lst.updateMoneyAndStatus(pl_id, money, prison);

   return prison;
}
