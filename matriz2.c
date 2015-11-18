#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LIN 10
#define COL 10

int main()
{
  int i, j;

  srand(getpid());

  int m1[LIN][COL];
  int m2[LIN][COL];
  int m3[LIN][COL];

  for(i = 0; i < COL; i++)
    for(j = 0; j < COL; j++)
    {
      m1[i][j] = rand() % 9;
      m2[i][j] = rand() % 9;
      m3[i][j] = 0;
    }

  for(i = 0; i < LIN; i++)
    for(j = 0; j < COL; j++)
      m3[i][j] = m1[i][j] + m2[i][j];

  printf("\n");
  for(i = 0; i < LIN; i++)
  {
    for(j = 0; j < COL; j++)
      printf("%d ", m1[i][j]);
    printf("\t");

    for(j = 0; j < COL; j++)
      printf("%d ", m2[i][j]);
    printf("\t"); 
 
    for(j = 0; j < COL; j++)
      printf("%2d ", m3[i][j]);
    printf("\n"); 

  }
  printf("\n");

  return 0;
}
