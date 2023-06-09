#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cambioSTR(char *);
int main()
{
    char * linea =(char *) malloc(100);
    strcpy(linea, "Caso posible");
    printf("Linea = %s\n", linea+5);
    cambioSTR(linea);
    strcpy(linea+8, linea+11);
    printf("Linea = %s\n", linea);
    return 0;
}

void cambioSTR(char * L){
    free(L);
    L =(char *) malloc(200);
    strcpy(L, "Nuevo ");
    strcat(L, "texto");
    printf("L = %s\n", L);
}
