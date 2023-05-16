#include <stdio.h>
#include <stdlib.h>

int ** crearPiramide(int * n){
  printf("Ingrese el nivel: ");
  scanf("%d", n);
  int columns = 1;
  int** array;
  array = (int**) malloc((*n)*sizeof(int*));
  for (int i = 0; i<(*n); i++) {
    array[i] = (int*) malloc(columns*sizeof(int));
    if (columns>=3)
    {
      for (int j = 1; j < columns-1; j++)
      {
        array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
      }
    }
    array[i][0] = 1;
    array[i][columns-1] = 1;
    columns++;
  }
  return array;
}

void borrarPiramide(int n, int** M){ 
  for (int i = 0; i < n; i++) { 
    // Agregar espacios en blanco para centrar la fila 
    int espacios = n - i - 1; 
    for (int j = 0; j < espacios; j++) { 
      printf(" "); 
    } 
    // Imprimir los valores de la fila actual 
    for (int j = 0; j <= i; j++) { 
      printf("%d ", M[i][j]); 
    } 
    printf("\n"); 
  } 
}

void freeMem(int ***array, int n){
  for (int i = 0; i < n; i++)
  {
    free(*array[i]);
  }
  free(*array);
}


int main(){
  int n;
  int **array = crearPiramide(&n);
  borrarPiramide(n, array);
  freeMem(&array, n);
  return 0;
}