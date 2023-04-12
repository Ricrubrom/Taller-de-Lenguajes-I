#include <stdio.h>
struct horario {
    unsigned hora : 5;
    unsigned minutos : 6;
    unsigned segundos : 5;
};
int main() {
    struct horario h;
    int value;

    printf("Ingrese una hora: ");
    scanf("%d", &value);
    h.hora = value;

    printf("Ingrese minutos: ");
    scanf("%d", &value);
    h.minutos = value;

    printf("Ingrese segundos: ");
    scanf("%d", &value);
    if (value > 31) {
        if (h.minutos == 59) {
            h.minutos = 0;
            if (h.hora == 23)
                h.hora = 0;
            else 
                h.hora++;
        }
        else {
            h.minutos++;
        }
    }
    else 
        h.segundos = value;

    printf("Horario = %d:%d:%d", h.hora,h.minutos,h.segundos);
    return 0;
}