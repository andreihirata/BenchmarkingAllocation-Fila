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

void inverter(Fila *q1, Pilha *s1) {
  TipoElemento buffer;

  while ( fila_remover(q1, &buffer) ) {
    pilha_empilhar(s1, buffer);
  }

  while ( pilha_desempilhar(s1, &buffer) ) {
    fila_inserir(q1, buffer);
  }
}

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

    TipoElemento elemento;
      /**************************************
    * Teste insercao e primeiro
    **************************************/
    Fila* f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_primeiro(f1, &elemento);

    /**************************************
    * Teste remocao
    **************************************/
    fila_remover(f1, &elemento);
    fila_remover(f1, &elemento);  
    fila_remover(f1, &elemento); 
    bool resultado = fila_remover(f1, &elemento);
    fila_destruir(&f1);

       

    /**************************************
    * Teste inserir todos e clone
    **************************************/
    int vetor[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    f1 = fila_criar();
    //fila_inserirTodos(f1, vetor, 12);
     
    //Fila* f2 = fila_clone(f1);
    //fila_remover(f2, &elemento);
    //fila_remover(f2, &elemento);
    //fila_remover(f2, &elemento);
    //fila_inserir(f2, 20);
    //fila_inserir(f2, 21);
    //fila_inserir(f2, 22);

    fila_destruir(&f1);
    //fila_destruir(&f2);

    printf("Hello World");
    return 0;
}
