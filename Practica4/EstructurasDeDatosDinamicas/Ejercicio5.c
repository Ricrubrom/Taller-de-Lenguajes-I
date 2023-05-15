#include <stdio.h>
#include <stdlib.h>

#define TOTAL 10

void Carga(char *p);
void Procesamiento(char c, int * mayus, int * min);
void clear_buffer(int j);

int main(){
  char *p = (char *) malloc(sizeof(char) * 100);
  Carga(p);
  free(p);
  return 0;
}

void Carga(char *p){
  for (int i = 0; i < TOTAL; i++)
  {
    int mayus = 0;
    int min = 0;
    int j = 0;
    printf("\nInserte una oracion: ");
    fgets(p, 100, stdin);
    while ((p[j]!='\0' || p[j]!='\n' ) && j<100){
      Procesamiento(p[j], &mayus, &min);
      j++;
    }
    printf("\n%s  Cant Mayusculas: %d\n  Cant Minusculas: %d\n", p, mayus, min);
    clear_buffer(j);
  }
}

void Procesamiento(char c, int * mayus, int * min){
  if (c>=65 && c<=90){
    (*mayus)++;
  }
  else if (c>=97 && c<=122){
    (*min)++;
  }
}
void clear_buffer(int j){
  int c;
  if (j == 100)
  {
    while (getchar());
  }
}