#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *fichero=fopen("Src/reporte_vinos.txt","r");
  FILE *a=fopen("Src/Ejercicio7_A.txt","w");
  FILE *b=fopen("Src/Ejercicio7_B.txt","w");
  FILE *c=fopen("Src/Ejercicio7_C.txt","w");
  char linea[200];
  while(!feof(fichero)){
    fputc(fgetc(fichero),a);
  }
  rewind(fichero);
  while (fgets(linea,200,fichero)!=NULL){
    fputs(linea, b);
  }
  rewind(fichero);
  size_t bytesRead;
  while((bytesRead = fread(linea, sizeof(char), 200, fichero))> 0){
    printf("%s", linea);
    fwrite(linea, sizeof(char), bytesRead, c);
  }
  return 0;
}