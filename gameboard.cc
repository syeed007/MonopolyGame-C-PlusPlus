// file that will start the game and handle the operations

#include<iostream>
#include<cstdlib>
#include<string>
#include<map>

#include "boarddrawer.hh"
#include "chopper.hh"
#include "die.hh"
#include "initexception.hh"
#include "initreader.hh"
#include "utility.hh"
#include "player.hh"
#include "playerlist.hh"
#include "playcard.hh"
#include "playcardlist.hh"
#include "square.hh"
#include "Street.hh"
#include "Prison.hh"
#include "Start.hh"
#include "StreetList.hh"

const int NO_OF_ARGS = 2;
const int QUIT_PLAYER = 1;
const int MAX_SQUARE_ID = 16;

const int MIN_PLAYER = 2;
const int MAX_PLAYER = 5;

const unsigned int MIN_NAME_LENGTH = 2;
const unsigned int MAX_NAEM_LENGTH = 10;

const int CASE_0 = 0;
const int CASE_1 = 1;
const int CASE_2 = 2;
const int CASE_3 = 3;

using namespace std;
using namespace Utility;

void initialize(StreetList &st_lst, PlayCardList &pl_crd_lst,
                PlayerList &pl_lst, Prison &prison, string file,
		BoardDrawer &board);

void addPlayerToGame(PlayerList &pl_lst, int start_money);
unsigned long throwDie();
void playerOperation( StreetList *st_lst, int st_id, PlayerList *pl_lst, 
		      char p_id, bool &isQuit, int &no_of_player,
		      Prison *prison, BoardDrawer &board, int &curr_pl_index );
void displayMove( int old_id, int id, StreetList *st_lst, bool &isCard,
		 PlayerList *pl_lst, char p_id, BoardDrawer &board, 
		  Prison &pr);

void removeBankRupts( PlayerList *pl_lst, StreetList *st_lst,
		      BoardDrawer &board, int &no_of_player,
		      int &curr_pl_index );

int main( int argc, char* argv[] )
{

   if( argc != NO_OF_ARGS )
   {
      cout <<"ERROR: Give (only) the name of the initialization file " 
	   << "as parameter." << endl;

      return EXIT_FAILURE;
   }

   string file = argv[1];
   PlayerList pl_lst;
   PlayCardList pl_crd_lst;
   StreetList st_lst;
   Prison prison;

   map<int, int> card_id; // contains all card street id; map is used for find

   BoardDrawer board;

   initialize(st_lst, pl_crd_lst, pl_lst, prison, file, board);

   bool isQuit = false;
   int no_of_player = pl_lst.size();
   int curr_pl_index = 0;

   while ( !isQuit && no_of_player > QUIT_PLAYER )
   {

   //****************** new turn will come here *********************//
   // ==> print player information..

      char p_id = pl_lst.at(curr_pl_index).getPlayerId();

      cout << "new turn: " << pl_lst.at(curr_pl_index).getPlayerName()
	   << " '" << p_id << "' " << pl_lst.at(curr_pl_index).getMoney()
	   << "$" << endl;

      bool flag = true;
      int st_id = 0;
      int old_id = 0;
       // ==>print prison status....
      if ( pl_lst.at(curr_pl_index).getPrisonStatus() )
      {
	 flag = false;
	 cout << "You are in prison." << endl;
	 old_id = pl_lst.at(curr_pl_index).getCurrentSquare();
	 int die_val = static_cast<int>(throwDie());
	 if(die_val == 6)
	 {
	    prison.redemptionBySix( &pl_lst, p_id );
	    st_id = old_id + die_val;
	    flag = true;
	 }
      }

   //***************** die will be thrown here **********************//
   // ==> calculate the square player moves...
      else
      {
	 old_id = pl_lst.at(curr_pl_index).getCurrentSquare();
	 int die_val = static_cast<int>(throwDie());
	 
	 st_id = old_id + die_val;
      }
      if( flag )
      {
	 bool isCard = false;
	 
	 if(st_id > MAX_SQUARE_ID )
	 {
	    st_id = st_id % 16;
	    displayMove( old_id, st_id, &st_lst, isCard, &pl_lst, p_id, 
			 board, prison);

	    Start street = st_lst.getStreetById( 1 );
	    street.startTrigger( &pl_lst, p_id ); //get money to pass the start
	 }
      
	 else
	 {
	    displayMove( old_id, st_id, &st_lst, isCard, &pl_lst, p_id,
			 board, prison);
	 }
	 
	 
	 while( isCard )
	 {
	    old_id = pl_lst.at(curr_pl_index).getCurrentSquare();
	    
	    if( st_lst.at(0).drawCard( pl_crd_lst, pl_lst, p_id ) )
	    {
	       st_id = prison.getStreetId();
	    }
	    else
	    {
	       st_id = st_id + pl_crd_lst.getTopCard().getMove();
	    }
	    
	    if(st_id > MAX_SQUARE_ID )
	    {
	       st_id = st_id % 16;
	       displayMove( old_id, st_id, &st_lst, isCard, &pl_lst, p_id,
			    board, prison);
	       
	       if( st_id != prison.getStreetId() )
	       {
		  Start street = st_lst.getStreetById( 1 );
		  street.startTrigger( &pl_lst, p_id ); 
		  // get money to pass the start
	       }
	    }
	    
	    else
	    {
	       displayMove( old_id, st_id, &st_lst, isCard, &pl_lst, p_id,
			    board, prison);
	    }
	    
	 }

	 // ==> draw the borad
	 board.draw( cout );
      
	 //***************** here comes the playerOperation ***************//
	 playerOperation( &st_lst, st_id, &pl_lst, p_id, isQuit, no_of_player,
			  &prison, board, curr_pl_index );
      }
      curr_pl_index = (curr_pl_index + 1) % (pl_lst.size());


      //*************** quit command***********************//
      // to exit the game
   }
   if(no_of_player == QUIT_PLAYER )
   {
      cout << pl_lst.at(0).getPlayerName() << " won." << endl;
   }
   return EXIT_SUCCESS;
}


