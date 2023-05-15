#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOMBA 'X'
#define OCULTA '?'
#define NO_MARCADA '-'
#define SIZE 8
#define MINAS 1
#define TAM_LETRA 3 //tamaño de cada letra en la impresion
#define CERO ' '

typedef struct{
    char visibilidad;
    char marca;
    int bombas;
    int ocultar;
} Casilla;

void generar(Casilla *T, int cant, int len);
int getMinas(Casilla T[], int len, int i, int j);
void print_tablero(Casilla *T, int len);
void showNear(Casilla T[], int x, int y, int *jugadas);

int main(){
    srand(time(NULL));
    Casilla *T = (Casilla *)malloc(sizeof(Casilla) * SIZE * SIZE);
    char rta[5];
    int flag = 1, fila, bombas = 0, jugadas = SIZE * SIZE - MINAS;
    char col, ocultar;
    printf("Buscaminas (en ingles: Minesweeper) es un videojuego para un jugador inventado en 1989 que se hizo popular desde que Microsoft Windows lo incluyo en su version 3.1. Aqui se implementa el nivel principiante que es una version del tablero 8x8 casillas y 10 minas.\nPara descubrir una celda ingrese una coordenada de una letra y un numero (importa el orden). Para marcar/desmarcar una celda sospechosa de bomba agregue un signo de pregunta (?) a la coordenada.\n");
    generar(T, MINAS, SIZE);
    print_tablero(T, SIZE);
    
    while (flag)
    {
        printf("Jugadas: %d.\n",jugadas);
        printf("Ingrese fila y columnas: ");
        scanf("%s",&rta);
        if (sscanf(rta, "%d %c %c", &fila, &col, &ocultar) == 2){ 
            if(fila >= 0 && fila <= SIZE && col >= 'A' && col <='A'+SIZE){
                if (T[fila * SIZE + (col - 'A')].marca == BOMBA){
                    flag = 0;
                    T[fila * SIZE + (col - 'A')].visibilidad = 1;
                }
                else{
                    if(T[fila * SIZE + (col - 'A')].marca == CERO)
                        showNear(T, fila, col -'A', &jugadas);
                    else{
                        jugadas--;
                        T[fila * SIZE + (col - 'A')].visibilidad = 1;
                    }
                }
            }
            else printf("Los valores ingresados son incorrectos.\n");
            
        }
        else
            if(sscanf(rta, "%d %c %c", &fila, &col, &ocultar) == 3){ 
                if(T[fila * SIZE + (col - 'A')].ocultar == 1){
                    T[fila * SIZE + (col - 'A')].ocultar = 0;
                    bombas++;
                }
                else{
                    if(T[fila * SIZE + (col - 'A')].visibilidad == 0){
                        T[fila * SIZE + (col - 'A')].ocultar = 1;
                        bombas++;
                    }
                    else printf("No es posible ocultar una casilla marcada.\n");
                }
            }
        else printf("Los valores ingresados son incorrectos.\n");

        print_tablero(T, SIZE);
        printf("Bombas marcadas: %d.\n",bombas);
        
        if(!flag)
            printf("PERDISTE!!!!\n");
        if(jugadas == 0 && bombas == MINAS){
            printf("GANASTEE!!!!\n");
            break;
        }
    }
    return 0;
}

void generar(Casilla *T, int cant, int len){
    int aux1, aux2;
    while(cant>0){
        aux1 = rand() % len;
        aux2 = rand() % len;
        if(T[aux1*len+aux2].marca != BOMBA){
            T[aux1 * len + aux2].marca = BOMBA;
            cant--;
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(T[i*len+j].marca != BOMBA){
                T[i * len + j].bombas = getMinas(T, len,i, j);
                if (T[i * len + j].bombas == 0)
                  T[i * len + j].marca = CERO;
                else T[i * len + j].marca = T[i * len + j].bombas + '0';
            }
            T[i * len + j].ocultar = 0;
            T[i * len + j].visibilidad = 0;
        }
    }
}

int getMinas(Casilla T[], int len, int i, int j) {
    int cont = 0;
    for(int x = i-1; x <= i+1; x++) {
        for(int y = j-1; y <= j+1; y++) {
            if((x >= 0) && (x < len) && (y >= 0) && (y < len)) {
                if(T[x*len + y].marca == BOMBA) {
                    cont++;
                }
            }
        }
    }
    return cont;
}

void print_tablero(Casilla *T, int len) {
    // imprimir las letras de las columnas
    printf("%*s", TAM_LETRA+1, ""); // espacio en blanco para la esquina superior izquierda
    for (int i = 0; i < len; i++) {
        printf("%*c ", TAM_LETRA, 'A' + i);
    }
    printf("\n");
    printf("%*s", TAM_LETRA, "   _"); // espacio en blanco para la esquina inferior izquierda
    for (int j = 0; j < len; j++) {
        printf("|___");
    }
    printf("|\n");

    // imprimir cada fila del tablero
    for (int i = 0; i < len; i++) {
        // imprimir el número de fila
        printf("%*d ", TAM_LETRA, i);

        // imprimir cada casilla de la fila
        for (int j = 0; j < len; j++) {
            if(T[i * len +j].visibilidad == 1)
                printf("| %c ", T[i * len + j].marca);
            else
                if(T[i * len +j].ocultar == 1)
                    printf("| %c ", OCULTA);
                else
                    printf("| %c ", NO_MARCADA);
        }
        printf("|\n");

        // imprimir la línea horizontal debajo de la fila
        printf("%*s", TAM_LETRA, "   _"); // espacio en blanco para la esquina inferior izquierda
        for (int j = 0; j < len; j++) {
            printf("|___");
        }
        printf("|\n");
    }
}

void showNear(Casilla T[], int i, int j, int* jugadas){
    if ((i < 0) || (i > SIZE-1) || (j < 0) || (j > SIZE-1)){
        return;
    }
    if (T[i*SIZE + j].marca == BOMBA || T[i*SIZE + j].visibilidad){
        return;
    }
    T[i*SIZE + j].visibilidad = 1;
    (*jugadas)--;
    if (T[i * SIZE + j].bombas != 0)
        return;
    for(int x = i-1; x <= i+1; x++) {
        for(int y = j-1; y <= j+1; y++) {
            if((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
                showNear(T, x, y, jugadas);
            }
        }
    }
}