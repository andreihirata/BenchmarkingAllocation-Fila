#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "pilha.h"

Fila *intercalar(Fila *q1, Fila *q2) {
  int cur;
  Fila *Q[2];
  Fila *q3;
  TipoElemento buffer;

  cur = 0;
  Q[0] = q1;
  Q[1] = q2;

  q3 = fila_criar();

  while ( !fila_vazia(Q[0]) && !fila_vazia(Q[1]) ) {
    fila_remover(Q[cur], &buffer);
    fila_inserir(q3, buffer);
    cur = (cur + 1) % 2;
  }

  while ( !fila_vazia(Q[0]) ) {
    fila_remover(Q[0], &buffer);
    fila_inserir(q3, buffer);
  }

  while ( !fila_vazia(Q[1]) ) {
    fila_remover(Q[1], &buffer);
    fila_inserir(q3, buffer);
  }

  return q3;
}


int main() {

  Fila *Q1, *Q2, *Q3;

  Q1 = fila_criar();
  Q2 = fila_criar();

  fila_inserir(Q1, 10);
  fila_inserir(Q1, 20);
  fila_inserir(Q1, 30);
  fila_inserir(Q1, 40);

  fila_inserir(Q2, 15);
  fila_inserir(Q2, 25);
  fila_inserir(Q2, 35);
  fila_inserir(Q2, 45);
  
  Q3 = intercalar(Q1, Q2);

  fila_imprimir(Q3);
  
  return 0;
}
