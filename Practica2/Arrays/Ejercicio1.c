#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  int nums[50],impares=0,pares=0;
  for (int i = 0; i < 50; i++)
  {
    nums[i] = rand();
    if (nums[i]%2==0 && i%2==1)
      pares++;
    else if (nums[i]%2==1 && i%2==0)
      impares++;
  }
  printf("Pares en impares: %d\nImpares en pares: %d", pares, impares);
  return 0;
}