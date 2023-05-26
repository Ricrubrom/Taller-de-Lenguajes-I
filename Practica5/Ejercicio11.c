#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *fichero=fopen("Src/tenistas.dat","rb");
  fseek(fichero,0,SEEK_END);
  printf("El tamaño del archivo es %ld bytes\n",ftell(fichero));
  return 0;
}