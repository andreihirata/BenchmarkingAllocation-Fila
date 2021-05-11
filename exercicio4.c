#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "pilha.h"

/**
 * O enúnciado diz que "não posso movimentar os outros elementos da
 * fila". Também não sei se posso acessar os elementos do vetor
 * diretamente ou se tenho que usar somente as funções que existem em
 * 'fila.h'.
 *
 * Se eu não posso acessar os dados diretamente, teria que remover
 * todos os elementos e inseri-los novamente ... o que não ajuda o
 * desempenho (O(n)).
 *
 * Se eu posso acessar os dados diretamente, posso mudar o tamanho do
 * vetor e ajustar os indices 'fim' e 'inicio' e podemos fazer essa
 * inserção em O(1).
 *
 * Vou fazer da maneira NÃO eficiente abaixo pois o tamanho sempre é
 * modificado dobrando o tamanho ou dividindo o tamanho por 2 e eu
 * teria que colocar um tamanho arbitrário.
 */
void fura_fila(Fila *f, TipoElemento elemento) {
  Fila *Q;
  TipoElemento buffer;

  Q = fila_criar();

  while ( fila_remover(f, &buffer) ) {
    fila_inserir(Q, buffer);
  }

  fila_inserir(f, elemento);

  while ( fila_remover(Q, &buffer) ) {
    fila_inserir(f, buffer);
  }

  fila_destruir(&Q);
}

int main(){

  Fila *Q;

  Q = fila_criar();

  fila_inserir(Q, 10);
  fila_inserir(Q, 20);
  fila_inserir(Q, 30);
  fila_inserir(Q, 40);

  fura_fila(Q, 5);

  fila_imprimir(Q);
  
  return 0;
}
