#include <stdio.h>
int main(){
  double pi = 3,inv=1;
  for (int i = 2; i < 3000; i+=2)
  {
    pi += inv * 4 / (i * (i + 1) * (i + 2));
    inv *= -1;
  }
  printf("%.6f", pi);
  return 0;
}