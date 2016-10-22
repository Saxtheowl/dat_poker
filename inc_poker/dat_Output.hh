#ifndef _DAT_OUTPUT_HH_
 #define _DAT_OUTPUT_HH_

#include "Board.hh"

class		dat_Output
{
private:
  std::vector<std::vector<char> > map;

  int		x_board;
  int		y_board;
  //  int		player_info_map[5][1];

public:
  dat_Output();
  ~dat_Output();

  void  fill_Corner();
  void  put_Static_Element();

  void	init_Map();
  void  print_All(Board *board, int flag);

  void	update_Cards(Board *board, Player *player);
  void	put_Cards(int card_pos_x, int card_pos_y, int first_card_value, int second_card_value, int pos);
  void	first_Update(Board *board);

  char	get_Rank_Symbol(int card_value);
  void	put_Card_Rank(int card_pos_x, int card_pos_y, char first_card_rank, char second_card_rank, int pos);

  void	put_Button(bool ok, int pos_p_x, int pos_p_y, int pos);

  void	put_Chips(int chips, int pos_p_x, int pos_p_y, int pos, int flag);
  void	clean_Chips(int pos_p_x, int pos_p_y, int pos, int flag);

  void	put_Cards_Shadow(int card_pos_x, int card_pos_y, int pos);
  void	clean_Cards_Shadow(int card_pos_x, int card_pos_y, int pos);
  void	put_Pot(int pot);
  void	clean_Pot();
  void	second_Update(Board *board);
  void	print_Player_Choice(Board *board);
  void	update_Card_Board(Board *board);
  void	print_Card_Board(int card_pos_y, int card_value);
  void	print_Rank_Card_Board(int card_pos_y, char rank);
  void	clean_Card_Board();
};

#endif
