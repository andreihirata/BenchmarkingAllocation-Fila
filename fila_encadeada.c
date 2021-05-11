#include "fila.h"
#include "string.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
typedef struct no{
    int dado;
    struct no* prox;
}No;

struct _fila {
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool fila_ehValida(Fila* f){
    return (f != NULL? true: false);   
}

No* novoNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

void fila_destruir(Fila** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    No* aux;
    while(f->inicio != NULL){
        aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    No* novo = novoNo(elemento);

    if(f->inicio == NULL){
        f->inicio = novo;        
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;    
    f->qtde++;

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    No* aux = f->inicio;        
    f->inicio = f->inicio->prox;
    f->qtde--;
    *saida = aux->dado;
    free(aux);
    
    if(f->inicio == NULL){        
        f->fim = NULL;
    }
    
    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->inicio->dado;
    return true;
}

bool fila_vazia(Fila* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

int fila_tamanho(Fila* f){
    if(!fila_ehValida(f)) return 0;

    return f->qtde;
}

void fila_imprimir(Fila* f) {
  No *cur;

  cur = f->inicio;

  while ( cur != NULL ) {
    fprintf(stdout, "Elemento: %d\n", cur->dado);
    cur = cur->prox;
  }
}

Fila* fila_clone(Fila* f) {
  int i;
  ssize_t bsize;
  TipoElemento *buffer;
  TipoElemento tmp;
  Fila *newf;

  bsize = 0;
  buffer = NULL;

  while ( fila_remover(f, &tmp) != NULL ) {
    buffer = (TipoElemento *) realloc(buffer, ++bsize * sizeof(TipoElemento));
    buffer[bsize-1] = tmp;
  }

  newf = fila_criar();
  for ( i = 0; i < bsize; i++ ) {
    fila_inserir(f, buffer[i]);
    fila_inserir(newf, buffer[i]);
  }

  free(buffer);
  
  return newf;
}

bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor) {
  int i;

  for ( i = 0; i < tamVetor; i++ ) {
    fila_inserir(f, vetor[i]);
  }

  return true;
}
