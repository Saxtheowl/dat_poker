#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "GameMain.hh"

int		main()
{
  GameMain	gameMain;

  srand(time(NULL));
  gameMain.Start();
}
