#include <iostream>
#include <string>
#include <sstream>
#include "GameMain.hh"
#include "bot_Ai.hh"
#include "dat_Input.hh"
#include "dat_Output.hh"

GameMain::GameMain()
{
}

GameMain::~GameMain()
{
}

void		GameMain::Start()
{
  Initialize();
  Menu();
  start_Game();
}

void		GameMain::Initialize()
{
  board = new Board();
  dat_output = new dat_Output();
  human = new Human();
}

void		GameMain::init_Ai()
{
  int		i;

  i = 0;
  while (i < board->get_Start_Nb_Players() - 1)
    {
      this->ai.push_back(new bot_Ai(i + 1));
      i++;
    }
}

void		GameMain::Menu()
{
  /*  std::cout << "What mod u want ?\n" << "0 - NO LIMIT HOLDEM\n" << std::endl;
  board->set_Mod(dat_input.get_Input());
  std::cout << "How many players u want ?\n" << "6 or 9\n" << std::endl;
  board->set_start_nb_Players(dat_input.get_Input());
  std::cout << "How many stack u want ?\n" << std::endl;
  board->set_start_Stack(dat_input.get_Input());*/
  board->set_Mod(6);
  board->set_start_nb_Players(6);
  board->set_start_Stack(100);
  board->init_nb_Player();

  dat_output->init_Map();
  board->init_Mod();
  init_Ai();
}

void		GameMain::start_Game()
{
  char		key;

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
}

void		GameMain::play_Human()
{
  
}

void		GameMain::launch_Game()
{
  int		who_play;
  int		elapsed;
  char		key;

  elapsed = 0;
  while (board->get_Standin_Players() > 1)
    {
      who_play = board->start_Round(elapsed);
      if (who_play == 0)
	{
	  dat_output->print_Player_Choice(); // something to fix
	  while (!human->play_Human(board, dat_input.get_Input()))
	    dat_output->print_Player_Choice();
	}
      else
	{
	  ai[board->get_Current_Player() - 1]->play_Bot(board);
	}
      elapsed++;
      board->dat_Refresh();
      dat_output->print_All(board, 1);
      std::cin >> key;
    }
}
