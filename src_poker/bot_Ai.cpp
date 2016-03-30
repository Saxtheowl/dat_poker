#include "bot_Ai.hh"

bot_Ai::bot_Ai(int pos)
{
  this->pos = pos;
}

bot_Ai::~bot_Ai()
{
}

void		bot_Ai::play_Bot(Board *board)
{
  std::cout << "bot" << pos << " is playing " << std::endl;
  if (board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() > 
      5 && board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() > 5)
    {
      if(board->get_Competitors()[pos]->get_Pushed() < board->get_Biggest_Raise())
	{
	  std::cout << "bot CALL get Pushed = " << board->get_Competitors()[pos]->get_Pushed() << " get biggest Raise = " << board->get_Biggest_Raise() << std::endl;
	  std::cout << "bot CALL" << std::endl;
	  board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
	  board->get_Competitors()[pos]->set_Pushed(board->get_Biggest_Raise());
	  std::cout << "bot CALL" << std::endl;
	}
      else
	{
	  std::cout << "bot CHECK" << std::endl;
	  //	  board->set_Biggest_Raise(10);
	  //	  board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
	}
      board->get_Competitors()[pos]->set_Played(true);
    }
  else
    {
      std::cout << "bot FOLD PREFLOP" << std::endl;
      board->get_Competitors()[pos]->set_Standin(false);
      board->get_Competitors()[pos]->set_Played(true);
    }
  /*  if(board->get_Step() == 3) // FOLD A LA FIN LOL
    {
      std::cout << "OKK4" << std::endl;
      board->get_Competitors()[pos]->set_Standin(false);
      }*/
}
