#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int pos;
  int max;
} Max;

int main(){
  FILE *f=fopen("Src/precipitaciones.txt", "r");
  int cant;
  Max max;
  max.max = -1;
  char linea[10];
  int pos = 1;
  while(fscanf(f,"%d-",&cant)==1){
    if (cant>max.max){
      max.max = cant;
      max.pos = pos;
    }
    pos++;
  }
  printf("El dia con mayor precipitacion es el %d con %d mm\n", max.pos, max.max);
  return 0;
}