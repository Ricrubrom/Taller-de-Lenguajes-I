#include <stdio.h>
int main(){
  int num1, num2;
  char op;
  printf("Inserte numero 1: ");
  scanf("%d", &num1);
  getchar();
  printf("Inserte caracter (+ - * /): ");
  scanf("%c", &op);
  printf("Inserte numero 2: ");
  scanf("%d", &num2);
  switch (op){
    case '+':
      printf("El resultado de %d %c %d es: %d", num1, op, num2, (num1 + num2));
      break;
    case '-':
      printf("El resultado de %d %c %d es: %d", num1, op, num2, (num1 - num2));
      break;
    case '*':
      printf("El resultado de %d %c %d es: %d", num1, op, num2, (num1 * num2));
      break;
    case '/':
      printf("El resultado de %d %c %d es: %d", num1, op, num2, ((float)num1 / num2));
      break;
    default:
      printf("Operador incorrecto");
  }
  return 0;
}