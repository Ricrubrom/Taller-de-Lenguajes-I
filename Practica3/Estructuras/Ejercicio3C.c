#include <stdio.h>

#define LENGTH 4

typedef struct pun3D{
  float x;
  float y;
  float z;
} punto3D;

int main(){
  printf("sizeof(punto3D): %d", sizeof(punto3D));
  printf("\nsizeof(struct pun3D): %d", sizeof(struct pun3D));
  punto3D p[LENGTH];
  for (int i = 0; i < LENGTH; i++)
  {
    printf("\nInserte x: ");
    scanf("%f", &p[i].x);
    printf("Inserte y: ");
    scanf("%f", &p[i].y);
    printf("Inserte z: ");
    scanf("%f", &p[i].z);
  }
  for (int i = 0; i < LENGTH; i++)
  {
    printf("size: ", sizeof(p));
  }
  return 0;
}