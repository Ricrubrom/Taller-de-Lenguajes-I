#include <stdio.h>
#include <stdlib.h>

int main(){
  srand(89176249);
  int num1, num2, res, tot = 0;
  for (int i = 0; i < 4; i++)
  {
    num1 = rand() % 101;
    num2 = rand() % 101;
    printf("%d + %d = ", num1, num2);
    scanf("%d", &res);
    if (res==num1+num2)
      tot++;
  }
  switch (tot)
  {
  case 0:
    printf("El alumno se saco una E");
    break;
  case 1:
    printf("El alumno se saco una D");
    break;
  case 2:
    printf("El alumno se saco una C");
    break;
  case 3:
    printf("El alumno se saco una B");
    break;
  case 4:
    printf("El alumno se saco una A");
    break;
  
  default:
    printf("Hubo un error");
    break;
  }
  return 0;
}