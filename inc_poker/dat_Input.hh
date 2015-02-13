#ifndef _DAT_INPUT_HH_
 #define _DAT_INPUT_HH_

#include <iostream>
#include <string>
#include <sstream>

class		dat_Input
{
public:
  dat_Input();
  ~dat_Input();

  int	toInt(std::string str);
  int	get_Input();
};

#endif