void displayMove( int old_id, int id, StreetList *st_lst, 
		  bool &isCard, PlayerList *pl_lst, char p_id, 
		  BoardDrawer &board, Prison &pr )
{
   if( id == pr.getStreetId() )
   {
      board.removePlayer(old_id, p_id );
      cout << "You moved to " << pr.getStreetName() <<"." << endl;
      (*pl_lst).setCurrentSquareById(p_id, id);
      board.addPlayer(id, p_id);
      isCard = false;
   }

   else
   {
      board.removePlayer(old_id, p_id);

      Start street = (*st_lst).getStreetById( id ); // get the street object
      cout << "You moved to " << street.getStreetName() <<"." << endl;

      (*pl_lst).setCurrentSquareById(p_id, id);
      
      board.addPlayer(id, p_id);

      if(street.getOwner() != '0' && street.getOwner() != p_id)
      {
	 // paying rent..
	 street.payRent( pl_lst, p_id );
      }
      if( street.getType() == "CARD" )
      {  
	 isCard = true;
      }
      else
      {
	 isCard = false;
      }
   }
}

void initialize(StreetList &st_lst, PlayCardList &pl_crd_lst,
		PlayerList &pl_lst, Prison &prison, string file,
		BoardDrawer &board )
{
   InitReader reader;

   reader.readFile( file );
   string name_of_board = reader.boardName();
   int start_money = reader.startMoney();

   InitReader::Streets strts = reader.getStreets();

   for( unsigned int j = 0; j < strts.size(); j++ )
   {
      if( strts.at(j).stype == "PRISON" )
      {
	 Prison jail( strts.at(j).id, strts.at(j).name,
		      strts.at(j).stype, strts.at(j).shackPrice,
		      strts.at(j).shackMax, strts.at(j).price );
	 prison = jail;
	 
	 board.addSquare(strts.at(j).name, strts.at(j).id,
                         strts.at(j).shackMax, '!', strts.at(j).price);
      }
      else
      {
	 st_lst.addStreet( strts.at(j).id, strts.at(j).name, strts.at(j).stype,
			   strts.at(j).shackPrice, strts.at(j).shackMax, 
			   strts.at(j).price );
	 
	 board.addSquare(strts.at(j).name, strts.at(j).id,
                         strts.at(j).shackMax, '-', strts.at(j).price);
      }
   }
   // ********************************************************** //
   // ********************************************************** //


   InitReader::Cards crds = reader.getCards();

   for(unsigned int i = 0; i < crds.size(); i++)
   {
      PlayCard pl_crd(crds.at(i).description, crds.at(i).money,
		      crds.at(i).prison, crds.at(i).move);
      pl_crd_lst.addPlayCard(pl_crd);
   }

   cout << name_of_board << endl;
   cout << "starting money: " << start_money << endl;

   addPlayerToGame(pl_lst, start_money);
}


void addPlayerToGame(PlayerList &pl_lst, int start_money)
{
   string name;
   char p_id = '1';

   for(int i = 1; i <= MAX_PLAYER; i++)
   {
      cout << "name of the player " << i << ": ";
      getline(cin, name);
      if(name == "")
      {
	 if(i <= MIN_PLAYER)
	 {
	    cout << "ERROR: Minimum number of players is two." << endl;
	    i--;
	 }
	 else
	 {
	    break;
	 }
      }
      else if( name.length() < MIN_NAME_LENGTH || 
	       name.length() > MAX_NAEM_LENGTH )
      {
	 cout << "ERROR: Name length incorrect" << endl;
	 i--;
      }
      else
      {
	 Player new_player(name, start_money, p_id++, false, 1);
	 if( pl_lst.verifyPlayer(new_player) )
	 {
	    pl_lst.addPlayer(new_player);
	 }
	 else
	 {
	    p_id--;
	    i--;
	 }
      }
   }
}


unsigned long throwDie()
{
   int seed = rand();
   Die di( seed );

   int val = di.cast();
   cout << "The die is cast: " << val << endl;

   return val;
}


