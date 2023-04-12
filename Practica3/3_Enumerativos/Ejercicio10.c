#include <stdio.h>

typedef enum {
    Bluetooth = 128,
    Wifi = 64,
    GPS =  32,
    Datos = 16,
    CamaraFrontal = 8,
    CamaraTrasera = 4,
    Linterna = 2,
    Vibrar = 1
}modulos;

int main(){
  const modulos m = Bluetooth | Wifi | GPS | Datos | CamaraFrontal | CamaraTrasera | Linterna | Vibrar;
  const modulos m2;
  modulos m3=0;
  printf("%d\n", m);
  printf("%d\n", m2);
  m3 |= Bluetooth;                            //Prende el bit de Bluetooth
  printf("%d\n", m3);
  m3 &= ~Bluetooth;                           //Apaga el bit de Bluetooth
  printf("%d\n", m3);
  m3 ^= GPS;                                  //Invierte el bit de GPS
  printf("%d\n", m3);
  if (m3 & Bluetooth)
    printf("Bluetooth esta activo\n");        //Verifica si el bit de Bluetooth esta prendido
  else 
    printf("Bluetooth esta desactivado\n");
  return 0;
}