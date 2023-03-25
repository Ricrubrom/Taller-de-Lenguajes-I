#include <stdio.h>
#include <string.h>

int isPalindrome (char *p, int length);

int main(){
  char palabra[20] = "racecar";
  if (isPalindrome(palabra, strlen(palabra)))
    printf("Es palindromo");
  else
    printf("No es palindromo");
  return 0;
}

int isPalindrome (char *p, int length){
  char *p2 = p + length - 1;
  for (int i = 0; i < length / 2; i++)
  {
    if (*p==*p2){
      p++;
      p2--;
    }else
      return 0;
  }
  return 1;
}