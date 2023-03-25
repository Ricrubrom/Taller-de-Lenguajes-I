#include <stdio.h>
#include <string.h>
int main(){
  char palabra[20];
  int cant = 0;
  do
  {
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    if (strlen(palabra)==5){
      cant++;
    }
  } while (strcmp(palabra, "ZZZ"));
  printf("La cantidad de palabras de 5 letras es: %d", cant);
  return 0;
}