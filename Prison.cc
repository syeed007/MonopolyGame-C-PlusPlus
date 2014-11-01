// implementation file for Prison.hh

#include "Prison.hh"

const int NOT_IN_PRISON = 1;
const int NO_MONEY = 2;
const int SUCCESS_BRIBE = 0;

Prison::Prison()
{
}

// constructor
Prison::Prison( int st_id, string st_name, string st_type, int sh_price,
              int no_of_shakes, int bribe_amount ): 
   Square( st_id, st_name, st_type, sh_price, no_of_shakes ), 
   bribe( bribe_amount )
{}



int Prison::giveBribe( PlayerList *p_list, char p_id )
{
   // player is not in prison or reach prison normally
   // not by drawing card
   if( ! ( (*p_list).getPlayerById( p_id ).getPrisonStatus() ) )
   {
      return NOT_IN_PRISON;  // 1 = the player is not in prison
   }

   else
   {
      if( (*p_list).getPlayerById( p_id ).getMoney() < bribe )
      {
	 return NO_MONEY; // 2 = player doses not have sufficient money to bribe
      }
      
      // deducting the money from the players account
      (*p_list).setMonyById( p_id, -bribe ); // sending a negative amount

      (*p_list).setPrisonStatusById( p_id, false ); 
                                                //     free from jail

      return SUCCESS_BRIBE; // 0= successfull bribing
   }   
}



void Prison::redemptionBySix( PlayerList *p_list, char p_id)
{
   // changing the prison status
   if( (*p_list).getPlayerById( p_id ).getPrisonStatus() ) 
   {
      (*p_list).setPrisonStatusById( p_id, false );
   }

}
