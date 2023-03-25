#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int precipitacion[10][12][30];
  float anual[10];
  int totAnual[10] = {0};
  int totMensual[12] = {0};
  srand(time(0));
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 12; j++)
    {
      for (int k = 0; k < 30; k++)
      {
        precipitacion[i][j][k] = rand() % 100;
      }
    }
  }
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 12; j++)
    {
      for (int k = 0; k < 30; k++)
      {
        totAnual[k] += precipitacion[i][j][k];
        totMensual[j] += precipitacion[i][j][k];
      }
      if (j==0){
        anual[i] = totMensual[j];
      }
      else if (totMensual[j] < anual[i]){
        anual[i] = totMensual[j];
      }
    }
  }
  for (int i = 0; i < 10; i++)
  {
    totAnual[i] /= 360;
  }
  float promedio = totAnual[0];
  for (int i = 0; i < 10; i++)
  {
    printf("El mes mas lluvioso del año %d fue %f \n", i+1, anual[i]);
    if (totAnual[i] < promedio){
      promedio = totAnual[i];
    }
  }
  printf("El promedio menor de precipitacion anual es %f \n", promedio);
  return 0;
}