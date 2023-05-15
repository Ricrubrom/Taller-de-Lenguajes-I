#include <stdio.h>
#include <stdlib.h>

int *reserveMem(int *n, int *m);
void arrayInit(int *array, int n);
void printMult(int *array, int n);
void freeMem(int **array);

int main(){
  int n, m;
  int *array = reserveMem(&n, &m);
  arrayInit(array, n*m);
  printMult(array, n*m);
  freeMem(&array);
  return 0;
}

int * reserveMem(int *n, int *m){
  printf("Inserte un numero: ");
  scanf("%d", n);
  printf("Inserte un numero: ");
  scanf("%d", m);
  int *aux = (int *)malloc((*n)*(*m)*sizeof(int));
  printf("\n\n");
  return aux;
}

void arrayInit(int *array, int n){
  for (int i = 0; i < n; i++)
  {
    printf("Inserte un numero: ");
    scanf("%d", (array+i));
  }
}

void printMult(int *array, int n){
  for (int i = 0; i < n; i++)
  {
    if (array[i]%3==0){
      printf("%d, ", i);
    }
  }
}

void freeMem(int **array){
  free(*array);
}