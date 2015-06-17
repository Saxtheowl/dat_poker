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
  
  std::cout << " pos is " << pos << std::endl;
  std::cout << " OKKKKK 11" << board->get_Standin_Players() << std::endl;
  std::cout << " OKKKKK 12" << board->get_Standin_Players() << std::endl;
  std::cout << " first card = " << board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() << std::endl;
  std::cout << " second card = " << board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() << std::endl;
  std::cout << " OKKKKK 13" << board->get_Standin_Players() << std::endl;
  if (board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() > 
      5 && board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() > 5)
    {
      board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
      if(board->get_Biggest_Raise() > 0)
	board->get_Competitors()[pos]->set_Pushed(board->get_Biggest_Raise());
      else
	board->set_Biggest_Raise(10);
      board->get_Competitors()[pos]->set_Played(true);
    }
  else
    {
      board->get_Competitors()[pos]->set_Standin(false);
      board->get_Competitors()[pos]->set_Played(true);
    }
  if(board->get_Step() == 3)
    {
      board->get_Competitors()[pos]->set_Standin(false);
    }
}
