#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

typedef struct
{
    char letter;
    double frequency;
} LetterFrequency;

typedef struct
{
    char word[SIZE];
    double frequency;
} Word;

const LetterFrequency letterFrequencies[] = {
    {'A', 12.53}, {'B', 1.42}, {'C', 4.68}, {'D', 5.86}, {'E', 13.68}, {'F', 0.69}, {'G', 1.01}, {'H', 0.70}, {'I', 6.25}, {'J', 0.44}, {'K', 0.01}, {'L', 4.97}, {'M', 3.15}, {'N', 6.71}, {'O', 8.68}, {'P', 2.51}, {'Q', 0.88}, {'R', 6.87}, {'S', 7.98}, {'T', 4.63}, {'U', 3.93}, {'V', 0.90}, {'W', 0.02}, {'X', 0.22}, {'Y', 0.90}, {'Z', 0.52}
    };

void createFile();
void printFile();
void insert(Word **arr, size_t *capacity, Word data);
void heapify(Word arr[], int n, int i);
void heapSort(Word arr[], int n);

int main(){
  createFile();
  printFile();
  return 0;
}

void createFile(){
  FILE *source = fopen("Src/palabras.txt", "r");
  FILE *dest = fopen("Src/palabras.bin", "wb");
  size_t size = 1;
  Word *arr = (Word *)malloc(size * sizeof(Word));
  char word[SIZE];
  while (fscanf(source, "%s", word) != EOF)
  {
    word[strcspn(word, "\n")] = '\0';
    Word data;
    strcpy(data.word, word);
    data.frequency = 0;
    for (int i = 0; i < strlen(word); i++)
    {
      data.frequency += letterFrequencies[word[i] - 'a'].frequency * letterFrequencies[word[i] - 'a'].frequency;
    }
    insert(&arr, &size, data);
  }
  heapSort(arr, size);
  for (int i = 1; i < size; i++)
  {
    fwrite(&arr[i],sizeof(Word),1,dest);
  }
  fclose(source);
  fclose(dest);
  free(arr);
}

void insert(Word **arr, size_t *capacity, Word data)
{
  (*capacity)++;
  Word *temp = (Word *)realloc(*arr, *capacity * sizeof(Word));
  if (temp == NULL)
  {
    printf("Error reallocating memory.");
    exit(EXIT_FAILURE);
  }
  *arr = temp;
  int n = *capacity - 1;
  while (n / 2 > 0 && (*arr)[n/2].frequency > data.frequency)
  {
    (*arr)[n] = (*arr)[n / 2];
    n /= 2;
  }
  (*arr)[n] = data;
}

void heapify(Word arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left].frequency> arr[largest].frequency)
  {
    largest = left;
  }

  if (right < n && arr[right].frequency > arr[largest].frequency)
  {
    largest = right;
  }

  if (largest != i)
  {
    Word temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}

void heapSort(Word arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    Word temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

void printFile(){
  FILE *f = fopen("Src/palabras.bin", "rb");
  Word word;
  while (fread(&word, sizeof(Word), 1, f) != 0)
  {
    printf("%s %.2f\n", word.word, word.frequency);
  }
  fclose(f);
}