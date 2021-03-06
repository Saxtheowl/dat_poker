#ifndef _PLAYER_HH_
 #define _PLAYER_HH_

#include "enum.hpp"
#include <iostream>
#include <vector>

class		Player
{
 public:
  Player(TYPE_PL type_p, int start_s);
  ~Player();
  void		set_Type_Pl(TYPE_PL type_p);
  TYPE_PL	get_Type_Pl();
  void		set_Stack(int s);
  int		get_Stack();

  void		set_Pos(int n);
  int		get_Pos();

  void		set_Pos_Map(int x, int y);
  int		get_Pos_Map_X();
  int		get_Pos_Map_Y();

  void		set_Index_Card(int index, int nb);
  int		get_Index_Card(int nb);

  void		set_Button(bool is_button);
  bool		get_Button();

  void		set_Alive(bool is_alive);
  bool		get_Alive();

  void		set_Standin(bool is_standin);
  bool		get_Standin();
  
  void		set_Pushed(int n);
  int		get_Pushed();
  void		set_Pushed_Total(int p);
  int		get_Pushed_Total();
  
  void		set_Played(bool has_played);
  bool		get_Played();

  void		set_Hand_Showdown_Power_Twoplustwo(int n);
  int		get_Hand_Showdown_Power_Twoplustwo();

  void		set_All_In(bool is_all_in);
  bool		get_All_In();

private:
  TYPE_PL type_pl;
  int	stack;
  int	pushed;
  int	pushed_total;

  int	pos;
  int	pos_map[1];
  int	cards[1];
  int	dead_chips;
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
