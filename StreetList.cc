// Implementation file for StreetList.hh

#include "StreetList.hh"


// adding street to the street list
void StreetList::addStreet( int st_id, string st_name, string st_type, 
			    int sh_price, int no_of_shakes, 
			    int street_price  )
{
   street_list.push_back( Start( st_id, st_name, st_type, sh_price, 
				 no_of_shakes, street_price ) );
}


// return an Street object of a given Street id
Start StreetList::getStreetById( int st_id )
{
   Start st;
   for( unsigned int i = 0; i < street_list.size(); i++ )
   {
      if( street_list.at(i).getStreetId() == st_id )
      {
         st = street_list.at(i);
      }
   }
   return st;
}


// set owner of the street if anyone bought this street.
void StreetList::setOwnerById( char p_id, int st_id )
{
   for( unsigned int i = 0; i < street_list.size(); i++ )
   {
      if( street_list.at(i).getStreetId() == st_id )
      {
         street_list.at(i).setOwner( p_id );
      }
   }
}


void StreetList::setNoOfShacksById( int st_id )
{
   for( unsigned int i = 0; i < street_list.size(); i++ )
   {
      if( street_list.at(i).getStreetId() == st_id )
      {
         street_list.at(i).setCurrentNoOfShacks( 0 );
      }
   }
}

// set the number of shacks by incrementing it by one..
void StreetList::buildShackById( int st_id )
{
   for( unsigned int i = 0; i < street_list.size(); i++ )
   {
      if( street_list.at(i).getStreetId() == st_id )
      {
         street_list.at(i).incrementNoOfShacks();
      }
   }

}

int StreetList::size()
{
   return street_list.size();
}


Street StreetList::at( int index )
{
   return  street_list.at( index );
}
