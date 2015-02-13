#ifndef _BOARD_HH_
 #define _BOARD_HH_

#include <iostream>
#include <vector>

#include "Card.hh"
#include "Player.hh"

class		Board
{
public:
  Board();
  ~Board();

  void		set_Mod(int mod);
  int		get_Mod();
  void		set_start_nb_Players(int players);
  int		get_Start_Nb_Players();
  void		set_start_Stack(int start_stack);
  int		get_start_Stack();
  void		set_Blind(int nb);
  int		get_Blind();

  void		init_nb_Player();
  void		init_position_map();
  void		init_player_Stack();
  void		init_Mod();
  void		init_Board();

  bool		not_on_the_deck(int i, int nb);
  void		shuffle_Deck();

  std::vector<Player*>	get_Competitors();

  bool		check_Alive();
  void		reload_Round(int i);
  bool		new_Round();
  void		gime_Card(Player *player, int nb);

  void		burn_Card();
  void		move_Button(int i);

  void		init_Player_Pos_X_Y();
  std::vector <Card*>	get_Deck();

  bool		put_Small_Blind(int i);
  bool		put_Big_Blind(int i);
  void		second_Update();
  int		get_Next_Alive(int i);
  int		get_Next_Standin(int i);
  void		refresh_Alive();
  void		refresh_Standin();
  void		put_Headsup_Blind();
  void		refresh_Pot();
  int		get_Pot();

  int		start_Round(int f);//std::vector <bot_Ai*> ai);
  int		get_Standin_Players();
  int		get_Current_Player();
  int		get_Button_Pos();

  bool		run_Round();
  bool		next_Step();
  void		fulfill_Board();
  std::vector <int> get_Board_Cards();
  int		get_Step();
private:
  std::vector <Player*> competitor;
  std::vector <Card*> deck;
  std::vector <int> board_card;

  int		mod;
  int		start_nb_players;
  int		start_stack;

  int		idx_card;

  int		x_board;
  int		y_board;

  bool		flag_moved_button;
  bool		flag_first_round;

  int		blind;
  int		alive_players;
  int		standin_players;
  int		pot;
  int		old_pot;
  int		current_player;
  int		button_pos;
  int		step;
};

#endif
