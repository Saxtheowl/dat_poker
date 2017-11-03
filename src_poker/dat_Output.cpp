#include "dat_Output.hpp"

dat_Output::dat_Output()
{
  init_Map();
}

dat_Output::~dat_Output()
{
}

void		dat_Output::print_All(Board *board, int flag)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  if (flag == 1)
    {
      first_Update(board);
      second_Update(board);
      update_Card_Board(board);
    }
  while (x < x_board)
    {
      while (y < y_board)
	{
	  std::cout << map[x][y];
	  y++;
	}
      y = 0;
      x++;
      std::cout << std::endl;
    }
}

void		dat_Output::put_Static_Element()
{
  map[PLAYER_0_X][PLAYER_0_Y] = 'P';
  map[PLAYER_0_X][PLAYER_0_Y + 1] = '6';
  map[PLAYER_1_X][PLAYER_1_Y] = 'P';
  map[PLAYER_1_X][PLAYER_1_Y + 1] = '5';
  map[PLAYER_2_X][PLAYER_2_Y] = 'P';
  map[PLAYER_2_X][PLAYER_2_Y + 1] = '4';
  map[PLAYER_3_X][PLAYER_3_Y] = 'P';
  map[PLAYER_3_X][PLAYER_3_Y + 1] = '1';
  map[PLAYER_4_X][PLAYER_4_Y] = 'P';
  map[PLAYER_4_X][PLAYER_4_Y + 1] = '2';
  map[PLAYER_5_X][PLAYER_5_Y] = 'P';
  map[PLAYER_5_X][PLAYER_5_Y + 1] = '3';

  map[4][45] = 'B';
  map[4][46] = 'A';
  map[4][47] = 'N';
  map[4][48] = 'K';
  
  map[7][PLAYER_0_Y + 3] = 'B'; // to put on non static

  map[8][5] = '[';
  map[8][9] = ']';
  map[8][11] = '[';
  map[8][15] = ']';

  map[14][5] = '[';
  map[14][9] = ']';
  map[14][11] = '[';
  map[14][15] = ']';

  map[20][5] = '[';
  map[20][9] = ']';
  map[20][11] = '[';
  map[20][15] = ']';

  map[8][89] = ']';
  map[8][85] = '[';
  map[8][83] = ']';
  map[8][79] = '[';

  map[14][89] = ']';
  map[14][85] = '[';
  map[14][83] = ']';
  map[14][79] = '[';

  map[20][89] = ']';
  map[20][85] = '[';
  map[20][83] = ']';
  map[20][79] = '[';

  map[14][33] = '[';
  map[14][37] = ']';
  map[14][39] = '[';
  map[14][43] = ']';
  map[14][45] = '[';

  map[14][49] = ']';
  map[14][51] = '[';
  map[14][55] = ']';
  map[14][57] = '[';
  map[14][61] = ']';  
}

void		dat_Output::fill_Corner()
{
  for (int i = 0; i < y_board; i++)
    {
      map[0][i] = 'X';
      map[25][i] = 'X';
    }
  for (int i = 0; i < x_board; i++)
    {
      map[i][0] = 'X';
      map[i][94] = 'X';
    }
}

void		dat_Output::init_Map()
{
  x_board = 26;
  y_board = 95;
  map.resize(x_board , std::vector<char>(y_board ,' '));
  fill_Corner();
  put_Static_Element();
}

char		dat_Output::get_Rank_Symbol(int card_value)
{
  char		c;
  
  c = 0;
  if (card_value < 12)
    c = 'a';
  else if (card_value < 25)
    c = 'b';
  else if (card_value < 38)
    c = 'c';
  else if (card_value < 52)
    c = 'd';
  return (c);
}

void		dat_Output::put_Card_Rank(int card_pos_x, int card_pos_y, char first_card_rank, char second_card_rank, int pos)
{
  if (pos < 3)
    {
      map[card_pos_x + 1][card_pos_y + 2] = first_card_rank;
      map[card_pos_x + 1][card_pos_y + 8] = second_card_rank;
    }
  else
    {
      map[card_pos_x + 1][card_pos_y + 2] = first_card_rank;
      map[card_pos_x + 1][card_pos_y - 4] = second_card_rank;
    }
}



