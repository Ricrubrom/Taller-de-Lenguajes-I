#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float tot;
  float min;
  float max;
} Info;

int main(){
  FILE *f=fopen("Src/vinos.csv","r");
  FILE *end=fopen("Src/reporte_vinos.txt","w");
  char *linea=(char*)malloc(sizeof(char)*100);
  Info res[8];
  float act[8];
  int cant=0;
  for (int i = 0; i < 8; i++)
  {
    res[i].min=9999;
    res[i].max=-1;
    res[i].tot=0;
  }
  fgets(linea, 100, f);
  while (fscanf(f, "%f;%f;%f;%f;%f;%f;%f;%f;%s\n", &act[0], &act[1], &act[2], &act[3], &act[4], &act[5], &act[6], &act[7], linea) == 9)
  {
    for (int i = 0; i < 8; i++)
    {
      res[i].tot+=act[i];
      if(act[i]<res[i].min){
        res[i].min=act[i];
      }
      if(act[i]>res[i].max){
        res[i].max=act[i];
      }
    }
    cant++;
  }
  for (int i = 0; i < 8; i++)
  {
    res[i].tot = res[i].tot / cant;
  }
  fprintf(end, "Atributo    Acidez Fija   Acidez Volatil   Acido Citrico   Azucares Residuales   PH      Sulfatos    Alcohol   Calidad");
  fprintf(end, "\nPromedio    %2.2f          %.2f             %.2f            %.2f                  %.2f    %.2f        %.2f     %.2f", res[0].tot, res[1].tot, res[2].tot, res[3].tot, res[4].tot, res[5].tot, res[6].tot, res[7].tot);
  fprintf(end, "\nMinimo      %.2f          %.2f             %.2f            %.2f                  %.2f    %.2f        %.2f      %.2f", res[0].min, res[1].min, res[2].min, res[3].min, res[4].min, res[5].min, res[6].min, res[7].min);
  fprintf(end, "\nMaximo      %.2f         %.2f             %.2f            %.2f                 %.2f    %.2f        %.2f     %.2f", res[0].max, res[1].max, res[2].max, res[3].max, res[4].max, res[5].max, res[6].max, res[7].max);
  return 0;
}