#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1
int main(){
  int x= 15;
  int y = 0;
  while (x<50){
    #if DEBUG
      printf("x= %d\n", x);
      y= y+1;
    #endif
    x++;
  }
  return 0;
}