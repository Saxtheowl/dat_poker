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
      board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
      if(board->get_Biggest_Raise() > 0)
	{
	  board->get_Competitors()[pos]->set_Pushed(board->get_Biggest_Raise());
	}
      else
	{
	  std::cout << "CHECK" << std::endl;
	  //	  board->set_Biggest_Raise(10);
	  //	  board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
	}
      board->get_Competitors()[pos]->set_Played(true);
    }
  else
    {
      board->get_Competitors()[pos]->set_Standin(false);
      board->get_Competitors()[pos]->set_Played(true);
    }
  /*  if(board->get_Step() == 3 && board->get_Standin_Players() > 2) // FOLD A LA FIN LOL
    {
      std::cout << "OKK4" << std::endl;
      board->get_Competitors()[pos]->set_Standin(false);
      }*/
}
