#include <stdio.h>
typedef struct{
  unsigned int R : 8;
  unsigned int G : 8;
  unsigned int B : 8;
}RGB24;

typedef struct{
  unsigned int R : 5;
  unsigned int G : 6;
  unsigned int B : 5;
}RGB16;

RGB16 RGB24toRGB16(RGB24 rgb24){
  RGB16 rgb16;
  rgb16.R = rgb24.R >> 3;
  rgb16.G = rgb24.G >> 2;
  rgb16.B = rgb24.B >> 3;
  return rgb16;
}

RGB24 RGB16toRGB24(RGB16 rgb16){
  RGB24 rgb24;
  rgb24.R = rgb16.R << 3;
  rgb24.G = rgb16.G << 2;
  rgb24.B = rgb16.B << 3;
  return rgb24;
}

int main(){
  RGB24 rgb24 = {255, 255, 255};
  RGB16 rgb16 = RGB24toRGB16(rgb24);
  printf("RGB24: R = %d, G = %d, B = %d\n", rgb24.R, rgb24.G, rgb24.B);
  printf("RGB16: R = %d, G = %d, B = %d", rgb16.R, rgb16.G, rgb16.B);
  return 0;
}