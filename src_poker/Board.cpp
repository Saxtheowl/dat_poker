#include "Board.hh"
#include "Card.hh"
#include "enum.hh"
#include <stdlib.h>
#include <iostream>

Board::Board()
{
  idx_card = 0;
  flag_first_round = true;
  end_round = false;
}

Board::~Board()
{
  
}

void		Board::set_Mod(int mod)
{
  this->mod = mod;
}

int		Board::get_Mod()
{
  return (this->mod);
}

void		Board::set_start_nb_Players(int players)
{
  this->start_nb_players = players;
}

int		Board::get_Start_Nb_Players()
{
  return (this->start_nb_players);
}

void		Board::set_start_Stack(int start_stack)
{
  this->start_stack = start_stack;
}

int		Board::get_start_Stack()
{
  return (this->start_stack);
}

void		Board::init_Board() // cant deal 9 player by now
{
}

void		Board::init_Mod()
{
  int		i;
  
  i = 0;
  while (i < 53)
    {
      this->deck.push_back(new Card());
      i++;
    }
  init_Board();
}

void		Board::init_nb_Player()
{
  int		i;

  i = 0;
  while (i < this->start_nb_players)
    {
      if (i == 0)
	this->competitor.push_back(new Player(HUMAN, start_stack));
      this->competitor.push_back(new Player(BOT, start_stack));
      competitor[i]->set_Pos(i);
      competitor[i]->set_Button(false); // useless ?
      competitor[i]->set_Played(false);
      i++;
    }
  init_Player_Pos_X_Y();
}

void		Board::init_Player_Pos_X_Y()
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (i < 3)
	{	  
	  competitor[i]->set_Pos_Map((7 + i * 6), 6);
	}
      else
	{
	  competitor[i]->set_Pos_Map((7 + (i - 3) * 6), 86);
	}
      i++;
    }
}

bool		Board::not_on_the_deck(int i, int nb)
{
  int		f;

  f = 0;
  while (f < i)
    {
      if (deck[f]->get_Nb() == nb)
	return (false);
      f++;
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
	this->deck[i]->set_All(rd);
	i++;
	//	std::cout << "rd = " << rd << " true value " << temp << std::endl;
      }
      test++;
    }
  this->deck[52]->set_All('X'); // HAX
}

std::vector<Player*>		Board::get_Competitors()
{
  return (this->competitor);
}

bool		Board::check_Alive()
{
  return (true);
}

void		Board::fulfill_Board()
{
  int		i;

  i = 0;
  while (i < 6)
    {
      this->board_card.push_back(i);
      board_card[i] = idx_card;
      idx_card++;
      i++;
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
      this->button_pos = i;
    }
  else if(competitor[i]->get_Button() == true && flag_moved_button == false)
    {
      competitor[i]->set_Button(false);
      while(competitor[i + 1]->get_Stack() <= 0)
	{
	  i++;
	  if(i == 5)
	    i = -1;
	}
      flag_moved_button = true;
      competitor[i + 1]->set_Button(true);
      this->button_pos = i + 1;
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
  return(0);
}

void		Board::refresh_Alive()
{
  int		i;

  i = 0;
  this->alive_players = 0;
  while (i < 6)
    {
      if (competitor[i]->get_Stack() > 0 || competitor[i]->get_Pushed() > 0)
	{
	  this->alive_players++;
	  competitor[i]->set_Alive(true);
	}
      else
	competitor[i]->set_Alive(false);
      i++;
    }
}

void		Board::refresh_Standin()
{
  int		i;
  int		last;

  i = 0;
  this->standin_players = 0;
  while (i < 6)
    {
      if (competitor[i]->get_Standin() == true)
	{
	  this->standin_players++;
	  last = i;
	}
      i++;
    }
  if (this->standin_players == 1 && this->end_round == false)
    {
      end_round = true;
      competitor[last]->set_Stack(competitor[last]->get_Stack() + this->pot);
      this->pot = 0;
    }    
}

void		Board::reload_Round(int i)
{
  competitor[i]->set_Pushed(0);
  gime_Card(competitor[i], 1);
  move_Button(i);
}

void		Board::refresh_Pot()
{
  int		i;

  i = 0;
  this->pot = 0;
  while (i < 6)
    {
      this->pot = this->pot + competitor[i]->get_Pushed();
      i++;
    }
  pot = pot + old_pot;
}

int		Board::get_Pot()
{
  return (this->pot);
}

void		Board::second_Update()
{
  int		i;
  
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
      put_Small_Blind(this->button_pos);
      put_Big_Blind(this->button_pos);
    }
  else
    put_Headsup_Blind();
  refresh_Pot();
}

