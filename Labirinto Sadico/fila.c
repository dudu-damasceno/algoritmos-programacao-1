#include "fila.h"

typedef struct telemento{
  int dado;
  struct telemento* prox;
}elemento;

//nessa implementacao de fila, estou usando uma lista ligada circular
//feita em sala e baseada na implementacao do Prof. Paulo Feofiloff
//https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html
//a fila sempre tem pelo menos uma cabeca (que pode mudar com a manipulacao da fila)
//quando a fila esta vazia a cabeca eh um elemento que aponta para ele mesmo
struct tfila{
  elemento *cabeca;
};

fila criarfila(){
  fila F = (fila) malloc(sizeof(struct tfila));
  elemento * cabeca = (elemento*) malloc(sizeof(elemento));
  //fila vazia, a cabeca aponta para ela mesma
  cabeca->prox = cabeca;
  //a cabeca eh guardada na fila
  F->cabeca = cabeca;
  return F;
}

void colocarnafila(fila F, int x){
  elemento* cabeca = F->cabeca;
  cabeca->dado = x;
  elemento * nova_cabeca = (elemento*) malloc(sizeof(elemento));
  nova_cabeca->prox = cabeca->prox;
  cabeca->prox = nova_cabeca;
  F->cabeca = nova_cabeca;
  return;
}

int retirardafila(fila F){
  elemento * cabeca = F->cabeca;
  elemento * pri_elem = cabeca->prox;
  int pri_dado = pri_elem->dado;
  cabeca->prox = pri_elem->prox;
  free(pri_elem);
  return pri_dado;
}

int filavazia(fila F){
  elemento * cabeca = F->cabeca;
  if(cabeca->prox == cabeca) return 1;
  else return 0;
}

void liberarfila(fila F){
  elemento * cabeca = F->cabeca;
  elemento * atual = cabeca->prox;
  while(atual != cabeca){
    elemento * temp = atual->prox;
    free(atual);
    atual = temp;
  }
  free(cabeca);
  free(F);
  return;
}
