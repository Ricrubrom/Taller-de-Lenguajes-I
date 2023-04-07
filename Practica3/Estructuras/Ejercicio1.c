#include <stdio.h>

#define LENGTH 3

typedef struct rectangulo{
  float base;
  float altura;
} rectangulo;


  rectangulo ini(rectangulo rec);
float area(  rectangulo rec);

int main(){
    rectangulo rec[LENGTH];
  float max = -1;
  for (int i = 0; i < LENGTH; i++)
  {
    rec[i] = ini(rec[i]);
    if (area(rec[i])>max){
      max = area(rec[i]);
    };
  }
  printf("maximo: %f", max);
  return 0;
}


  rectangulo ini(rectangulo rec)
{
  printf("\nInserte altura: ");
  scanf("%f", &rec.altura);
  printf("Inserte base: ");
  scanf("%f", &rec.base);
  return rec;
}

float area(rectangulo rec){
  return rec.altura * rec.base;
}