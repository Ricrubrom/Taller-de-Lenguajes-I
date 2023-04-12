#include <stdio.h>

typedef struct{
  char apellido[20];
  char nombre[20];
  char legajo[10];
  int extranjero;
  union{
    int DNI;
    char pasaporte[10];
  } ID;
}estudiante;

int main(){
  estudiante e;
  printf("Ingrese apellido: ");
  scanf("%s", e.apellido);
  printf("Ingrese nombre: ");
  scanf("%s", e.nombre);
  printf("Ingrese legajo: ");
  scanf("%s", e.legajo);
  printf("Es extranjero? (1/0): ");
  scanf("%d", &e.extranjero);
  if(e.extranjero){
    printf("Ingrese pasaporte: ");
    scanf("%s", e.ID.pasaporte);
    printf("%s %s %s %s\n", e.apellido, e.nombre, e.legajo, e.ID.pasaporte);
  }
  else{
  printf("Ingrese DNI: ");
  scanf("%d", &e.ID.DNI);
  printf("%s %s %s %d\n", e.apellido, e.nombre, e.legajo, e.ID.DNI);
  }
  return 0;
}