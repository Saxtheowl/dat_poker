#ifndef _CARD_HH_
 #define _CARD_HH_

#include "enum.hh"

class		Card
{
public:
  Card();
  ~Card();

  void	set_All(int nb);
  int	get_Nb();
  SUIT  get_Suit();
  char  get_Rank();
  int	get_True_Nb();

  void	set_Is_Given();
  bool	get_Is_Given();

private:

  bool	is_given;
  int	nb;
  int	rank;
  SUIT	suit;
};

#endif
