#include <stdio.h>
int main(){
    char palabra[20];
  int cant = 0;
  do
  {
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    if (palabra[strlen(palabra)-1]=='o'){
      cant++;
    }
  } while (strcmp(palabra, "XXX"));
  printf("La cantidad de palabras que terminan en 'o' es: %d", cant);
  return 0;
}