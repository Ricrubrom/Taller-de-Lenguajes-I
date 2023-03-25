#include <stdio.h>

char* strCpy(char cadena1[], char cadena2[]);

int main(){
  char cadena1[11] = "Hola mundo";
  char cadena2[11];
  printf("%s\n", strCpy(cadena1, cadena2));
  printf("%s", cadena1);
  return 0;
}

char *strCpy(char cadena1[], char cadena2[]){
  int i = 0;
  while (cadena1[i]!='\0')
  {
    cadena2[i] = cadena1[i];
    i++;
  }
  cadena2[i] = '\0';
  return cadena2;
}