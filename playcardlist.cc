// implementation file for PlayCardList

#include "playcardlist.hh"

PlayCardList::PlayCardList():top(0), no_of_card(0)
{
}

PlayCardList::~PlayCardList()
{
}

void PlayCardList::addPlayCard(PlayCard new_playcard)
{
   play_card_list.push_back(new_playcard);
   no_of_card++;
}

void PlayCardList::showCardInfo()
{
   play_card_list.at(top).printCardDescription();
   top = (top + 1) % no_of_card;
}

PlayCard PlayCardList::getTopCard()
{
   return play_card_list.at(top);
}
