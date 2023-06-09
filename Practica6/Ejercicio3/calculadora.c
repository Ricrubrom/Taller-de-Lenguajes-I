#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
  char op=argv[2][0];
  switch (op)
  {
  case '+':
    printf("\n%d",atoi(argv[1])+atoi(argv[3]));
    break;
  
  case '-':
    printf("\n%d",atoi(argv[1])-atoi(argv[3]));
    break;
  
  case '.':
    printf("\n%d",atoi(argv[1])*atoi(argv[3]));
    break;

  case '/':
    printf("\n%d",atoi(argv[1])/atoi(argv[3]));
    break;
  default:
    printf("\nOperacion no valida");
    break;
  }
  return 0;
}
