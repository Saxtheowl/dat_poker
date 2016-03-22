#include "Player.hh"
#include "enum.hh"

Player::Player(TYPE_PL type_pl, int start_stack)
{
  this->pos_mapv.resize(2);
  this->idx_p.resize(2);
  this->standin = true;
  this->type_pl = type_pl;
  this->stack = start_stack;
}

Player::~Player()
{
}

void	Player::set_Type_Pl(TYPE_PL type_pl)
{
  this->type_pl = type_pl;
}

TYPE_PL Player::get_Type_Pl()
{
  return (this->type_pl);
}

void	Player::set_Stack(int stack)
{
  this->stack = stack;
  if (stack < 0)
    this->stack = 0;
}

int	Player::get_Stack()
{
  return (this->stack);
}

void	Player::set_Pos(int nb)
{
  this->pos = nb;
}

int	Player::get_Pos()
{
  return(pos);
}

void	Player::set_Pos_Map(int x, int y)
{
  this->pos_mapv[0] = x;
  this->pos_mapv[1] = y;
}

int     Player::get_Pos_Map_X()
{
  return (pos_mapv[0]);
}

int     Player::get_Pos_Map_Y()
{
  return (pos_mapv[1]);
}

void	Player::set_Index_Card(int index, int nb)
{
  this->idx_p[nb] = index;
}

int	Player::get_Index_Card(int nb)
{
  return (this->idx_p[nb]);
}

void	Player::set_Button(bool ok)
{
  this->button = ok;
}

bool	Player::get_Button()
{
  return (this->button);
}

void	Player::set_Alive(bool ok)
{
  this->alive = ok;
}

bool	Player::get_Alive()
{
  return (this->alive);
}

void	Player::set_Pushed(int nb)
{
  if (this->stack < nb)
    nb = this->stack;
  this->pushed = nb;
}

int	Player::get_Pushed()
{
  return (this->pushed);
}

void	Player::set_Standin(bool ok)
{
  this->standin = ok;
}

bool	Player::get_Standin()
{
  return (this->standin);
}

void	Player::set_Played(bool ok)
{
  this->played = ok;
}

bool	Player::get_Played()
{
  return (this->played);
}

void	Player::set_Hand_Showdown_Power_Twoplustwo(int nb)
{
  this->hand_showdown_power_twoplustwo = nb;
}

int	Player::get_Hand_Showdown_Power_Twoplustwo()
{
  return(this->hand_showdown_power_twoplustwo);
}
