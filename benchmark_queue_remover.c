#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"

// Valor máximo de um número que ser inserido
#define MAX_VALUE 65536

int main(int argc, char **argv) {
  int i;
  int n;
  Fila *Q;
  TipoElemento buffer;

  // Verificando se o nmero de argumentos esta correto
  if (argc != 2) {
    printf("Número errado de argumentos.\n");
    return -1;
  }

  // Convertendo o argumento para inteiro
  n = atoi(argv[1]);
  printf(">> Inserir/Remover %d\n", n);

  // Inicializando o gerador de numeros aleatorios
  srand(time(NULL));

  // Criando a fila
  Q = fila_criar();

  // Fazendo insercoes
  for (i = 0; i < n; i++) {
    fila_inserir(Q, rand() % MAX_VALUE); // % MAX_VALUE -> resto da divisao por MAX_VALUE, come uma operacao
  }

  // Removendo elementos da fila
  for (i = 0; i < n; i++) {
    fila_remover(Q, &buffer);
  }

  // Liberando a fila
  fila_destruir(&Q);

  return 0;
}
