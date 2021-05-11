#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "pilha.h"

char *separar(char *str, size_t ssize) {
  int i;
  char *r;
  Fila *Q;
  Pilha *S;
  TipoElemento buffer;

  Q = fila_criar();
  S = pilha_criar();

  while ( i < ssize ) {
    if ( str[i] >= '0' && str[i] <= '9' ) {
      pilha_empilhar(S, str[i]);
    }
    else {
      fila_inserir(Q, str[i]);
    }
    
    i = i + 1;
  }

  r = (char *) malloc(ssize * sizeof(char));

  i = 0;
  while ( fila_remover(Q, &buffer) ) {
    r[i] = buffer;
    i = i + 1;
  }

  while ( pilha_desempilhar(S, &buffer) ) {
    r[i] = buffer;
    i = i + 1;
  }

  fila_destruir(&Q);
  pilha_destruir(S);

  return r;
}

int main() {

  int i;
  char str[] = "H0e1l2l0";
  char *new_str;

  new_str = separar(str, 8);

  for ( i = 0; i < 8; i++ ) {
    fprintf(stdout, "%c", new_str[i]);
  }
  fprintf(stdout, "\n");

  free(new_str);
  
  return 0;
}
