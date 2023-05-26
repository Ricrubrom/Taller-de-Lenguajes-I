#include <stdio.h>
#include <stdlib.h>
int main(){
  FILE *dec=fopen("Src/numeros.txt","w");
  FILE *bin=fopen("Src/numeros.dat","wb+");
  int n = 9;
  while (n!=0)
  {
    printf("Ingrese un numero de un digito: ");
    scanf("%d",&n);
    if (n!=0)
    {
      fputc(n+48,dec);
      fputc(' ',dec);
      fwrite(&n,sizeof(int),1,bin);
    }
  }
  fseek(bin,0,SEEK_SET);
  fread(&n,sizeof(int),1,bin);
  while (!feof(bin))
  {
    printf("%d ",n);
    fread(&n,sizeof(int),1,bin);
  }
  return 0;
}