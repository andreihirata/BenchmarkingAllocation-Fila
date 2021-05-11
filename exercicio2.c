#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "pilha.h"


void inverter(Fila *q1, Pilha *s1) {
  TipoElemento buffer;

  while ( fila_remover(q1, &buffer) ) {
    pilha_empilhar(s1, buffer);
  }

  while ( pilha_desempilhar(s1, &buffer) ) {
    fila_inserir(q1, buffer);
  }
}


int main() {

  Fila *Q;
  Pilha *S;

  Q = fila_criar();
  S = pilha_criar();

  fila_inserir(Q, 10);
  fila_inserir(Q, 20);
  fila_inserir(Q, 30);
  fila_inserir(Q, 40);

  inverter(Q, S);

  fila_imprimir(Q);
  
  return 0;
}
