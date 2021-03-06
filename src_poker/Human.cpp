#include "Human.hpp"
#include <string>
#include <sstream>

Human::Human()
{
}

Human::~Human()
{
}

int		Human::toInt(std::string str)
{
  std::istringstream    buffer(str);
  int   i;

  buffer >> i;
  return (i);
}

int		Human::get_Input()
{
  int		to_ret;
  std::string	str;

  std::cin >> str;
  to_ret = toInt(str);
  if (to_ret > 0)
    return (to_ret);
  else
    return (0);
}

bool		Human::play_Human(Board *board)
{
  int		action;

  action = get_Input();
  if (action == 1)
    {
      if(board->get_Biggest_Raise() > 0)
	board->get_Competitors()[0]->set_Pushed(board->get_Blind());
      board->get_Competitors()[0]->set_Played(true);
      return (true);
    }
  else if (action == 2)
    {
      int		amount = 0;
      
      while(amount > board->get_Competitors()[0]->get_Stack() ||
	    ( amount <= board->get_Biggest_Raise() && amount <= board->get_Blind() ))
	{
	  std::cout << " how much ? " << std::endl;
	  amount = get_Input();
	}
      board->get_Competitors()[0]->set_Pushed(amount);
      board->set_Biggest_Raise(amount);
      board->get_Competitors()[0]->set_Played(true);
      //      board->get_Competitors()[0]->set_Standin(true);
      std::cout << " amount Human " << amount << std::endl;
      return (true);
    }
  else if (action == 3)
    {
      board->get_Competitors()[0]->set_Played(true);
      board->get_Competitors()[0]->set_Standin(false);
      std::cout << " human fold OK " << std::endl;
      return (true);
    }
  std::cout << " error play human " << std::endl;
  return (false);
}
