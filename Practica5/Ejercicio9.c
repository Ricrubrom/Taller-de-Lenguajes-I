#include <stdio.h>
#include <stdlib.h>

#define LONG 300
#define CANT 2

typedef struct{
  char nombre[20];
  char apellido[20];
  int edad;
  int titulos;
  int ranking;
  float fortuna;
} Tenista;

int main(){
  FILE *fichero=fopen("Src/tenistas.dat","wb+");
  Tenista tenista;
  for (int i = 0; i < CANT; i++)
  {
    printf("Ingrese el nombre del tenista: ");
    scanf("%s",tenista.nombre);
    printf("Ingrese el apellido del tenista: ");
    scanf("%s",tenista.apellido);
    printf("Ingrese la edad del tenista: ");
    scanf("%d",&tenista.edad);
    printf("Ingrese la cantidad de titulos del tenista: ");
    scanf("%d",&tenista.titulos);
    printf("Ingrese el ranking del tenista: ");
    scanf("%d",&tenista.ranking);
    printf("Ingrese la fortuna del tenista: ");
    scanf("%f",&tenista.fortuna);
    fwrite(&tenista,sizeof(Tenista),1,fichero);
  }
  Tenista maxRanking;
  maxRanking.ranking = 9999;
  Tenista maxTitulos;
  maxTitulos.titulos = -1;
  fclose(fichero);
  fichero=fopen("Src/tenistas.dat","rb");
  for (int i = 0; i < CANT; i++)
  {
    fread(&tenista,sizeof(Tenista),1,fichero);
    if (tenista.ranking < maxRanking.ranking)
    {
      maxRanking = tenista;
    }
    if (tenista.titulos > maxTitulos.titulos)
    {
      maxTitulos = tenista;
    }
  }
  printf("El tenista con mayor ranking es %s %s con %d titulos y %d de ranking y una fortuna de %f\n",maxRanking.nombre,maxRanking.apellido,maxRanking.titulos,maxRanking.ranking,maxRanking.fortuna);
  printf("El tenista con mas titulos es %s %s con %d titulos y %d de ranking y una fortuna de %f\n",maxTitulos.nombre,maxTitulos.apellido,maxTitulos.titulos,maxTitulos.ranking,maxTitulos.fortuna);
  return 0;
}