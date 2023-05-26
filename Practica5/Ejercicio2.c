#include <stdio.h>
#include <stdlib.h>

#define LENGTH 300

int main(){
  FILE *f=fopen("Src/prueba.txt", "r");
  char linea[LENGTH];
  int mayus = 0;
  int min = 0;
  int dig = 0;
  if (f == NULL){
    printf ("\nError al abrir archivo fuente\n");
    return 1;
  }
  while (fgets(linea,LENGTH,f)!=NULL){
    int i = 0;
    while (linea[i])
    {
      if (linea[i]>='A' && linea[i]<='Z')
        mayus++;
      else if(linea[i]>='a' && linea[i]<='z')
        min++;
      else if(linea[i]>='0' && linea[i]<='9')
        dig++;
      i++;
    }
  }
  printf("Mayusculas: %d\nMinusculas: %d\nDigitos: %d\n", mayus, min, dig);
  return 0;
}