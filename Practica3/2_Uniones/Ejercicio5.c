#include <stdio.h>

typedef union dim
{
  struct
  {
    struct
    {
      unsigned x1, y1;
    };
    struct
    {
      unsigned x2, y2;
    };
  } forma1;
  struct
  {
    struct
    {
      unsigned x, y;
    };
    struct
    {
      unsigned ancho, alto;
    };
  } forma2;
  struct
  {
    unsigned x, y, ancho, alto;
  } forma3;
}dim;

int main(){
  dim d;
  d.forma1.x1 = 1;
  d.forma1.y1 = 2;
  d.forma1.x2 = 3;
  d.forma1.y2 = 4;
  printf("%d %d %d %d \n", d.forma1.x1, d.forma1.y1, d.forma1.x2, d.forma1.y2);
  d.forma2.x=5;
  d.forma2.y=6;
  d.forma2.ancho=7;
  d.forma2.alto=8;
  printf("%d %d %d %d\n", d.forma2.x, d.forma2.y, d.forma2.ancho, d.forma2.alto);
  d.forma3.x=9;
  d.forma3.y=10;
  d.forma3.ancho=11;
  d.forma3.alto=12;
  printf("%d %d %d %d\n", d.forma3.x, d.forma3.y, d.forma3.ancho, d.forma3.alto);
  return 0;
}