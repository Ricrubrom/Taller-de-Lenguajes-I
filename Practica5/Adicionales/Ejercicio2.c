#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64
#define STR_SIZE 32
#define FILES 10

typedef struct
{
    char word[SIZE];
    double frequency;
} Word;

int main(){
  FILE *source = fopen("Src/palabras.bin", "rb");
  fseek(source, 0, SEEK_END);
  long size = ftell(source)/sizeof(Word);
  fseek(source, 0, SEEK_SET);
  Word *arr = (Word *)malloc(sizeof(Word) * (size));
  int i = 0;
  int capacity = 0;
  while(fread(&arr[i], sizeof(Word), 1, source) != 0){
    i++;
  }
  fclose(source);
  char path[STR_SIZE];
  for (int i = FILES; i >= 1; i--)
  {
    sprintf(path, "Src/Particiones/Dificultad%d.bin", i);
    FILE *f = fopen(path, "wb");
    int k = (i<=size % FILES) ? 1 : 0; 
    for (int j = 0; j < size/FILES + k; j++)
    {
      fwrite(&arr[capacity], sizeof(Word), 1, f);
      capacity++;
    }
    fclose(f);
  }
}