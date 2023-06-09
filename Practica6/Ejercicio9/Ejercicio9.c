#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define DEBUG 0

int main(){
  int array[SIZE];
  int i;
  srand(time(NULL));
  for (i=0; i<SIZE; i++){
    array[i]=rand()%1000;
  }
  int j = Isearch(43, array);
  if (j==-1){
    printf("El numero no se encuentra en el array\n");
  }
  else{
    printf("El numero se encuentra en la posicion %d\n", j);
  }
  return 0;
}

int Isearch(int x, int * array){
  int i;
  int y = 0;
  for (i=0; i<SIZE; i++){
    #if DEBUG
      printf("Iteracion  n%d\n", i, y);
    #endif
    if (array[i]==x){
      return i;
    }
    y++;
  }
  return -1;
}