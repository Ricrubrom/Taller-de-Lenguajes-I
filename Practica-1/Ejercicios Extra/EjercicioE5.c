#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(0));
  int dados[2];
  int primerDados;
  dados[0] = rand() % 6 + 1;
  dados[1] = rand() % 6 + 1;
  primerDados = dados[0] + dados[1];
  if ((primerDados==7)||(primerDados==11)){
    printf("Felicidades, has ganado con %d", primerDados);
  }
  else while (1){
    if (((dados[0]+dados[1])==2)||((dados[0]+dados[1])==12)){
      printf("Perdiste con %d", dados[0] + dados[1]);
      break;
    } else if ((dados[0]+dados[1])==primerDados){
      printf("Ganaste tras conseguir %d por segunda vez", primerDados);
      break;
    }
  }
  return 0;
}