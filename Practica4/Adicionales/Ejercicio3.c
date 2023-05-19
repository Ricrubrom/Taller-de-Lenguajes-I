#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {FALSE, TRUE} Boolean;
#define SIZE 8
#define HIDDEN '-'
#define SAFE ' '
#define FLAG '?'
#define BOMB '*'
#define BOMBS 5
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
int processPlay(Cell **game, int x, int y, int *totPlays);


int main(){
  srand(time(0));
  Cell **game = startGame();
  gameLoop(game);
  for (int i = 0; i < SIZE; i++)
  {
    free(game[i]);
  }
  free(game);
  return 0;
}

Cell **startGame(){
  Cell **game = (Cell **)calloc(SIZE, sizeof(Cell*));
  for (int i = 0; i < SIZE; i++)
  {
    game[i] = (Cell *)calloc(SIZE, sizeof(Cell));
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
      game[i][j].state = FALSE;
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
        if(T[i][j].state == TRUE && T[i][j].isBomb!=TRUE)
          printf("| %c ", T[i][j].sign);
        else
        {
          if (T[i][j].state==FALSE)
          {
            printf("| %c ", HIDDEN);
          }
          else{
            printf("| %c ", BOMB);
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
    int totPlays = SIZE * SIZE - BOMBS;
    char play[5];
    int flag;
    while (TRUE)
    {
      printGame(game);
      printf("\nInserte Jugada (? marca)(0-%d)(A-%c): ", SIZE - 1, SIZE - 1 + 'A');
      scanf("%s", play);
      while (!((play[0]==FLAG && (play[1]>='0' && play[1]<=SIZE - 1 + '0')&&(play[2]>='A' && play[2]<=SIZE - 1 + 'A'))||((play[0]>='0' && play[0]<=SIZE - 1 + '0')&&(play[1]>='A' && play[1]<='H')))){
        printf("\nJugada Erronea, intente devuelta: ");
        scanf("%s", play);
      }
      if (play[0]==FLAG){
        if (game[play[1] - 0x30][play[2] - 0x41].state!=0 && game[play[1] - 0x30][play[2] - 0x41].sign != FLAG )
        {
          printf("\nNo puedes marcar una casilla ya descubierta\n");
          continue;
        }
        game[play[1] - 0x30][play[2] - 0x41].state = game[play[1] - 0x30][play[2] - 0x41].state ^ 1 ;
        if (game[play[1] - 0x30][play[2] - 0x41].state){
          game[play[1] - 0x30][play[2] - 0x41].sign = FLAG ;
        }
        else{
          game[play[1] - 0x30][play[2] - 0x41].sign = HIDDEN ;
        }
      }
      else
      {
        flag = processPlay(game, play[0] - 0x30, play[1] - 0x41, &totPlays);
        if (flag){
          break;
        }
      }
      if (totPlays==0)
        break;
    }
    if (flag){
      printGame(game);
      printf("PERDISTEEEEEEEE!!!!!!!!");
    }
    else{
      printGame(game);
      printf("GANASTEEEEEEEEE!!!!!!!!");
    }
}

int processPlay(Cell **game, int x, int y, int *totPlays){
  if (game[x][y].isBomb){
    game[x][y].sign = BOMB;
    game[x][y].state = TRUE;
    return TRUE;
  }
  if (game[x][y].state){
    return FALSE;
  }
  (*totPlays)--;
  if (game[x][y].bombs==0){
    game[x][y].sign = SAFE;
    game[x][y].state = TRUE;
    for (int i = x-1; i <= x+1; i++)
    {
      for (int j = y-1; j <= y+1; j++)
      {
          if ((i >= 0 && i <= SIZE - 1) && (j >= 0 && j <= SIZE - 1)){
            int flag=processPlay(game, i, j, totPlays);
            if (flag==TRUE){
              return TRUE;
            }
          }
      }
    }
  }
  else{
    game[x][y].sign = game[x][y].bombs + '0';
    game[x][y].state = TRUE;
  }
  return FALSE;
}