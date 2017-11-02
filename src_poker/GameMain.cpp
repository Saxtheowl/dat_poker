#include <iostream>
#include <string>
#include <sstream>

#include "GameMain.hpp"
#include "bot_Ai.hpp"
#include "dat_Output.hpp"

GameMain::GameMain()
{
  
}

GameMain::~GameMain()
{
  
}

void		GameMain::Start()
{
  Menu();
  Initialize();
  start_Game();
}

void		GameMain::Menu()
{
  int		mod = 6;
  int		start_nb_players = 6;
  int		start_stack = 100;
  /*  std::cout << "What mod u want ?\n" << "0 - NO LIMIT HOLDEM\n" << std::endl;
  board->set_Mod(dat_input.get_Input());
  std::cout << "How many players u want ?\n" << "6 or 9\n" << std::endl;
  board->set_start_nb_Players(dat_input.get_Input());
  std::cout << "How many stack u want ?\n" << std::endl;
  board->set_start_Stack(dat_input.get_Input());*/
  board = new Board(mod, start_nb_players , start_stack);
  //  board->set_Mod(6);
  //  board->set_start_nb_Players(6);
  //  board->set_start_Stack(100);
}

void		GameMain::Initialize()
{
  dat_output = new dat_Output();
  human = new Human();
  for (int i = 0 ; i < board->get_Start_Nb_Players() - 1 ; i++)
    ai.push_back(new bot_Ai(i + 1));
  std::cout << "ok5" << std::endl;
}

void		GameMain::start_Game()
{
  char		key;

  std::cout << "ok7" << std::endl;
  while (board->new_Round() == true)
    {
      std::cout << "first update start" << std::endl;
      dat_output->first_Update(board);
      std::cout << "print start" << std::endl;
      dat_output->print_All(board, 0);
      std::cout << " press key to start " << std::endl;
      std::cin >> key;
      launch_Game();
      dat_output->clean_Card_Board();
      std::cout << " New round begin " << std::endl;
    }
  std::cout << "ok9" << std::endl;
}

void		GameMain::launch_Game()
{
  int		who_play;
  int		elapsed;
  char		key;

  elapsed = 0;
  std::cout << "ok3" << std::endl;
  while (board->get_Standin_Players() > 1)
    {
      who_play = board->start_Round(elapsed);
      if (who_play == 0 && board->get_Competitors()[0]->get_Standin() == true && board->get_Competitors()[0]->get_Stack() > 0)
	{
	  if(board->get_Step() > 0)
	    dat_output->print_All(board, 1);
	  dat_output->print_Player_Choice(board); // something to fix
	  while (!human->play_Human(board))
	    dat_output->print_Player_Choice(board);
	}
      else if(who_play > 0)
	ai[board->get_Current_Player() - 1]->play_Bot(board);
      elapsed++;
      board->dat_Refresh();
      dat_output->print_All(board, 1);
      std::cin >> key;
    }
}
