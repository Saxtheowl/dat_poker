#include "Player.hh"
#include "enum.hh"

Player::Player(TYPE_PL type_p, int start_s)
{
  pos_mapv.resize(2);
  idx_p.resize(2);
  standin = true;
  type_pl = type_p;
  stack = start_s;
  pushed = 0;
  pushed_total = 0;
}

Player::~Player()
{
}

void		Player::set_Type_Pl(TYPE_PL type_p)
{
  type_pl = type_p;
}

TYPE_PL		Player::get_Type_Pl()
{
  return (type_pl);
}

void		Player::set_Stack(int s)
{
  stack = s;
  if (s < 0)
    stack = 0;
}

int		Player::get_Stack()
{
  return (stack);
}

void		Player::set_Pos(int n)
{
  this->pos = n;
}

int		Player::get_Pos()
{
  return(pos);
}

void		Player::set_Pos_Map(int x, int y)
{
  pos_mapv[0] = x;
  pos_mapv[1] = y;
}

int		Player::get_Pos_Map_X()
{
  return (pos_mapv[0]);
}

int		Player::get_Pos_Map_Y()
{
  return (pos_mapv[1]);
}

void		Player::set_Index_Card(int index, int nb)
{
  idx_p[nb] = index;
}

int		Player::get_Index_Card(int nb)
{
  return (idx_p[nb]);
}

void		Player::set_Button(bool b)
{
  button = b;
}

bool		Player::get_Button()
{
  return (button);
}

void		Player::set_Alive(bool a)
{
  alive = a;
}

bool		Player::get_Alive()
{
  return (alive);
}

void		Player::set_Pushed(int n)
{
  if(n > stack)
    pushed_total = pushed_total + (stack - (n));
  else
    pushed_total = pushed_total + n;
  if(stack < ( n - pushed))
    {
      pushed = stack;
      stack = 0;
    }
  else if(n > 0)
    {
      set_Stack(stack - (n - pushed));
      pushed = n;
    }
  else
    pushed = n;
}

int		Player::get_Pushed()
{
  return (pushed);
}

void		Player::set_Pushed_Total(int p)
{
  pushed_total = p;
}

int		Player::get_Pushed_Total()
{
  return(pushed_total);
}

void		Player::set_Standin(bool s)
{
  standin = s;

}

bool		Player::get_Standin()
{
  return (standin);
}

void		Player::set_Played(bool ok)
{
  played = ok;
}

bool		Player::get_Played()
{
  return (played);
}

void		Player::set_Hand_Showdown_Power_Twoplustwo(int n)
{
  hand_showdown_power_twoplustwo = n;
}

int		Player::get_Hand_Showdown_Power_Twoplustwo()
{
  return(hand_showdown_power_twoplustwo);
}

void		Player::set_All_In(bool a)
{
  all_in = a;
}

bool		Player::get_All_In()
{
  return(all_in);
}
