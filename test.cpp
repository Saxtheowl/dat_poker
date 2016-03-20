#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int HR[32487834];

int InitTheEvaluator()
{
  memset(HR, 0, sizeof(HR));
  FILE *fin = fopen("handrank.dat", "rb");
  // Load the HANDRANKS.DAT file data into the HR arra
  size_t bytesread = fread(HR, sizeof(HR), 1, fin);
  fclose(fin);
}

int GetHandValue(int* pCards)
{
  int p = HR[53 + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  p = HR[p + *pCards++];
  return HR[p + *pCards++];
}

void DoSomeWork()
{
  //  int myCards[] = { 2, 12, 12, 14, 23, 26, 29 };
  int myCards[] = { 5, 6, 12, 30, 38, 1, 15 };
  int handInfo = GetHandValue(myCards);
  printf("%d\n", handInfo);
  int handCategory = handInfo >> 12;
  printf("%d\n", handCategory);
  int rankWithinCategory = handInfo & 0x00000FFF;
  printf("%d\n", rankWithinCategory);
}

int		ogogo(int card)
{
  
  if(card > 1 && card < 12)
    return((card * 4) - 3);
  if(card > 13 && card < 26)
    return(((card - 13) * 4) - 2);
  if(card > 26 && card < 39)
    return(((card - 26) * 4) - 1);
  if(card > 39 && card < 52)
    return(((card - 39) * 4));
  if(card == 0)
    return(49);
  if(card == 13)
    return(50);
  if(card == 26)
    return(51);
  if(card == 39)
    return(52);
  
    
}

int		main()
{

  for(int i = 0; i < 52; i++)
    std::cout << ogogo(i) << std::endl;
  //  InitTheEvaluator();
  //  DoSomeWork();



}
