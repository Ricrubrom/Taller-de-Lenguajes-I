#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *f=fopen("Src/apuestas.txt", "r");
  int cod;
  double num,tot=0;
  while (fscanf(f, "%d|%lf;", &cod, &num) == 2)
  {
    tot += num;
  }
  printf("El monto total apostado es $%lf", tot);
  return 0;
}