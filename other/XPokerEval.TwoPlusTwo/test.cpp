#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HR[32487834];

int InitTheEvaluator()
{
  memset(HR, 0, sizeof(HR));
  FILE *fin = fopen("HandRanks.dat", "rb");
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
  int myCards[] = { 2, 6, 12, 14, 23, 26, 29 };
  int handInfo = GetHandValue(myCards);
  printf("%d\n", handInfo);
  int handCategory = handInfo >> 12;
  printf("%d\n", handCategory);
  int rankWithinCategory = handInfo & 0x00000FFF;
  printf("%d\n", rankWithinCategory);
}

int		main()
{
  int		a;

  InitTheEvaluator();
  DoSomeWork();
}
