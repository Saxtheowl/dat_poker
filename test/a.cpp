#include <iostream>
#include <sstream>

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
  while(42)
    {
      a = get_Input();
      std::cout << "ok" << std::endl;
      
    }
}
