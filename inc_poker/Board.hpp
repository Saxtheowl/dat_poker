#ifndef _BOARD_HH_
 #define _BOARD_HH_

#include <iostream>
#include <vector>

#include "Card.hpp"
#include "Player.hpp"

class		Board
{
public:
  Board(int m, int s_n_p, int s_s);
  ~Board();

  int		get_Mod();
  int		get_Start_Nb_Players();
  int		get_start_Stack();
  void		set_Blind(int n);
  int		get_Blind();

  void		init_nb_Player();
  void		init_position_map();
  void		init_Deck();

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
  void		next_Step();
  void		fulfill_Board();
  std::vector <int> get_Board_Cards();
  int		get_Step();
  void		set_Biggest_Raise(int raise);
  int		get_Biggest_Raise();
  void		dat_Refresh();
  void		reset_Round();
  void		Resolve();
  void		distribute_Pot();

  void		init_Hand_Evaluator_Twoplustwo();
  int		get_Hand_Value(int *pCards);
  int		get_fixed_Card_Twoplustwo(int card);
  void		setup_Hand_Power();
  void		setup_Round();
private:
  std::vector <Player*> competitor;
  std::vector <Card*> deck;
  std::vector <int> board_card;

  int		mod;
  int		start_nb_players;
  int		start_stack;

  int		idx_card = 0;

  bool		flag_moved_button = false;
  bool		flag_first_round = true;
  bool		end_round = false;

  int		blind;
  int		alive_players;
  int		standin_players;
  int		pot;
  int		old_pot;
  int		current_player;
  int		button_pos;
  int		step;
  int		biggest_raise;
  int		HR[32487834];
  int		winner_twoplustwo;
};

#endif
