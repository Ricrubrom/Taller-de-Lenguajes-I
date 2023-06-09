#ifndef IMATH_H
#define IMATH_H

int potencia(int base, int exponente){
  int resultado = 1;
  for(int i = 0; i < exponente; i++){
    resultado *= base;
  }
  return resultado;
}

int cuadrado(int numero){
  return numero*numero;
}

int cubo(int numero){
  return numero*numero*numero;
}

int absoluto(int numero){
  if(numero < 0){
    return -numero;
  }
  return numero;
}

int factorial(int numero){
  int resultado = 1;
  for(int i = 1; i <= numero; i++){
    resultado *= i;
  }
  return resultado;
}

int sumatoria(int numero){
  int resultado = 0;
  for(int i = 1; i <= numero; i++){
    resultado += i;
  }
  return resultado;
}

int multiplos(int numero1, int numero2){
  if (numero1%numero2 == 0){
    return 1;
  }
  return 0;
}

int divisores(int numero1, int numero2){
  if (numero2%numero1 == 0){
    return 1;
  }
  return 0;
}

int par(int numero){
  if (numero%2 == 0){
    return 1;
  }
  return 0;
}

int impar(int numero){
  if (numero%2 != 0){
    return 1;
  }
  return 0;
}
#endif

