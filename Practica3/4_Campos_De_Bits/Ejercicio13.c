#include <stdio.h>

typedef struct {
  unsigned Bluetooth : 1;
  unsigned WiFi : 1;
  unsigned GPS : 1;
  unsigned Datos : 1;
  unsigned Frontal : 1;
  unsigned Trasera : 1;
  unsigned Linterna : 1;
  unsigned Vibrar : 1;
} Modulos;

int main(){
  const Modulos m = {1, 1, 1, 1, 1, 1, 1, 1};
  const Modulos m2 = {0, 0, 0, 0, 0, 0, 0, 0};
  Modulos m3 = m2;
  m3.Bluetooth |= 1;
  m3.Bluetooth &= 0;
  m3.GPS ^= 1;
  if (m3.GPS == 1)
    printf("GPS activado");
  printf(" m3.Bluetooth = %d", m3.Bluetooth);
  printf(" m3.GPS = %d", m3.GPS);
  return 0;
}