#include <stdio.h>
#include <stdlib.h>

int main(){
  srand(2);
  for (int i = 0; i < 15; i++)
  {
    printf("%d \n", rand());
  }
  return 0;
}

/*
  Siempre que se use la misma semilla va a generar la misma secuencia de numeros, para que esto no pase se tienen que usar semillas distintas.
  Una forma seria con una variable que vaya cambiando su valor mientras se ejecute el programa, lo cual nos aseguraria que no se use la misma semilla siempre
*/