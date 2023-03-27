#include <stdio.h>
#include <string.h>


void upperString(char cadena[]);
void lowerString(char cadena[]);
char *numToString(int num, char cadena[]);
char *numToText(int num, char cadena[]);


int main(){
  char string[20]="Hola mundo";
  upperString(string);
  printf("%s \n", string);
  lowerString(string);
  printf("%s \n", string);
  printf("%s \n", numToString(123, string));
  printf("%s \n", numToText(22, string));
  return 0;
}

void upperString(char cadena[]){
  int i = 0;
  while (cadena[i] != '\0')
  {
    if (cadena[i] >= 'a' && cadena[i] <= 'z')
      cadena[i] -= 32;
    i++;
  }
}

void lowerString(char cadena[]){
  int i = 0;
  while (cadena[i] != '\0')
  {
    if (cadena[i] >= 'A' && cadena[i] <= 'Z')
      cadena[i] += 32;
    i++;
  }
}

char *numToString(int num, char cadena[]){
  int i = 0;
  while (num > 0)
  {
    cadena[i] = num%10 + '0';
    num /= 10;
    i++;
  }
  cadena[i] = '\0';
  strrev(cadena);
  return cadena;
}

char *numToText(int num, char cadena[]){
  char *unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
  char *decenas[] = {"diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
  char *especiales[] = {"once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve","veintiuno", "veintidos", "veintitres", "veinticuatro", "veinticinco", "veintiseis", "veintisiete", "veintiocho", "veintinueve"};
  int i = 0;
  if (num < 10)
  {
    strcpy(cadena, unidades[num]);
  }
  else if (num < 30)
  {
    strcpy(cadena, especiales[num - 11]);
  }
  else
  {
    strcpy(cadena, decenas[num/10-1]);
    if (num%10 != 0)
    {
      strcat(cadena, " y ");
      strcat(cadena, unidades[num%10]);
    }
  }
  return cadena;
}