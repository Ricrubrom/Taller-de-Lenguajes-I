#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  int A[3][2];
  int B[3][2];
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      A[i][j] = rand() % 10;
      B[i][j] = rand() % 10;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      A[i][j] += B[i][j];
    }
  }
  return 0;
}