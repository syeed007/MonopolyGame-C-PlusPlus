//====================================
// specification file for Prison class
//====================================

// including required libraries and header files
//===============================================================
#include "square.hh"      // super class for Prison class
#include "playerlist.hh"  // Class for changing the player status 
                          // if he or she is in prison.
#include <string>
//===============================================================


#ifndef PRISON_HH
#define PRISON_HH


class Prison: public Square{

   private:
       int bribe;          // hold the amount of bribe
                           // amount of bribe is given in initialization file
                           // in 'example.txt' file
   public:
      Prison();
      Prison( int st_id, string st_name, string st_type, int sh_price, 
	      int no_of_shakes, int bribe_amount );
      // precondition: take bribe_amount as an agrument.
      //               bribe amount is given in initialization file.
      // postcondition: initialize bribe with this value

      int giveBribe( PlayerList *p_list, char p_id );
      // precondition: take player list and player id ( of the palyer 
      //               in prison ) as a argument.

      // postcondition: (1) find the palyer (p_id) in the player list( p_list )
      //                (2) get player prison status.
      //                (3) change the prison status.
      //                (4) deduct the player money by the amount of 'bribe'
      
      void redemptionBySix( PlayerList *p_list, char p_id);
      // precondition: take player list and player id ( of the palyer 
       //               in prison )as a argument.

      // postcondition: (1) find the palyer (p_id) in the player list( p_list)
      //                (2) get player prison status.
      //                (3) change the prison status.

};


#endif
