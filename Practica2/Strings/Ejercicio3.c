#include <stdio.h>
#include <string.h>

char* Replace(char cadena[], char c1, char c2);

int main(){
  char cadena[11] = "Hola mundo";
  char c1 = 'o';
  char c2 = 'X';
  printf("%s \n", Replace(cadena, c1, c2));
  return 0;
}

char* Replace(char cadena[], char c1, char c2){
  for (int i = 0; cadena[i]!='\0'; i++)
  {
    if (cadena[i]==c1)
      cadena[i] = c2;
  }
  return cadena;
}