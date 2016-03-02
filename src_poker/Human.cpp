#include "Human.hh"

Human::Human()
{

}

Human::~Human()
{
}

bool		Human::play_Human(Board *board, int action)
{
  if (action == 1)
    {
      board->get_Competitors()[0]->set_Pushed(10);
      board->get_Competitors()[0]->set_Stack(board->get_Competitors()[0]->get_Stack() - 10);
      std::cout << " new stack human = " << board->get_Competitors()[0]->get_Stack() << std::endl;
      board->get_Competitors()[0]->set_Played(true);
      return (true);
    }
  else if (action == 2)
    {
      /*
      board->get_Competitors()[0]->set_Pushed(20);
      board->get_Competitors()[0]->set_Stack(board->get_Competitors()[0]->get_Stack() - 20);
      board->set_Biggest_Raise(20);*/
      std::cout << " how much ? " << std::endl;
      board->get_Competitors()[0]->set_Played(true);
      board->get_Competitors()[0]->set_Standin(true);
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
