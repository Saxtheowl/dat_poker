#include "Board.hpp"
#include "Card.hpp"
#include "enum.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

Board::Board(int m, int s_n_p, int s_s)
{
  mod = m;
  start_nb_players = s_n_p;
  start_stack = s_s;
  init_Hand_Evaluator_Twoplustwo();
  init_nb_Player();
  init_Deck();
}

Board::~Board()
{

}


int		Board::get_Mod()
{
  return (mod);
}

int		Board::get_Start_Nb_Players()
{
  return (start_nb_players);
}

int		Board::get_start_Stack()
{
  return (start_stack);
}

void		Board::init_Deck()
{
  for (int i = 0; i < 53; i++)
    deck.push_back(new Card());
}

void		Board::init_nb_Player()
{
  int		i;

  i = 0;
  while (i < start_nb_players)
    {
      if (i == 0)
	competitor.push_back(new Player(HUMAN, start_stack));
      competitor.push_back(new Player(BOT, start_stack));
      competitor[i]->set_Pos(i);
      competitor[i]->set_Button(false); // useless ?
      competitor[i]->set_Played(false);
      i++;
    }
  init_Player_Pos_X_Y();
}

void		Board::init_Player_Pos_X_Y()
{
  for (int i = 0; i < 6; i++)
    {
      if (i < 3)
	competitor[i]->set_Pos_Map((7 + i * 6), 6);
      else
	competitor[i]->set_Pos_Map((7 + (i - 3) * 6), 86);
    }
}

bool		Board::not_on_the_deck(int i, int nb)
{
  for (int f; f < i; f++)
    {
      if (deck[f]->get_Nb() == nb)
	return (false);
    }
  return (true);
}

void		Board::shuffle_Deck()
{
  int		i;
  int		test;
  int		rd;
  int		temp;

  test = 0;
  i = 0;
  while (i < 52)
    {
      rd = rand()%(1000);
      if (not_on_the_deck(i, rd) && rd < 52)
      {
	temp = rd;
	while (temp > 12)
	  temp = temp - 13;
	deck[i]->set_All(rd);
	i++;
      }
      test++;
    }
}

std::vector<Player*>		Board::get_Competitors()
{
  return (competitor);
}

bool		Board::check_Alive()
{
  return (true);
}

void		Board::fulfill_Board()
{
  for (int i = 0; i < 6; i++)
    {
      board_card.push_back(i);
      board_card[i] = idx_card;
      idx_card++;
    }
}

std::vector <int>		Board::get_Board_Cards()
{
  return (board_card);
}

void		Board::gime_Card(Player *player, int nb)
{
  int		to_del;

  to_del = 0;
  while (nb > -1 && to_del != 2)
    {
      player->set_Index_Card(idx_card, to_del);
      nb--;
      idx_card++;
      to_del++;
    }
}

void		Board::move_Button(int i)
{
  if (i == 5 && competitor[i]->get_Button() == true && flag_moved_button == false)
    {
      competitor[i]->set_Button(false);
      i = 0;
      while (competitor[i]->get_Stack() <= 0)
	i++;
      competitor[i]->set_Button(true);
      flag_moved_button = true;
      button_pos = i;
    }
  else if (competitor[i]->get_Button() == true && flag_moved_button == false)
    {
      competitor[i]->set_Button(false);
      while (competitor[i + 1]->get_Stack() <= 0)
	{
	  i++;
	  if (i == 5)
	    i = -1;
	}
      flag_moved_button = true;
      competitor[i + 1]->set_Button(true);
      button_pos = i + 1;
    }
}

int		Board::get_Next_Alive(int i)
{
  refresh_Alive();
  while (i < 5)
    {
      if (competitor[i + 1]->get_Alive() == true)
	return (i + 1);
      else
	i++;
    }
  return (0);
}

int		Board::get_Next_Standin(int i)
{
  refresh_Alive();
  while (i < 5)
    {
      if (competitor[i + 1]->get_Standin() == true)
	return (i + 1);
      else
	i++;
    }
  if(competitor[0]->get_Standin() == true)
    return (0);
  else
    {
      i = 0;
      while (i < 5)
	{
	  if (competitor[i + 1]->get_Standin() == true)
	    return (i + 1);
	  else
	    i++;
	} 
    }
  return (0);
}

void		Board::refresh_Alive()
{ 
  alive_players = 0;
  for (int i = 0; i < 6; i++)
    {
      if (competitor[i]->get_Stack() > 0 || competitor[i]->get_Pushed() > 0)
	{
	  alive_players++;
	  competitor[i]->set_Alive(true);
	}
      else
	competitor[i]->set_Alive(false);
    }
}

void		Board::refresh_Standin()
{
  int		last;

  standin_players = 0;
  for (int i = 0; i < 6; i++)
    {
      if (competitor[i]->get_Standin() == true )
	{
	  standin_players++;
	  last = i;
	}
    }
  if (standin_players == 1 && end_round == false)
    {
      end_round = true;
      competitor[last]->set_Stack(competitor[last]->get_Stack() + pot);
      pot = 0;
    }
}

