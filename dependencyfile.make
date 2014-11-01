boarddrawer.o: boarddrawer.cc boarddrawer.hh utility.hh
card.o: card.cc card.hh square.hh playcardlist.hh playcard.hh \
  playerlist.hh player.hh
CardStreet.o: CardStreet.cc CardStreet.hh Street.hh square.hh \
  playerlist.hh player.hh playcardlist.hh playcard.hh card.hh
CardStreetList.o: CardStreetList.cc CardStreetList.hh Start.hh Street.hh \
  square.hh playerlist.hh player.hh playcardlist.hh playcard.hh \
  CardStreet.hh card.hh
chopper.o: chopper.cc chopper.hh initexception.hh
die.o: die.cc die.hh
gameboard.o: gameboard.cc boarddrawer.hh chopper.hh initexception.hh \
  die.hh initreader.hh utility.hh player.hh playerlist.hh playcard.hh \
  playcardlist.hh square.hh Street.hh Prison.hh Start.hh StreetList.hh
initreader.o: initreader.cc initreader.hh initexception.hh utility.hh
playcard.o: playcard.cc playcard.hh
playcardlist.o: playcardlist.cc playcardlist.hh playcard.hh
player.o: player.cc player.hh
playerlist.o: playerlist.cc playerlist.hh player.hh
Prison.o: Prison.cc Prison.hh square.hh playerlist.hh player.hh
square.o: square.cc square.hh
Start.o: Start.cc Start.hh Street.hh square.hh playerlist.hh player.hh \
  playcardlist.hh playcard.hh
Street.o: Street.cc Street.hh square.hh playerlist.hh player.hh \
  playcardlist.hh playcard.hh
StreetList.o: StreetList.cc StreetList.hh Start.hh Street.hh square.hh \
  playerlist.hh player.hh playcardlist.hh playcard.hh
utility.o: utility.cc utility.hh chopper.hh initexception.hh
