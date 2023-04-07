#include <stdio.h>

#define LENGTH 3

typedef struct direccion{
  char calle[50];
  char ciudad[30];
  int coidgo_postal;
  char pais[40];
}direccion;

typedef struct alu{
  char nombre[50];
  char apellido[50];
  char legajo[8];
  float promedio;
  direccion dir;
} alumno;

alumno inicializar(alumno alu){
  printf("Inserte nombre: ");
  scanf("%s", alu.nombre);
  printf("Inserte apellido: ");
  scanf("%s", alu.apellido);
  printf("Inserte legajo: ");
  scanf("%s", alu.legajo);
  printf("Inserte promedio: ");
  scanf("%f", &alu.promedio);
  printf("Inserte calle: ");
  scanf("%s", alu.dir.calle);
  printf("Inserte ciudad: ");
  scanf("%s", alu.dir.ciudad);
  printf("Inserte codigo postal: ");
  scanf("%d", &alu.dir.coidgo_postal);
  printf("Inserte pais: ");
  scanf("%s", alu.dir.pais);
  return alu;
}

int main(){
  alumno alu[LENGTH],max;
  for (int i = 0; i < LENGTH; i++)
  {
    alu[i] = inicializar(alu[i]);
    if (alu[i].promedio > max.promedio){
      max = alu[i];
    }
  }
  printf("Alumno con mayor promedio: %s %s", max.nombre, max.apellido);
  return 0;
}