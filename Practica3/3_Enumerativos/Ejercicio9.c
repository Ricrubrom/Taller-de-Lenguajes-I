#include <stdio.h>

typedef enum {DOMINGO, LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO} dias;

void printDay1(dias d){
  switch(d){
    case DOMINGO:
      printf("Domingo\n");
      break;
    case LUNES:
      printf("Lunes\n");
      break;
    case MARTES:
      printf("Martes\n");
      break;
    case MIERCOLES:
      printf("Miercoles\n");
      break;
    case JUEVES:
      printf("Jueves\n");
      break;
    case VIERNES:
      printf("Viernes\n");
      break;
    case SABADO:
      printf("Sabado\n");
      break;
  }
}

void printDay2(dias d){
  char *days[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
  printf("%s\n", days[d]);
}

int main(){
  dias d = DOMINGO;
  printDay1(d);
  printDay2(d+1);
  return 0;
}