void playerOperation( StreetList *st_lst, int st_id, PlayerList *pl_lst,
		      char p_id, bool &isQuit, int &no_of_player,
		      Prison *prison, BoardDrawer &board, int &curr_pl_index )
{  
   while( true )
   {
      cout << (*pl_lst).getPlayerById(p_id).getPlayerName() << " '" << p_id
	   << "' " << (*pl_lst).getPlayerById(p_id).getMoney() << "$ > ";
      
      string command = "";
      cin >> command;

      // execution of 'buy' command
      //============================
      if( command == "buy")
      {
	 if( (*prison).getStreetId() == st_id )
	 {
	    cout << "You cannot buy the square." << endl;
	    continue;
	 }
	 int ret_val = (*st_lst).getStreetById( st_id ).
	    buyStreet( pl_lst, p_id );
	 
	 switch( ret_val )
	 {
	    case CASE_0:	       
	       cout << "You bought "
		    << (*st_lst).getStreetById( st_id ).getStreetName() 
		    << endl;

	       // setting this player as the owner of the street
	       (*st_lst).setOwnerById( p_id, st_id );

	       // setting owner to the board
	       board.changeOwner( st_id, p_id );

	       break;
	       
	    case CASE_1:
	       cout << "You cannot buy the square." << endl;
	       break;
	       
	    case CASE_2:
	       cout << "You do not have enough money to buy the square." 
		    << endl;
	       break;
	    default:
	       break;
	 }
      }
     
      //execution of build command
      //==========================
      else if( command == "build" )
      {
	 int ret_val = (*st_lst).getStreetById( st_id ).
	    buildShack( pl_lst, p_id );
	 
	 switch( ret_val )
	 {
	    case CASE_0:
	       cout << "You built a new shack on " 
		    << (*st_lst).getStreetById( st_id ).getStreetName() 
		    << endl;

	       // building a new shack in that street
	       (*st_lst).buildShackById( st_id );

               // changes the number of shacks in the square
	       board.changeShacks( 
		  st_id, 
		  (*st_lst).getStreetById( st_id ).getCurrentNoOfShacks(),
		  (*st_lst).getStreetById( st_id ).getNoOfShacks() );

	       break;
	       
	    case CASE_1:
	       cout << "You do not own the square. "
		    << "You can only build on squares you own." << endl;
	       break;
	       
	    case CASE_2:
	       cout << "The square already has the maximum amount of shacks."
		    << endl;
	       break;
	       
	    case CASE_3:
	       cout << "You do not have enough money to build a new shack."
		    << endl;
	       break;

	    default:
               break;

	 }
      }
       

      //execution of 'bribe' command
      //============================
      else if( command == "bribe" )
      {
	 int ret_val = (*prison).giveBribe( pl_lst, p_id );
	 
	 switch( ret_val )
	 {
	    case CASE_0:
	       cout << "You bribe your way out of the prison." << endl;
	       break;
	       
	    case CASE_1:
	       cout << "Check your medication. You are not in prison." << endl;
	       break;
	       
	    case CASE_2:
	       cout << "You do not have enough money for a bribe." << endl;

	    default:
               break;

	 }
      }
  
      // execution of "board" command
      //================================
      else if( command == "board" )
      {
	 board.draw( cout );
      }
     
      // execution of 'next' command
      //============================
      else if( command == "next" )
      {
	 removeBankRupts( pl_lst, st_lst, board, no_of_player, curr_pl_index );
	   
	 return;                     // return to the main for next player turn
      }

      else if( command == "quit" )
      {
	 isQuit = true;
         return;                     // return to the main for next player turn
      }
 
   }
}


void removeBankRupts( PlayerList *pl_lst, StreetList *st_lst, 
		      BoardDrawer &board, int &no_of_player,
		      int &curr_pl_index )
{
   for( int i = 0 ; i < (*pl_lst).size() ; i++ )
   {
      char p_id = (*pl_lst).at(i).getPlayerId();
      
      if( (*pl_lst).at(i).getMoney() <= 0 )
      {
	 for( int j = 0 ; j < (*st_lst).size() ; j++ )
	 {
	    if ( (*st_lst).at(j).getOwner() == p_id )
	    {
	       (*st_lst).setOwnerById( '0', (*st_lst).at(j).getStreetId() );
	       (*st_lst).setNoOfShacksById( (*st_lst).at(j).getStreetId() );

	       board.changeOwner( (*st_lst).at(j).getStreetId(), '-' );

	       board.changeShacks(
                  (*st_lst).at(j).getStreetId(),0,
                  (*st_lst).getStreetById( (*st_lst).at(j).getStreetId() ).
		  getNoOfShacks() );

	       board.removePlayer((*pl_lst).at(i).getCurrentSquare(), p_id );
	    }
	 }
	 cout << (*pl_lst).at(i).getPlayerName() << " has been bankrupted."
	      << endl;
	 (*pl_lst).removePlayerById( p_id );
	 no_of_player--;
	 
	 if( i == curr_pl_index )
	 {
	    curr_pl_index--;
	 }
	 i--;
      } 
   }
}
