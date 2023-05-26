#include <stdio.h>
#include <stdlib.h>

#define LONG 300

int main(){
  FILE *f;
  char linea[LONG];
  // Abrir el archivo
  f = fopen("Src/prueba.txt", "r");
  if (f == NULL){
    printf ("\nError al abrir archivo fuente\n");
    return 1;
  }
  while (fgets(linea,LONG,f)!=NULL){
    puts(linea);
  }
  fclose(f);
  return 0;
}