void		Board::burn_Card()
{
  this->idx_card++;
}

bool		Board::new_Round()
{
  int		i;
  int		alive_bot;
  
  i = 0;
  alive_bot = 0;
  this->alive_players = 0;
  idx_card = 0;
  set_Blind(10);
  this->biggest_raise = get_Blind();
  reset_Round();
  if (flag_first_round == true)
    {
      competitor[0]->set_Button(true);
      flag_first_round = false;
      flag_moved_button = true;
    }
  else
    {
      flag_moved_button = false;
    }
  shuffle_Deck();
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
  return (this->deck);
}

void				Board::set_Blind(int nb)
{
  this->blind = nb;
}

int				Board::get_Blind()
{
  return (this->blind);
}

bool				Board::put_Small_Blind(int i)
{
  i = get_Next_Alive(i);
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind / 2);
  competitor[i]->set_Stack(competitor[i]->get_Stack() - blind / 2);
  return (true);
}
  
bool				Board::put_Big_Blind(int i)
{
  i = get_Next_Alive(i);
  i = get_Next_Alive(i);
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind);
  competitor[i]->set_Stack(competitor[i]->get_Stack() - blind);
  return (true);
}

void				Board::put_Headsup_Blind()
{
  int				i;

  i = 0;
  while (competitor[i]->get_Button() == false)
    i++;
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind);
  competitor[i]->set_Stack(competitor[i]->get_Stack() - blind);
  i = get_Next_Alive(i);
  competitor[i]->set_Pushed(competitor[i]->get_Pushed() + blind / 2);
  competitor[i]->set_Stack(competitor[i]->get_Stack() - blind / 2);
}

bool				Board::run_Round() // ugly
{
  int				i;
  int				f;
  int				has_played;


  f = 0;
  has_played = 0;
  i = current_player;
  while (has_played < (this->standin_players))
    {
      if (competitor[i]->get_Pushed() == this->biggest_raise && competitor[i]->get_Played() == true)
	has_played++;
      else if (competitor[i]->get_Pushed() > this->biggest_raise)
	{
	  for (int g = 0; g < 6; g++)
	    competitor[g]->set_Played(false);
	  this->biggest_raise = competitor[i]->get_Pushed(); // useless ?
	  competitor[i]->set_Played(true);
	  has_played = 0;
	}
      i = get_Next_Standin(i);
      f++;
      if (f == this->standin_players && has_played < this->standin_players)
	return (false);
    }
  return (true);
}

int				Board::start_Round(int elapsed)//std::vector <bot_Ai*> bot_ai)
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
	return (0);
      else
	return (1);
    }
  else if (step < 3)
  {
    this->old_pot = pot;
    next_Step();
  }
  else
    Resolve();
  return(0);
}

int				Board::get_Standin_Players()
{
  return (this->standin_players);
}

int				Board::get_Current_Player()
{
  return (this->current_player);
}

int				Board::get_Button_Pos()
{
  return (this->button_pos);
}

void				Board::next_Step()
{
  int				i;

  i = 0;
  step++;
  std::cout << " next step OK " << std::endl;
  old_pot = pot;
  set_Biggest_Raise(0);
  while(current_player != this->button_pos)
    current_player = get_Next_Alive(button_pos);
  current_player = get_Next_Alive(button_pos);
  while (i < 6)// && competitor[i]->get_Standin() == true)
    {
      competitor[i]->set_Played(false);
      competitor[i]->set_Pushed(0);
      i++;
    }
  i = 0;
}

int				Board::get_Step()
{
  return (step);
}

void				Board::set_Biggest_Raise(int raise)
{
  this->biggest_raise = raise;
}

int				Board::get_Biggest_Raise()
{
  return (this->biggest_raise);
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
  this->old_pot = 0;
  end_round = false;
}

void				Board::Resolve()
{
  std::cout << " resolve start " << std::endl;
  //  competitor[0]->set_Stack(competitor[0]->get_Stack() + this->pot);
  std::cout << " stack to up " << competitor[0]->get_Stack() << std::endl;
  for (int i = 0; i < 5; i++)
    competitor[i]->set_Standin(false);      
  //  this->standin_players = 0;
}
