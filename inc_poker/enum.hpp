#ifndef _ENUM_HH_
 #define _ENUM_HH_

enum SUIT
  {
    SPADE,
    HEART,
    DIAMOND,
    CLUB,
  };

enum RANK
  {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
  };

enum TYPE_PL
  {
    HUMAN,
    BOT,
  };

enum POS_MAP
  {
    PLAYER_0_X = 7,
    PLAYER_0_Y = 6,
    
    PLAYER_1_X = 13,
    PLAYER_1_Y = 6,    
    
    PLAYER_2_X = 19,
    PLAYER_2_Y = 6,    

    PLAYER_3_X = 7,
    PLAYER_3_Y = 87,

    PLAYER_4_X = 13,
    PLAYER_4_Y = 87,    

    PLAYER_5_X = 19,
    PLAYER_5_Y = 87,
  };

#endif
