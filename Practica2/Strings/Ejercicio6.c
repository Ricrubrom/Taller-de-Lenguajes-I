#include <stdio.h>
int main(){
  char letras[26] = {0};
  char cadena[20]="hola mundo";
  for (int i = 0; cadena[i]!='\0'; i++)
  {
    letras[cadena[i]-97]++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (letras[i]!=0)
      printf("%c: %d \n", i+97, letras[i]);
  }
  return 0;
}
