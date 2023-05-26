#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nombre[20];
  char apellido[20];
  int edad;
  int titulos;
  int ranking;
  float fortuna;
} Tenista;

int cambiarRanking(char nombre[], char apellido[], int n);

int main(){
  char nombre[20];
  char apellido[20];
  int n;
  while(1){
    printf("Ingrese el nombre del tenista: ");
    scanf("%s",nombre);
    if (strcmp(nombre,"ZZZ") == 0)
    {
      break;
    }
    printf("Ingrese el apellido del tenista: ");
    scanf("%s",apellido);
    if (strcmp(apellido,"ZZZ") == 0)
    {
      break;
    }
    printf("Ingrese el nuevo ranking del tenista: ");
    scanf("%d",&n);
    if (cambiarRanking(nombre,apellido,n) == 1)
    {
      printf("El tenista %s %s ha cambiado su ranking a %d\n",nombre,apellido,n);
    }else{
      printf("El tenista %s %s no existe\n",nombre,apellido);
    }
  }
  FILE *file = fopen("Src/tenistas.dat", "rb+");
  Tenista tenista;
  while(fread(&tenista,sizeof(Tenista),1,file)==1){
    printf("%s %s %d %d %d %.2f\n",tenista.nombre,tenista.apellido,tenista.edad,tenista.titulos,tenista.ranking,tenista.fortuna);
  }
  return 0;
}

int cambiarRanking(char nombre[], char apellido[], int n){
  FILE *file = fopen("Src/tenistas.dat", "rb+");
  Tenista tenista;
  while (fread(&tenista,sizeof(Tenista),1,file)==1)
  {
    if (strcmp(nombre, tenista.nombre)==0){
      if (strcmp(apellido, tenista.apellido)==0){
        tenista.ranking = n;
        fseek(file, -sizeof(Tenista), SEEK_CUR);
        fwrite(&tenista,sizeof(Tenista),1,file);
        fclose(file);
        return 1;
      }
    }
  }
  return 0;
}