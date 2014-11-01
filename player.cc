// implementation file for Player

#include "player.hh"

Player::Player()
{
}

Player::Player(string name, int mon, char id, bool pri_status, int curr_sqr)
{
   name_of_player = name;
   money = mon;
   player_id = id;
   prison_status = pri_status;
   current_square = curr_sqr;
}

Player::~Player()
{
}

int Player::getCurrentSquare()
{
   return current_square;
}

void Player::setCurrentSquare(int current_sqr_id)
{
   current_square = current_sqr_id;
}

int Player::getMoney()
{
   return money;
}

void Player::setMoney(int mon)
{
   money = money + mon;
}

bool Player::getPrisonStatus()
{
   return prison_status;
}

void Player::setPrisonStatus(bool pri_status)
{
   prison_status = pri_status;
}

string Player::getPlayerName()
{
   return  name_of_player ;
}

char Player::getPlayerId()
{
   return player_id;
}
