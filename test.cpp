#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

int		HR[32487834];

void				init_Hand_Evaluator_Twoplustwo()
{
  std::cout << " OK start TWOPLUSTWO " << std::endl;
  memset(HR, 0, sizeof(HR));
  FILE * fin = fopen("handrank.dat", "rb");
  // Load the HANDRANKS.DAT file data into the HR array
  size_t bytesread = fread(HR, sizeof(HR), 1, fin);
  fclose(fin);
  std::cout << " OK END TWOPLUSTWO " << std::endl;
}

int				get_Hand_Value(int *pCards)
{
  int p = HR[53 + *pCards++];

  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  return HR[p + *pCards++];
}

int		main()
{
}
