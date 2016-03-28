#ifndef _PLAYER_HH_
 #define _PLAYER_HH_

#include "enum.hh"
#include <iostream>
#include <vector>

class		Player
{
 public:
  Player(TYPE_PL type_pl, int start_stack);
  ~Player();
  void		set_Type_Pl(TYPE_PL type_pl);
  TYPE_PL	get_Type_Pl();
  void		set_Stack(int stack);
  int		get_Stack();

  void		set_Pos(int nb);
  int		get_Pos();

  void		set_Pos_Map(int x, int y);
  int		get_Pos_Map_X();
  int		get_Pos_Map_Y();

  void		set_Index_Card(int index, int nb);
  int		get_Index_Card(int nb);

  void		set_Button(bool ok);
  bool		get_Button();

  void		set_Alive(bool ok);
  bool		get_Alive();

  void		set_Standin(bool ok);
  bool		get_Standin();
  
  void		set_Pushed(int nb);
  int		get_Pushed();

  void		set_Played(bool ok);
  bool		get_Played();

  void		set_Hand_Showdown_Power_Twoplustwo(int nb);
  int		get_Hand_Showdown_Power_Twoplustwo();

  void		set_All_In(bool ok);
  bool		get_All_In();

private:
  TYPE_PL type_pl;
  int	stack;
  int	pushed;

  int	pos;
  int	pos_map[1];
  int	cards[1];
  //  int	idx_p[1];
  std::vector <int> pos_mapv;
  std::vector <int> idx_p;

  int	hand_showdown_power_twoplustwo;
  bool	button;
  bool	alive;
  bool	standin;
  bool	played;
  bool	all_in;
};

#endif