void		Board::reload_Round(int i)
{
  competitor[i]->set_All_In(false);
  competitor[i]->set_Pushed(0);
  gime_Card(competitor[i], 1);
  move_Button(i);
  pot = 0;
}

void		Board::refresh_Pot()
{
  pot = 0;
  for (int i = 0; i < 6; i++)
    pot = pot + competitor[i]->get_Pushed();
  pot = pot + old_pot;
}

int		Board::get_Pot()
{
  return (pot);
}

void		Board::second_Update()
{
  int i;

  i = 0;
  refresh_Alive();
  if (alive_players > 1)
    {
      while (i < 6)
	{
	  competitor[i]->set_Pushed(0);
	  i++;
	}
      i = 0;
      put_Small_Blind(button_pos);
      put_Big_Blind(button_pos);
    }
  else
    put_Headsup_Blind();
  refresh_Pot();
}

void		Board::burn_Card()
{
  idx_card++;
}

void		Board::setup_Round()
{
  alive_players = 0;
  idx_card = 0;
  set_Blind(10);
  biggest_raise = get_Blind();
  reset_Round();
  if (flag_first_round == true)
    {
      competitor[0]->set_Button(true);
      flag_first_round = false;
      flag_moved_button = true;
    }
  else
    flag_moved_button = false;
  shuffle_Deck();

}

bool		Board::new_Round()
{
  int		i;
  int		alive_bot;
  
  i = 0;
  alive_bot = 0;
  setup_Round();
  if (competitor[0]->get_Stack() < 2)
    {
      std::cout << "Bot win" << std::endl;
      return(false);
    }
  while (i < start_nb_players)
    {
      if (competitor[i]->get_Stack() > 0)	
	{
	  if (competitor[i]->get_Type_Pl() == BOT)
	    alive_bot++;
	  reload_Round(i);
	  i++;
 	}
      else
	i++;
    }
  if (alive_bot > 0)
    {
      second_Update();
      refresh_Standin();
      return (true);
    }
  else
    {
      std::cout << "Human win" << std::endl;
      return (false);
    }
}

std::vector<Card*>		Board::get_Deck()
{
  return (deck);
}

void				Board::set_Blind(int n)
{
  blind = n;
}

int				Board::get_Blind()
{
  return (blind);
}

bool				Board::put_Small_Blind(int i)
{
  i = get_Next_Alive(i);
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind / 2);
  return (true);
}
  
bool				Board::put_Big_Blind(int i)
{
  i = get_Next_Alive(i);
  i = get_Next_Alive(i);
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind);
  return (true);
}

void				Board::put_Headsup_Blind()
{
  int				i;

  i = 0;
  while (competitor[i]->get_Button() == false)
    i++;
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind);
  i = get_Next_Alive(i);
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind / 2);
}

bool				Board::run_Round() // ugly
{
  int				i;
  int				f;
  int				has_played;

  f = 0;
  has_played = 0;
  std::cout << "run round running " << std::endl;
  i = current_player;
  while (has_played < (standin_players))
    {
      if ((competitor[i]->get_Pushed() == biggest_raise && competitor[i]->get_Played() == true ) || competitor[i]->get_Stack() == 0)
	has_played++;
      else if (competitor[i]->get_Pushed() > biggest_raise)
	{
	  for (int g = 0; g < 6; g++)
	    competitor[g]->set_Played(false);
	  biggest_raise = competitor[i]->get_Pushed();
	  competitor[i]->set_Played(true);
	  has_played = 0;
	}
      i = get_Next_Standin(i);
      f++;
      if (f == standin_players && has_played < standin_players)
	return (false);
    }
  if (step < 3)
    next_Step();
  else if (step == 3)
    {
      Resolve();
      return (true);
    }
  return (0);
}

int				Board::start_Round(int elapsed)
{
  if (elapsed == 0)
    {
      fulfill_Board();
      step = 0;
      current_player = button_pos;
      current_player = get_Next_Alive(current_player);
      current_player = get_Next_Alive(current_player);
    }
  if (run_Round() == false)
    {
      current_player = get_Next_Standin(current_player);
      if (current_player == 0 && competitor[0]->get_Standin() == true)
	{
	  std::cout << " start round : " << std::endl;
	  std::cout << " biggest raise = " << biggest_raise << std::endl;
	  std::cout << " competitor 00" << " get pushed = " << competitor[0]->get_Pushed() << std::endl;
	  return (0);
	}
      else
	return (1);
    }
  return (0);
}

int				Board::get_Standin_Players()
{
  return (standin_players);
}

int				Board::get_Current_Player()
{
  return (current_player);
}

int				Board::get_Button_Pos()
{
  return (button_pos);
}

void				Board::next_Step()
{
  int				i;

  i = 0;
  step++;
  std::cout << " next step OK " << std::endl;
  old_pot = pot;
  set_Biggest_Raise(0);
  current_player = button_pos;
  while (i < 6)// && competitor[i]->get_Standin() == true)
    {
      competitor[i]->set_Played(false);
      competitor[i]->set_Pushed(0);
      i++;
    }
  std::cout << " get_biggest_raise " << biggest_raise << std::endl;
  i = 0;
  for (int i = 0; i < 6; i++)
    {
      std::cout << " board get_pushed next step = " << competitor[i]->get_Pushed() << std::endl;
    }
}

