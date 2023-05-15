#include <stdio.h>
#include <stdlib.h>

void carga1(double *arreglo, double * tot, int n);
void carga2(double *arreglo, double * tot, int n);
void freeMem(double **arreglo1, double **arreglo2);

int main(){
  printf("Inserte un numero: ");
  int n;
  scanf("%d", &n);
  double *arreglo1 = (double *)malloc(sizeof(double) * n);
  double *arreglo2 = (double *)malloc(sizeof(double) * n);
  double tot1 = 0;
  double tot2 = 0;
  printf("\n");
  carga1(arreglo1, &tot1, n);
  printf("\n");
  carga1(arreglo2, &tot2, n);
  printf("\n");
  printf("Promedio 1: %.2lf \nPromedio 2: %.2lf", tot1/n, tot2/n);
  freeMem(&arreglo1, &arreglo2);
  return 0;
}


void carga1(double *arreglo, double * tot, int n){
  for (int i = 0; i < n; i++)
  {
    printf("Inserte un numero: ");
    scanf("%lf", &(arreglo[i]));
    *tot += arreglo[i];
  }
}

void carga2(double *arreglo, double * tot, int n){
  for (int i = 0; i < n; i++)
  {
    printf("Inserte un numero: ");
    scanf("%lf", (arreglo+i));
    *tot += *(arreglo+i);
  }
}

void freeMem(double **arreglo1, double **arreglo2){
  free(*arreglo1);
  free(*arreglo2);
}