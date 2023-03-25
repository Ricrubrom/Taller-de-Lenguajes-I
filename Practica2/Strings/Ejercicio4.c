#include <stdio.h>

int strLen(char cadena[]);

int main(){
  char cadena[13] = "Hola mundo";
  printf("%d", strLen(cadena));
  return 0;
}

int strLen(char cadena[]){
  int i;
  while (*cadena!='\0')
  {
    i++;
    cadena++;
  }
  return i;
}