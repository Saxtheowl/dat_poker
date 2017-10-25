#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "GameMain.hpp"

int		main()
{
  GameMain	gameMain;

  srand(time(NULL));
  gameMain.Start();
}
