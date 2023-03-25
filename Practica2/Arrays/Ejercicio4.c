#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  int m1[2][2];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      m1[i][j] = rand() % 10;
    }
  }
  int m2[2][2];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      m2[i][j] = m1[j][i];
    }
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%d ", m1[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%d ", m2[i][j]);
    }
    printf("\n");
  }
  return 0;
}