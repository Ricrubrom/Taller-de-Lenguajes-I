#include <stdio.h>
#include <stdlib.h>
int main(){
  int rows = 2;
  int columns = 3;
  int *array = (int *)malloc(rows * columns * sizeof(int));
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf("Inserte un numero: ");
      scanf("%d", (array + i*columns + j));
    }
  }
  
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      printf("%d ", array[i*columns+j]);
    }
    printf("\n");
  }

  free(array);
  return 0;
}