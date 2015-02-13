#include "dat_Input.hh"
#include <iostream>
#include <string>
#include <sstream>

dat_Input::dat_Input()
{
}

dat_Input::~dat_Input()
{
}

int		dat_Input::toInt(std::string str)
{
  std::istringstream    buffer(str);
  int   i;

  buffer >> i;
  return (i);
}

int		dat_Input::get_Input()
{
  int		to_ret;
  std::string	str;

  std::cin >> str;
  to_ret = toInt(str);
  if(to_ret > 0)
    return(to_ret);
  else
    return(0);
}
