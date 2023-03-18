#include <stdio.h>

#define CANT_PAISES 4
#define ESPECIES 40
int main(){
  int codigoPais[CANT_PAISES];
  int cantEspecies[CANT_PAISES];
  int cant = 0, min1 = 0, min2 = 1;
  for (int i = 0; i < CANT_PAISES; i++)
  {
    printf("Ingrese el codigo de pais: ");
    scanf("%d", &codigoPais[i]);
    printf("Ingrese la cantidad de especies para el pais: ");
    scanf("%d", &cantEspecies[i]);
    if (cantEspecies[i]>40)
      cant += 1;
  }
  for (int i = 2; i < CANT_PAISES; i++)
  {
    if (cantEspecies[i] < cantEspecies[min1]) {
      min2 = min1;
      min1 = i;
    }
    else if ((cantEspecies[i]>cantEspecies[min1])&&(cantEspecies[i]<cantEspecies[min2]))
      min2 = i;
  }
  printf("Los paises con menor cantidad de especies son: %d y %d \nEl porcentaje de paises con mas de 40 especies de pajaros es: %.2f", min1, min2, (float)cant * 100 / CANT_PAISES);
  return 0;
}