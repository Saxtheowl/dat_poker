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

<<<<<<< HEAD
  bool  play_Human(Board *board, int action);
=======
  bool  play_Human(Board *board);
>>>>>>> 34044947cbfa9d39c8375be308e2477d2c44104d
  int	toInt(std::string str);
  int	get_Input();
private:
  
};

#endif
