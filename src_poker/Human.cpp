#include "Human.hh"

Human::Human()
{

}

Human::~Human()
{
}

bool		Human::play_Human(Board *board, int action)
{
  if(action == 1)
    {
      board->get_Competitors()[0]->set_Pushed(10);
      board->get_Competitors()[0]->set_Stack(board->get_Competitors()[0]->get_Stack() - 10);
      board->get_Competitors()[0]->set_Played(true);
      return(true);
    }
  else if(action == 2)
    {
      board->get_Competitors()[0]->set_Played(true);
      board->get_Competitors()[0]->set_Standin(false);
      return(true);
    }
  else if(action == 3)
    {
      board->get_Competitors()[0]->set_Played(true);
      board->get_Competitors()[0]->set_Standin(false);
      std::cout << " human fold OK " << std::endl;
      return(true);
    }
  std::cout << " error play human " << std::endl;
  return(false);
}