void		dat_Output::put_Cards(int card_pos_x, int card_pos_y, int first_card_value, int second_card_value, int pos)
{
  char		c;

  if (pos < 3)
    {
      if (first_card_value >= 9)
	{
	  c = (first_card_value - 9) + '0';
	  map[card_pos_x + 1][card_pos_y] = '1';
	  map[card_pos_x + 1][card_pos_y + 1] = c;
	  c = (first_card_value - 9) + '0';
	}
      else
	{
	  c = (first_card_value + 1) + '0';
	  map[card_pos_x + 1][card_pos_y] = '0';
	  map[card_pos_x + 1][card_pos_y + 1] = c;
	}
      if (second_card_value >= 9)
	{
	  c = (second_card_value - 9) + '0';
	  map[card_pos_x + 1][card_pos_y + 6] = '1';
	  map[card_pos_x + 1][card_pos_y + 7] = c;
	  c = (second_card_value - 9) + '0';
	}
      else
	{
	  c = (second_card_value + 1) + '0';
	  map[card_pos_x + 1][card_pos_y + 6] = '0';
	  map[card_pos_x + 1][card_pos_y + 7] = c;
	}
    }
  else 
    {
      if (first_card_value >= 9)
	{
	  c = (first_card_value - 9) + '0';
	  map[card_pos_x + 1][card_pos_y] = '1';
	  map[card_pos_x + 1][card_pos_y + 1] = c;
	  c = (first_card_value - 9) + '0';
	}
      else
	{
	  c = (first_card_value + 1) + '0';
	  map[card_pos_x + 1][card_pos_y] = '0';
	  map[card_pos_x + 1][card_pos_y + 1] = c;
	}
      if (second_card_value >= 9)
	{
	  c = (second_card_value - 9) + '0';
	  map[card_pos_x + 1][card_pos_y - 6] = '1';
	  map[card_pos_x + 1][card_pos_y - 5] = c;
	  c = (second_card_value - 9) + '0';
	}
      else
	{
	  c = (second_card_value + 1) + '0';
	  map[card_pos_x + 1][card_pos_y - 6] = '0';
	  map[card_pos_x + 1][card_pos_y - 5] = c;
	}
    }
}

void		dat_Output::put_Button(bool is_button, int pos_p_x, int pos_p_y, int pos)
{
  if (pos < 3)
    {
      if (is_button == true)
	map[pos_p_x][pos_p_y + 3] = 'B';
      else
	map[pos_p_x][pos_p_y + 3] = ' ';
    }
  else
    if (is_button == true)
      map[pos_p_x][pos_p_y - 1] = 'B';
    else
      map[pos_p_x][pos_p_y - 1] = ' ';
  
}

void		dat_Output::clean_Chips(int pos_p_x, int pos_p_y, int pos, int flag)
{
  int		i;
  int		y;
  int		j;
  
  j = 0;
  if (pos < 3 && flag == 0)
    {
      i = -1;
      y = 2;
    }
  else if (flag == 0)
    {
      i = -3;
      y = 2;
    }
  if (pos < 3 && flag == 1)
    {
      y = 1;
      i = 11;
    }
  else if (flag == 1)
    {
      y = 1;
      i = -16;
    }
  while (j < 8)
    {
      map[pos_p_x + y][pos_p_y + i + j] = ' ';
      j++;
    }
}

void		dat_Output::put_Chips(int chips, int pos_p_x, int pos_p_y, int pos, int flag)
{
  int		power;
  int		save_nb;
  int		i;
  int		y;
  char		c;

  //  std::cout << "chips = " << chips << std::endl;
  power = 1;
  save_nb = chips;
  if (pos < 3 && flag == 0)
    {
      i = -1;
      y = 2;
    }
  else if (flag == 0)
    {
      i = -3;
      y = 2;
    }
  if (pos < 3 && flag == 1)
    {
      y = 1;
      i = 11;
    }
  else if (flag == 1)
    {
      y = 1;
      i = -16;
    }
  while (chips >= 10)
    {
      power = power * 10;
      chips = chips / 10;
    }
  while (power > 0)
    {
      c = save_nb / power;
      save_nb = save_nb % power;
      map[pos_p_x + y][pos_p_y + i] = (c + '0');
      power = power / 10;
      i++;
    }
}

