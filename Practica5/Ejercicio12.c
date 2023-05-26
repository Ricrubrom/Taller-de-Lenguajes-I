#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 300

typedef struct{
  long dni;
  size_t id;
} idx;

typedef struct
{
  unsigned id, dni;
  char *surname, *name, *work, *mail, *city, *country;
} person;

void startIdx(idx **index, size_t *size);
void insert(idx **arr, size_t *capacity, idx data);
void printIdx();
void heapify(idx arr[], int n, int i);
void heapSort(idx arr[], int n);
void printPerson(person p);
int buscar(FILE *personas, idx *indice, int dni, person *persona, int capacity);

int main(){
  idx *arr;
  size_t capacity = 0;
  startIdx(&arr, &capacity);
  printIdx();
  FILE *personas = fopen("Src/personas copy.csv", "r");
  person persona;
  int dni;
  printf("Ingrese el dni a buscar: ");
  scanf("%d", &dni);
  if (buscar(personas, arr, dni, &persona, capacity))
  {
    printf("Se encontro el dni\n");
    printPerson(persona);
  }
  else
  {
    printf("No se encontro el dni\n");
  }
  return 0;
}

void startIdx(idx **index, size_t *size){
  FILE *csv=fopen("Src/personas copy.csv","r");
  FILE *IDX=fopen("Src/personas.idx","wb");
  char linea[SIZE];
  fgets(linea, SIZE, csv);
  int dni, aux;
  *size= 1;
  idx *arr = (idx *)malloc((*size) * sizeof(idx));
  idx persona;
  persona.id = ftell(csv);
  while(fgets(linea, SIZE, csv) != NULL){
    sscanf(linea, "%d;%ld;", &aux, &dni);
    persona.dni = dni;
    insert(&arr, size, persona);
    persona.id = ftell(csv);
  }
  heapSort(arr, *size);
  for (int i = 1; i < *size; i++)
  {
    fwrite(&arr[i],sizeof(idx),1,IDX);
  }
  fclose(csv);
  fclose(IDX);
  *index=arr;
}

void insert(idx **arr, size_t *capacity, idx data)
{
  (*capacity)++;
  idx *temp = (idx *)realloc(*arr, *capacity * sizeof(idx));
  if (temp == NULL)
  {
    printf("Error reallocating memory.");
    exit(EXIT_FAILURE);
  }
  *arr = temp;
  int n = *capacity - 1;
  while (n / 2 > 0 && (*arr)[n / 2].dni > data.dni)
  {
    (*arr)[n] = (*arr)[n / 2];
    n /= 2;
  }
  (*arr)[n] = data;
}

void heapify(idx arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left].dni > arr[largest].dni)
  {
    largest = left;
  }

  if (right < n && arr[right].dni > arr[largest].dni)
  {
    largest = right;
  }

  if (largest != i)
  {
    idx temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}

void heapSort(idx arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    idx temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

void printIdx()
{
  FILE *file = fopen("Src/personas.idx", "rb");
  idx aux;
  while (fread(&aux, sizeof(idx), 1, file))
  {
    printf("%ld %ld\n", aux.dni, aux.id);
  }
  fclose(file);
}

void printPerson(person p)
{
  printf("%d %d %s %s %s %s %s %s\n", p.id, p.dni, p.surname, p.name, p.work, p.mail, p.city, p.country);
}

int buscar(FILE *personas, idx *indice, int dni, person *persona, int capacity){
  int left = 1;
  int right = capacity;
  char buffer[SIZE];
  char *field;
  while (left<=right){
    int mid = (left + right) / 2;
    if (indice[mid].dni==dni){
      fseek(personas, indice[mid].id, SEEK_SET);
      if (fgets(buffer, SIZE, personas) != NULL)
      {
        char *field = strtok(buffer, ";");
        persona->id = atoi(field);
        field = strtok(NULL, ";");
        persona->dni = atoi(field);
        field = strtok(NULL, ";");
        persona->surname = strdup(field);
        field = strtok(NULL, ";");
        persona->name = strdup(field);
        field = strtok(NULL, ";");
        persona->work = strdup(field);
        field = strtok(NULL, ";");
        persona->mail = strdup(field);
        field = strtok(NULL, ";");
        persona->city = strdup(field);
        field = strtok(NULL, ";");
        persona->country = strdup(field);
        return 1;
      }
    }
    if (indice[mid].dni<dni){
      left = mid + 1;
      continue;
    }
    right = mid - 1;
  }
  return 0;
}