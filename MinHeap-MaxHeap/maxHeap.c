#include <stdio.h>
#include <stdlib.h>
#include "maxHeap.h"


#define MAX 1000000



maxHeap * cria_maxHeap(){
  maxHeap * H = (maxHeap *) malloc(sizeof(maxHeap));
  H->V = (int*) malloc(MAX * sizeof(int));
  H->n = 0;
  return H;
}

int pai_max(int pos){
  return (pos - 1) / 2;
}

int esq_max(int pos){
  return 2 * pos + 1;
}

int dir_max(int pos){
  return 2 * pos + 2;
}

void desce_heap_max(maxHeap * H, int pos){
  int e = esq_max(pos);
  //pos nao tem filho
  if(e > H->n - 1) return;

  int maior_filho = e;
  
  int d = dir_max(pos);
  if(d <= H->n - 1 && H->V[d] > H->V[e]) 
    maior_filho = d;

  //variavel maior_filho contem o indice do
  //filho (existente) maior.
  if(H->V[pos] < H->V[maior_filho]){
    //esta errado, preciso trocar
    int aux = H->V[maior_filho];
    H->V[maior_filho] = H->V[pos];
    H->V[pos] = aux;
    desce_heap_max(H, maior_filho);
  }
  return;
}

int remove_max(maxHeap * H){
  int temp = H->V[0];
  H->V[0] = H->V[H->n - 1];
  H->n = H->n - 1;
  desce_heap_max(H, 0);
  return temp;
}


int verifica_max(maxHeap * H){
  return H->V[0];
}

void sobe_heap_max(maxHeap * H, int pos){
  if(pos == 0) return;
  int p = pai_max(pos);
  if(H->V[pos] > H->V[p]){
    //Esta errado, preciso trocar
    int aux = H->V[p];
    H->V[p] = H->V[pos];
    H->V[pos] = aux;
    sobe_heap_max(H, p);
  }
  return;
}

void adiciona_elemento_maxHeap(maxHeap * H, int e){
  H->V[H->n] = e;
  H->n = H->n + 1;
  sobe_heap_max(H, H->n - 1);
}

void imprime_maxHeap(maxHeap * H){
  for(int i = 0; i < H->n; i++){
    printf("%d ", H->V[i]);
  }
  printf("\n");
}

void constroi_maxHeap(maxHeap * H){
  for(int i = (H->n - 2) / 2; i >= 0; i--){
    desce_heap_max(H, i);
  }
}

