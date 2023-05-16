#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  printf("Inserte un numero: ");
  scanf("%d", &n);
  int j = 1;
  int *array = (int *)malloc(j*sizeof(int));
  array[0] = 1;
  for (int i = 2; i <= n/2; i++)
  {
    if (n%i==0){
      j++;
      array = realloc(array, j * sizeof(int));
      array[j-1] = i;
    }
  }
  j++;
  array = realloc(array, j * sizeof(int));
  array[j-1] = n;
  printf("\n%d : (%d", n, array[0]);
  for (int i = 1; i < j; i++)
  {
    printf(", %d", array[i]);
  }
  printf(")");
  free(array);
  return 0;
}