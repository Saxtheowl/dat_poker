#ifndef _HUMAN_HH_
 #define _HUMAN_HH_

#include "Board.hh"
#include <string>
#include <sstream>

class		Human
{
public:
  Human();
  ~Human();

  bool  play_Human(Board *board, int action);
  bool  play_Human(Board *board);
  int	toInt(std::string str);
  int	get_Input();
private:
  
};

#endif
