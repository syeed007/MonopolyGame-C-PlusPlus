//====================================
//specifiaction file for StreetList.hh
//====================================

//====================================
#include<vector>
#include "Start.hh"
#include "playerlist.hh"
//====================================

//const int No_OF_STREET = 15;

#ifndef STREETLIST_HH
#define STREETLIST_HH



class StreetList{
   private:
      vector< Start > street_list;
    
   public:
      void addStreet( int st_id, string st_name, string st_type, int sh_price,
		      int no_of_shakes, int street_price );


      // return an Street object of a given Street id
      Start getStreetById( int st_id );

      void setOwnerById( char p_id, int st_id );

     // set the number of shacks by incrementing it by one..
      void buildShackById( int st_id );
      
      int size();
      Street at( int index );

      void setNoOfShacksById( int st_id );
};

#endif
