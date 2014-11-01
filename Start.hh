// specification file for Start street
//====================================

// including required libraries and header files
//===============================================================
#include "Street.hh"      // super class for Start class
#include "playerlist.hh"  // Class for changing the player status
//===============================================================

#ifndef START_HH
#define START_HH

class Start: public Street{
   
   public:
      Start();
      Start( int st_id, string st_name, string st_type, int sh_price,
                 int no_of_shakes, int street_price );

      void startTrigger( PlayerList *p_list, char p_id );
      // pecondition: take player list and the player id as argument
      // postcondition: if a player passes through the start square
      //                   or, moves to it. then he or she would be
      //                awarded some amount of money( -/+ ).
      //          (-) going to prison never trigger this function
};


#endif
