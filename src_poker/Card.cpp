#include "Card.hh"
#include "enum.hh"

Card::Card()
{
  this->is_given = false;
}

Card::~Card()
{
}

void	Card::set_All(int nb)
{
  int	temp;

  temp = nb;
  this->nb = nb;
  if (temp < 12)
    suit = SPADE;
  else if (temp < 25)
    suit = HEART;
  else if (temp < 38)
    suit = DIAMOND;
  else
    suit = CLUB;
  while (temp > 12)
    temp = temp - 12;
  rank = temp;
}

int	Card::get_Nb()
{
  return (nb);
}

SUIT	Card::get_Suit()
{
  return (suit);
}

char	Card::get_Rank()
{
  if (this->nb < 12)
    return ('a');
  else if (this->nb < 25)
    return ('b');
  else if (this->nb < 38)
    return ('c');
  else if (this->nb < 52)
    return ('d');
}

void	Card::set_Is_Given()
{
  this->is_given = true;
}

bool	Card::get_Is_Given()
{
  return (is_given);
}

int	Card::get_True_Nb()
{
  int	temp;
  
  temp = this->nb;
  while (temp > 12)
    temp = temp - 13;
  return (temp);
}
