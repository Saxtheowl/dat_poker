#include <iostream>
#include <sstream>

int		toInt(std::string str)
{
  std::istringstream    buffer(str);
  int   i;

  buffer >> i;
  return (i);
}

int		get_Input()
{
  int		to_ret;
  std::string	str;

  std::cin >> str;
  to_ret = toInt(str);
  if (to_ret > 0)
    return (to_ret);
  else
    return (0);
}

int		main()
{

    int		a;
  std::string	b;
  
  while(42)
    {
      std::cout << " enter key " << std::endl;
      //      std::cin >> a;
      //      a = get_Input();
      std::cin >> a;
      std::cout << a << std::endl;
      }
}
