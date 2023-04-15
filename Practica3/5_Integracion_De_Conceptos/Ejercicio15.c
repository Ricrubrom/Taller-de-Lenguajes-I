#include <stdio.h>
  typedef struct{
    int tipo : 4;
    union
    {
      struct
      {
        int radio;
      } Circulo;
      struct
      {
        int base;
        int altura;
      } Rectangulo;
      struct
      {
        int lado;
      } Cuadrado;
      struct
      {
        int radioMayor;
        int radioMenor;
      } Elipse;
      struct
      {
        int base;
        int altura;
      } Triangulo;
  } ;
  }Figura;

float area(Figura figura){
  switch (figura.tipo)
  {
  case 1:
    return 3.1416 * figura.Circulo.radio * figura.Circulo.radio;
    break;
  case 2:
    return figura.Rectangulo.base * figura.Rectangulo.altura;
    break;
  case 3:
    return figura.Cuadrado.lado * figura.Cuadrado.lado;
    break;
  case 4:
    return 3.1416 * figura.Elipse.radioMayor * figura.Elipse.radioMenor;
    break;
  case 5:
    return figura.Triangulo.base * figura.Triangulo.altura / 2;
    break;
  default:
    return 0;
    break;
  }
}

int main(){
    Figura figura;
    // Circulo
    figura.tipo = 1;
    figura.Circulo.radio = 5;
    printf("Area del circulo: %.2f\n", area(figura));
    // Rectangulo
    figura.tipo = 2;
    figura.Rectangulo.base = 5;
    figura.Rectangulo.altura = 10;
    printf("Area del rectangulo: %.2f\n", area(figura));
    // Cuadrado
    figura.tipo = 3;
    figura.Cuadrado.lado = 5;
    printf("Area del cuadrado: %.2f\n", area(figura));
    // Elipse
    figura.tipo = 4;
    figura.Elipse.radioMayor = 5;
    figura.Elipse.radioMenor = 10;
    printf("Area de la elipse: %.2f\n", area(figura));
    // Triangulo
    figura.tipo = 5;
    figura.Triangulo.base = 5;
    figura.Triangulo.altura = 10;
    printf("Area del triangulo: %.2f\n", area(figura));
    return 0;
}