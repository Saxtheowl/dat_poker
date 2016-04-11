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
	}
      board->get_Competitors()[pos]->set_Played(true);
    }
}
