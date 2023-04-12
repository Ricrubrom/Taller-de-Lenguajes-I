#include <stdio.h>
typedef struct{
  unsigned segundo:5;
  unsigned minuto:6;
  unsigned hora:5;
} horario;

int main(){
  horario h;
  printf("Introduce la hora: ");
  unsigned int hora;
  scanf("%d", &hora);
  printf("Introduce los minutos: ");
  unsigned int minuto;
  scanf("%d", &minuto);
  printf("Introduce los segundos: ");
  unsigned int segundo;
  scanf("%d", &segundo);
  if (segundo>=32){
    segundo=0;
    minuto++;
  }
  h.hora = hora;
  h.minuto = minuto;
  h.segundo = segundo;
  printf("%02d:%02d:%02d\n", h.hora, h.minuto, h.segundo);
  return 0;
}