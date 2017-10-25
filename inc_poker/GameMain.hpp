#ifndef _GAMEMAIN_HH_
 #define _GAMEMAIN_HH_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Board.hpp"
#include "dat_Output.hpp"
#include "bot_Ai.hpp"
#include "Human.hpp"

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
  void		init_All();
private:
  Board		*board;
  dat_Output	*dat_output;
  Human		*human;

  std::vector	<bot_Ai*> ai;
};

#endif

// NO LIMIT HOLDEM
// OMAHA
// CASH GAME
// TOURNEY
