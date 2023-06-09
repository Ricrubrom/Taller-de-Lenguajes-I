#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define AREA(r) PI*(r)*(r)

int main(){
  srand(time(NULL));
  for (int i=0; i<10; i++){
    int r=(rand()%10)+1;
    printf("\nArea de un circulo de radio %d: %.2lf", r, AREA(r));
  }
  return 0;
}