//==============================
// specifiaction file for Street
//==============================

// including required libraries and header files
//===============================================================
#include "square.hh"      // super class Start class
#include "playerlist.hh"  // Class for changing the player status
#include "playcardlist.hh"

//===============================================================


#ifndef STREET_HH
#define STREET_HH


class Street: public Square{
   private:
      char owner;            // holds the player id who currently owns the
                            // square.
                            // owner = 0 , if not owned by anyone.
      
      int price;            // holds the price to buy a square or street
   
   public:
      Street();
      Street(  int st_id, string st_name, string st_type, int sh_price,
	       int no_of_shakes, int street_price );

      int calculateRent();
      // calculate rent of a street by the given equation

      int getPrice();
      // return current price of the street

      char getOwner();
      // return owner id of the street

      //int getNoOfShacks();

      bool setOwner( char p_id );
      // set the owner for the street.

      // Postcondition:
      // return true for successfully setting the owner

      int buildShack( PlayerList *p_list, char p_id );
      // preconditoin: build shach in the street
      // postconditoin:
      // return values: 0 = if successfully build the shack
      //                1 = if the square owned by other player or not sold
      //                2 = if no of shacks already reached the maximum limit
      //                3 = if the player does not have enough money
 
      int buyStreet( PlayerList *p_list, char p_id );
      // preconditon: sold the street if not sold already
      // postconditon:
      // return values: 0 = if successfully sold
      //                1 = if not sold yet
      //                2 = if the player does not have enough money
      
      void payRent( PlayerList *p_list, char p_id );
      // preconditon: pay rent to the owner of the street
      // prostconditon:
      //        get the player object and current owner objcet
      //        check if the owner are different or not
      //        if owners are different
      //            -> calculate rent of the square
      //            -> pay rent accordingly
      //            -> print appropriate message

      bool drawCard(PlayCardList &pc_lst, PlayerList &pl_lst, char pl_id);
};


#endif
