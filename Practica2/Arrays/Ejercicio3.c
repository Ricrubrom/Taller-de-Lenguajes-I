#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5
#define N 5

void fillMatrix(int matrix[M][N]){
  srand(time(0));
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      matrix[i][j] = rand()%10;
    }
  }
}

void multiply(int matrix[M][N], int C){
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      matrix[i][j] *= C;
    }
  }
  
}
void printMatrix(int matrix[M][N]){
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}


int main(){
  int matrix[M][N];
  fillMatrix(matrix);
  printMatrix(matrix);
  printf("\n  Multiplicando por 2 \n");
  multiply(matrix, 2);
  printMatrix(matrix);
  return 0;
}