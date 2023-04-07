#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define AMMOUNT 48
const char *Palos[4] = {"Oros", "Copas", "Espadas", "Bastos"};

typedef struct carta{
  char palo[30];
  char valor[10];
} carta;

void barajar(carta mazo[AMMOUNT]);
carta getCarta(carta mazo[AMMOUNT],carta c);
void imprimirCarta(carta c);

int main(){
  carta mazo[AMMOUNT];
  srand(time(NULL));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 9; j++) {
        strcpy(mazo[i*12+j].palo, Palos[i]);
        sprintf(mazo[i*12+j].valor, "%d", j+1);
    }
    strcpy(mazo[i*12+9].palo, Palos[i]);
    strcpy(mazo[i*12+9].valor, "Sota");
    strcpy(mazo[i*12+10].palo, Palos[i]);
    strcpy(mazo[i*12+10].valor, "Caballo");
    strcpy(mazo[i*12+11].palo, Palos[i]);
    strcpy(mazo[i*12+11].valor, "Rey");
}

  barajar(mazo);
  for (int i = 0; i < AMMOUNT; i++) {
    printf("\n%s de %s", mazo[i].valor, mazo[i].palo);
  }
  printf("\n");
  carta c;
  strcpy(c.palo, "Oros");
  strcpy(c.valor, "5");
  carta c2 = getCarta(mazo, c);
  imprimirCarta(c2);
  return 0;
}

void barajar(carta mazo[AMMOUNT]){
  carta aux;
  int i, j;
  for (int i = 0; i < AMMOUNT; i++) {
    j = rand() % AMMOUNT;
    aux = mazo[i];
    mazo[i] = mazo[j];
    mazo[j] = aux;
  }
}

carta getCarta(carta mazo[AMMOUNT],carta c){
  for (int i = 0; i < AMMOUNT; i++) {
    if (strcmp(mazo[i].palo, c.palo) == 0 && strcmp(mazo[i].valor, c.valor) == 0) {
      return mazo[i];
    }
  }
}

void imprimirCarta(carta c){
  printf("\n%s de %s", c.valor, c.palo);
}