void		dat_Output::put_Pot(int	pot)
{
  int		power;
  int		save_nb;
  int		i;
  char		c;

  i = 0;
  save_nb = pot;
  power = 1;
  while (pot >= 10)
    {
      power = power * 10;
      pot = pot / 10;
    }
  while (power > 0)
    {
      c = save_nb / power;
      save_nb = save_nb % power;
      map[6][43 + i] = (c + '0');
      power = power / 10;
      i++;
    }
}

void		dat_Output::clean_Pot()
{
  map[6][43] = ' ';
  map[6][44] = ' ';
  map[6][45] = ' ';
  map[6][46] = ' ';
  map[6][47] = ' ';

}

void		dat_Output::put_Cards_Shadow(int card_pos_x, int card_pos_y, int pos)
{
  if (pos < 3)
    {
      map[card_pos_x + 1][card_pos_y] = 'X';
      map[card_pos_x + 1][card_pos_y + 1] = 'X';
      map[card_pos_x + 1][card_pos_y + 2] = 'X';
      map[card_pos_x + 1][card_pos_y + 6] = 'X';
      map[card_pos_x + 1][card_pos_y + 7] = 'X';
      map[card_pos_x + 1][card_pos_y + 8] = 'X';
    }
  else 
    {
      map[card_pos_x + 1][card_pos_y] = 'X';
      map[card_pos_x + 1][card_pos_y + 1] = 'X';
      map[card_pos_x + 1][card_pos_y + 2] = 'X';
      map[card_pos_x + 1][card_pos_y - 6] = 'X';
      map[card_pos_x + 1][card_pos_y - 5] = 'X';
      map[card_pos_x + 1][card_pos_y - 4] = 'X';
    }
}

void		dat_Output::clean_Cards_Shadow(int card_pos_x, int card_pos_y, int pos)
{
    if (pos < 3)
    {
      map[card_pos_x + 1][card_pos_y] = ' ';
      map[card_pos_x + 1][card_pos_y + 1] = ' ';
      map[card_pos_x + 1][card_pos_y + 2] = ' ';
      map[card_pos_x + 1][card_pos_y + 6] = ' ';
      map[card_pos_x + 1][card_pos_y + 7] = ' ';
      map[card_pos_x + 1][card_pos_y + 8] = ' ';
    }
  else 
    {
      map[card_pos_x + 1][card_pos_y] = ' ';
      map[card_pos_x + 1][card_pos_y + 1] = ' ';
      map[card_pos_x + 1][card_pos_y + 2] = ' ';
      map[card_pos_x + 1][card_pos_y - 6] = ' ';
      map[card_pos_x + 1][card_pos_y - 5] = ' ';
      map[card_pos_x + 1][card_pos_y - 4] = ' ';
    }
}

void		dat_Output::update_Cards(Board *board, Player *player)
{
  //    if(player->get_Pos() == 0)
  if (1 + 1 == 2)
      {
	put_Cards(player->get_Pos_Map_X(), player->get_Pos_Map_Y(), board->get_Deck()[player->get_Index_Card(0)]->get_True_Nb(), board->get_Deck()[player->get_Index_Card(1)]->get_True_Nb(), player->get_Pos());
	put_Card_Rank(player->get_Pos_Map_X(), player->get_Pos_Map_Y(), board->get_Deck()[player->get_Index_Card(0)]->get_Rank(), board->get_Deck()[player->get_Index_Card(1)]->get_Rank(), player->get_Pos());
      }
    else if (player->get_Alive() == true && (player->get_Stack() > 0 || player->get_Pushed() > 0))
    put_Cards_Shadow(player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos());
  else if (player->get_Alive() == false)
    clean_Cards_Shadow(player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos());
  put_Button(player->get_Button(), player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos());
  
  clean_Chips(player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos(), 0);
  if (player->get_Stack() > 0)
    put_Chips(player->get_Stack(), player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos(), 0);
  
  clean_Chips(player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos(), 1);
  //  int t = player->get_Pushed();
  if (player->get_Pushed() > 0)
    put_Chips(player->get_Pushed(), player->get_Pos_Map_X(), player->get_Pos_Map_Y(), player->get_Pos(), 1);
  put_Pot(board->get_Pot());
  clean_Pot();
  //  std::cout << " get pushed dat output " << t << std::endl;
}