int				Board::get_Step()
{
  return (step);
}

void				Board::set_Biggest_Raise(int raise)
{
  biggest_raise = raise;
}

int				Board::get_Biggest_Raise()
{
  return (biggest_raise);
}

void				Board::dat_Refresh()
{
  refresh_Alive();
  refresh_Standin();
  refresh_Pot();
}

void				Board::reset_Round()
{
  for (int i = 0; i < 6; i++)
    {
      if (competitor[i]->get_Stack() > 0)
	competitor[i]->set_Standin(true);
    }
  old_pot = 0;
  end_round = false;
}

void				Board::init_Hand_Evaluator_Twoplustwo()
{
  memset(HR, 0, sizeof(HR));
  FILE * fin = fopen("other/XPokerEval/linux/HandRanks.dat", "rb");
  if (fin == 0)
    {
      std::cout << " HandRanks.dat not found, run ""sh setup.sh"" then launch the game again "<< std::endl;
      exit(0);
    }
  fread(HR, sizeof(HR), 1, fin);      
  fclose(fin);
  std::cout << " OK END TWOPLUSTWO " << std::endl;
}

int				Board::get_Hand_Value(int *pCards)
{
  int p = HR[53 + *pCards++];

  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  return (HR[p + *pCards++]);
}

int				Board::get_fixed_Card_Twoplustwo(int card)
{

  if (card > 0 && card < 13)
    return ((card * 4) - 3);
  if (card > 13 && card < 26)
    return (((card - 13) * 4) - 2);
  if (card > 26 && card < 39)
    return (((card - 26) * 4) - 1);
  if(card > 39 && card < 52)
    return (((card - 39) * 4));
  if(card == 0) // fuck this
    return (49);
  if(card == 13)
    return (50);
  if(card == 26)
    return (51);
  if(card == 39)
    return (52);
  return (0);
}

void				Board::setup_Hand_Power()
{
  int				Card[7];
  int				handInfo;

  Card[2] = get_fixed_Card_Twoplustwo(deck[board_card[0]]->get_Nb());
  Card[3] = get_fixed_Card_Twoplustwo(deck[board_card[1]]->get_Nb());
  Card[4] = get_fixed_Card_Twoplustwo(deck[board_card[2]]->get_Nb());
  Card[5] = get_fixed_Card_Twoplustwo(deck[board_card[3]]->get_Nb());
  Card[6] = get_fixed_Card_Twoplustwo(deck[board_card[4]]->get_Nb());
  for (int i = 0; i < 6; i++)
    {
      std::cout << deck[competitor[i]->get_Index_Card(1)]->get_Nb() << std::endl;
      Card[0] = get_fixed_Card_Twoplustwo(deck[competitor[i]->get_Index_Card(0)]->get_Nb());
      Card[1] = get_fixed_Card_Twoplustwo(deck[competitor[i]->get_Index_Card(1)]->get_Nb());
      handInfo = get_Hand_Value(Card);
      competitor[i]->set_Hand_Showdown_Power_Twoplustwo(handInfo);
    }  
}

void				Board::Resolve()
{
  int				temp;

  setup_Hand_Power();
  std::cout << " resolve start " << std::endl;
  temp = 0;
  for (int i = 0; i < 6; i++)
    {
      if (competitor[i]->get_Standin() == true && competitor[i]->get_Hand_Showdown_Power_Twoplustwo() > temp)
	{
	  temp = competitor[i]->get_Hand_Showdown_Power_Twoplustwo();
	  winner_twoplustwo = i;
	}
      std::cout << " player " << i << " got " << competitor[i]->get_Hand_Showdown_Power_Twoplustwo() << std::endl;
    }
  std::cout << " winner is " << winner_twoplustwo << std::endl;
  std::cout << " resolve end " << std::endl;
  distribute_Pot();
}

void		Board::distribute_Pot()
{
  int		temp = 0;
  int		winner_nb = 1;

  for (int i = 0; i < 6; i++)
    {
      if (competitor[i]->get_Standin() == true && competitor[i]->get_Hand_Showdown_Power_Twoplustwo() > temp)
	{
	  temp = competitor[i]->get_Hand_Showdown_Power_Twoplustwo();
	  winner_nb = 1;
	}
      else if (competitor[i]->get_Standin() == true && competitor[i]->get_Hand_Showdown_Power_Twoplustwo() == temp)
	winner_nb++;
    }
  std::cout << " nb winners = " << winner_nb << std::endl;
  std::cout << " OK99" << std::endl;
  /*  if(winner_nb > 1)
    {
    // SEEM TO WORK
    }*/
  for (int i = 0; i < 6; i++)
    {
      if (competitor[i]->get_Standin() == true && competitor[i]->get_Hand_Showdown_Power_Twoplustwo() == temp)
	competitor[i]->set_Stack(competitor[i]->get_Stack() + (pot / winner_nb));
      competitor[i]->set_Standin(false);  
    }
}
