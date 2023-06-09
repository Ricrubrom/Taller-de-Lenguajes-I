#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
  int tot = 0;
  printf("\nargc = %d",argc);
  for (int i = 1; i <= argc-1; i++)
  {
    tot+=atoi(argv[i]);
  }
  printf("\ntot= %d",tot);
  printf("\nEl promedio es: %.2lf",((double)tot)/(argc-1));
  return 0;
}