void		dat_Output::first_Update(Board *board)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      update_Cards(board, board->get_Competitors()[i]); // to rename
      i++;
    }
}

void		dat_Output::print_Player_Choice(Board *board)
{
  if(board->get_Biggest_Raise() > 0)
    std::cout << " 1 - CALL\n" << std::endl;
  else
    std::cout << " 1 - CHECK\n" << std::endl;
  std::cout << " 2 - RAISE\n" << std::endl;
  std::cout << " 3 - FOLD\n" << std::endl;
}

void		dat_Output::second_Update(Board *board)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (board->get_Competitors()[i]->get_Standin() == false)
	clean_Cards_Shadow(board->get_Competitors()[i]->get_Pos_Map_X(), board->get_Competitors()[i]->get_Pos_Map_Y(), board->get_Competitors()[i]->get_Pos());
      put_Pot(board->get_Pot());
      i++;
    }
}

void		dat_Output::update_Card_Board(Board *board)
{

  //  std::cout << " ok 1 step = 1 " << std::endl;
  std::cout << " step =  " << board->get_Step() << std::endl;
  if (board->get_Step() == 1)
    {
      print_Card_Board(34, board->get_Deck()[board->get_Board_Cards()[0]]->get_True_Nb());
      print_Rank_Card_Board(36, board->get_Deck()[board->get_Board_Cards()[0]]->get_Rank());
      print_Card_Board(40, board->get_Deck()[board->get_Board_Cards()[1]]->get_True_Nb());
      print_Rank_Card_Board(42, board->get_Deck()[board->get_Board_Cards()[1]]->get_Rank());
      print_Card_Board(46, board->get_Deck()[board->get_Board_Cards()[2]]->get_True_Nb());
      print_Rank_Card_Board(48, board->get_Deck()[board->get_Board_Cards()[2]]->get_Rank());
    }
  else if (board->get_Step() == 2)
    {
      print_Card_Board(52, board->get_Deck()[board->get_Board_Cards()[3]]->get_True_Nb());
      print_Rank_Card_Board(54, board->get_Deck()[board->get_Board_Cards()[3]]->get_Rank());
    }
  else if (board->get_Step() == 3)
    {
      print_Card_Board(58, board->get_Deck()[board->get_Board_Cards()[4]]->get_True_Nb());
      print_Rank_Card_Board(60, board->get_Deck()[board->get_Board_Cards()[4]]->get_Rank());
    }
}

void		dat_Output::print_Card_Board(int card_pos_y, int card_value)
{
  char		c;

  std::cout << " ok 2 step = 1 " << std::endl;
  if (card_value >= 9)
    {
      c = (card_value - 9) + '0';
      map[14][card_pos_y] = '1';
      map[14][card_pos_y + 1] = c;
    }
  else
    {
      c = (card_value + 1) + '0';
      map[14][card_pos_y] = '0';
      map[14][card_pos_y + 1] = c;
    }
}

void		dat_Output::print_Rank_Card_Board(int card_pos_y, char rank)
{
  map[14][card_pos_y] = rank;
}

void		dat_Output::clean_Card_Board()
{
  int		i;
  int		f;
  int		j;

  j = 34;
  i = 0;
  f = 0;
  while (i < 6)
    {
      while (f < 3)
	{
	  map[14][34 + f + (i * 6)] = ' ';
	  f++;
	}
      j = j + 6;
      f = 0;
      i++;
    }
}
