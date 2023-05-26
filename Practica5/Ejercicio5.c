#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInDictionary(char **dictionary, int size, char *word)
{
  int left = 0, right = size;

  while (left <= right)
  {
    int mid = (left + right) / 2;
    int comparison = strcmp(word, dictionary[mid]);
    if (comparison == 0)
    {
      return 1;
    }
    else if (comparison < 0)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return 0;
}



int main(){
  FILE *f=fopen("Src/dictionary.txt", "r");
  char **diccionario;
  char palabra[20];
  int i = 1;
  diccionario = (char **)malloc(sizeof(char *));
  while (fgets(palabra, 20, f) != NULL)
  {
    palabra[strlen(palabra) - 1] = '\0';
    diccionario[i-1] = strdup(palabra);
    diccionario = (char **)realloc(diccionario, sizeof(char *) * (++i));
  }
  printf("Ingrese una palabra: ");
  scanf("%s", palabra);
  while (strcmp(palabra, "ZZZ") != 0)
  {
    int j = 0;
    isInDictionary(diccionario, i-1, palabra) ? printf("La palabra %s esta en el diccionario\n", palabra) : printf("La palabra %s no esta en el diccionario\n", palabra);
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
  }
  return 0;
}