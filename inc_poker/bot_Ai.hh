#ifndef _BOT_AI_HH_
 #define _BOT_AI_HH_

#include "Board.hh"

class		bot_Ai
{
public:
  bot_Ai(int pos);
  ~bot_Ai();

  void	play_Bot(Board *board);
private:
  int	pos;
  int	raise;
  
};

#endif
