// implementation file of PlayCard

#include "playcard.hh"

PlayCard::PlayCard()
{
}

PlayCard::PlayCard(string des, int mon, int pri, int mov)
{
   description = des;
   money = mon;
   prison = pri;
   move = mov;
}

PlayCard::~PlayCard()
{
}

void PlayCard::printCardDescription()
{
   cout << description << endl;
   cout << "money: " << money << endl;
   cout << "move: " << move << endl;
   cout << "prison: " << ( prison ? "YES" : "NO" ) << endl;
}

int PlayCard::getMoneyInCard()
{
   return money;
}

bool PlayCard::getPrisonInCard()
{
   return prison;
}

int PlayCard::getMove()
{
   return move;
}
