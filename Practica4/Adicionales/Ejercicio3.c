#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {FALSE, TRUE} Boolean;
#define SIZE 8
#define HIDDEN '-'
#define NOT_HIDDEN ' '
#define FLAG '?'
#define BOMB '*'
#define BOMBS 10
#define CELL_SIZE 3

typedef struct{
  int bombs;
  char sign;
  int state;
  int isBomb;
} Cell;

Cell **startGame();
void printGame(Cell **game);
void gameLoop(Cell **game);
int processPlay(Cell ***game);


int main(){
  srand(1);
  Cell **game = startGame();
  printGame(game);
  return 0;
}

Cell **startGame(){
  Cell **game = (Cell **)malloc(SIZE * sizeof(Cell*));
  for (int i = 0; i < SIZE; i++)
  {
    game[i] = (Cell *)malloc(SIZE * sizeof(Cell));
  }
  for (int j = 0; j < SIZE; j++)
  {
    for (int k = 0; k < SIZE; k++)
    {
      game[j][k].bombs=0;
      game[j][k].isBomb=FALSE;
    }
  }
  for (int i = 0; i < BOMBS; i++)
  {
    int x = rand() % SIZE;
    int y = rand() % SIZE;
    while (game[x][y].isBomb)
    {
      x = rand() % SIZE;
      y = rand() % SIZE;
    }
    game[x][y].isBomb = TRUE;
    for (int j = x-1; j <= x+1; j++)
    {
      for (int k = y-1; k <= y+1; k++)
      {
        if ((j>=0 && k>=0)&&(j<SIZE && k<SIZE))
        {
          game[j][k].bombs++;
        }
      }
    }
    
  }
  
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      game[i][j].state = TRUE;
      game[i][j].sign = game[i][j].bombs+'0';
    }
  }
  return game;
}

void printGame(Cell **T) {
    // imprimir las letras de las columnas
    printf("%*s", CELL_SIZE+1, ""); // espacio en blanco para la esquina superior izquierda
    for (int i = 0; i < SIZE; i++) {
        printf("%*c ", CELL_SIZE, 'A' + i);
    }
    printf("\n");
    printf("%*s", CELL_SIZE, "   _"); // espacio en blanco para la esquina inferior izquierda
    for (int j = 0; j < SIZE; j++) {
        printf("|___");
    }
    printf("|\n");

    // imprimir cada fila del tablero
    for (int i = 0; i < SIZE; i++) {
      // imprimir el número de fila
      printf("%*d ", CELL_SIZE, i);

      // imprimir cada casilla de la fila
      for (int j = 0; j < SIZE; j++) {
        if (T[i][j].isBomb)
        {
          printf("| %c ", BOMB);
        }
        else{
          if(T[i][j].state == TRUE)
            printf("| %c ", T[i][j].sign);
          else
          {
            printf("| %c ", HIDDEN);
          }
        }
      }
      printf("|\n");

      // imprimir la línea horizontal debajo de la fila
      printf("%*s", CELL_SIZE, "   _"); // espacio en blanco para la esquina inferior izquierda
      for (int j = 0; j < SIZE; j++) {
        printf("|___");
      }
      printf("|\n");
    }
  }

void gameLoop(Cell **game){
    int totPlays = SIZE * SIZE * BOMBS;
    char play[5];
    while (TRUE)
    {
      printGame(game);
      printf("Inserte Jugada (? marca)(0-%d)(A-%c)", SIZE, SIZE + 'A');
      scanf("%s", play);
      while (getchar() || !(((play[0]==FLAG && (play[1]>='0' && play[1]<=7)&&(play[2]>='A' && play[2]<='H')))||((play[0]>='0' && play[0]<=7)&&(play[1]>='A' && play[1]<='H')))){
        while(getchar());
        printf("Jugada Erronea, intente devuelta: ");
        scanf("%s", play);
      }
    }
}