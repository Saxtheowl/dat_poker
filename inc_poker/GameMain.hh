#ifndef _GAMEMAIN_HH_
 #define _GAMEMAIN_HH_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Board.hh"
#include "dat_Input.hh"
#include "dat_Output.hh"
#include "bot_Ai.hh"
#include "Human.hh"

class		GameMain
{
public:
  GameMain();
  ~GameMain();

  void		Start();
  void		Initialize();
  void		init_Ai();
  void		Menu();
  void		start_Game();
  void		launch_Game();
  void		play_Human();
private:
  Board		*board;
  dat_Input	dat_input;
  dat_Output	*dat_output;
  Human		*human;

  std::vector	<bot_Ai*> ai;
};

#endif

// NO LIMIT HOLDEM
// OMAHA
// CASH GAME
// TOURNEY
