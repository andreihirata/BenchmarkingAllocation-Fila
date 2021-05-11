#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"

#define MAX_VALUE 65536

int main(int argc, char **argv) {
  int i;
  int n;
  Fila *Q;

  if (argc != 2) {
    printf("Número errado de argumentos.\n");
    return -1;
  }


  n = atoi(argv[1]);
  printf(">> Inserir %d\n", n);

  srand(time(NULL));
  
  Q = fila_criar();

  for (i = 0; i < n; i++) {
    fila_inserir(Q, rand() % MAX_VALUE);
  }

  fila_destruir(&Q);

  return 0;
}
