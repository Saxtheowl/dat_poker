#ifndef _CARD_HH_
 #define _CARD_HH_

#include "enum.hpp"

class		Card
{
public:
  Card();
  ~Card();

  void	set_All(int n);
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
