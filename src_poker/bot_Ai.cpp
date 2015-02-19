#include "bot_Ai.hh"

bot_Ai::bot_Ai(int pos)
{
  this->pos = pos;
}

bot_Ai::~bot_Ai()
{
}
/*
void		bot_Ai::play_Bot(Board *board)
{
  int		i;
  int		f;
  f = 0;
  i = 0;
  i = board->get_Current_Player();
  if(pos == 4 || pos == 5)
    {
      while(f < board->get_Standin_Players())
	{
	  if(board->get_Competitors()[pos]->get_Pushed() < board->get_Competitors()[i]->get_Pushed() && board->get_Competitors()[pos]->get_Played() == false)
	    {
	      board->get_Competitors()[pos]->set_Pushed(10);
	      board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - 10);
	      board->get_Competitors()[pos]->set_Played(true);
	    }
	  i = board->get_Next_Standin(i);
	  f++;
	}
      //      board->get_Competitors()[pos]->set_Standin(true);
    }
  else
    {
      board->get_Competitors()[pos]->set_Standin(false);
      board->get_Competitors()[pos]->set_Played(true);
    }
}
*/
 /*
void		bot_Ai::play_Bot(Board *board)
{
  int		i;
  int		f;
  f = 0;
  i = 0;
  i = board->get_Current_Player();
  std::cout << " first card = " << board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() << std::endl;
  std::cout << " second card = " << board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() << std::endl;
  if(board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() > 5 && board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() > 5)
    {
      while(f < board->get_Standin_Players())
	{
	  if(board->get_Competitors()[pos]->get_Pushed() < board->get_Competitors()[i]->get_Pushed() && board->get_Competitors()[pos]->get_Played() == false)
	    {
	      board->get_Competitors()[pos]->set_Pushed(board->get_Biggest_Raise());
	      board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
	      board->get_Competitors()[pos]->set_Played(true);
	    }
	  else if(board->get_Competitors()[pos]->get_Pushed() == board->get_Blind() && board->get_Competitors()[pos]->get_Played() == false)
	    board->get_Competitors()[pos]->set_Played(true);
	  else if(board->get_Competitors()[pos]->get_Pushed() == (board->get_Blind() / 2) && board->get_Competitors()[pos]->get_Played() == false)
	    {
	      board->get_Competitors()[pos]->set_Pushed(10);
	      board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - 5);
	      board->get_Competitors()[pos]->set_Played(true);
	    }
	  i = board->get_Next_Standin(i);
	  f++;
	}
      //      board->get_Competitors()[pos]->set_Standin(true);
    }
  else
    {
      board->get_Competitors()[pos]->set_Standin(false);
      board->get_Competitors()[pos]->set_Played(true);
    }
}
 */

void		bot_Ai::play_Bot(Board *board)
{
  int		i;
  int		f;
  f = 0;
  i = 0;
  i = board->get_Current_Player();
  std::cout << " first card = " << board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() << std::endl;
  std::cout << " second card = " << board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() << std::endl;
  if(board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(0)]->get_True_Nb() > 5 && board->get_Deck()[board->get_Competitors()[pos]->get_Index_Card(1)]->get_True_Nb() > 5)
    {
      board->get_Competitors()[pos]->set_Stack(board->get_Competitors()[pos]->get_Stack() - (board->get_Biggest_Raise() - board->get_Competitors()[pos]->get_Pushed()));
      board->get_Competitors()[pos]->set_Pushed(board->get_Biggest_Raise());
      board->get_Competitors()[pos]->set_Played(true);
    }
  else
    {
      board->get_Competitors()[pos]->set_Standin(false);
      board->get_Competitors()[pos]->set_Played(true);
    }
}
