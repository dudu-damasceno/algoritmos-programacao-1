#include <stdio.h>
#include <stdlib.h>

typedef struct tnoh{
  int dado;
  struct tnoh * esq;
  struct tnoh * dir;  
}noh;

noh * criar_noh(int d){
  noh * n = (noh *) malloc(sizeof(noh));
  n->dado = d;
  n->esq = NULL;
  n->dir = NULL;
  return n;
  //(6 , (5 , (7 ,  ,  ) , (8 ,  ,  ) ) , (3 ,  ,  ) )
}

void imprimir_arvore(noh * r){
  if(r == NULL) return;
  printf("(%d, ", r->dado);
  imprimir_arvore(r->esq);
  printf(", ");
  imprimir_arvore(r->dir);
  printf(")");
  return;
}

void imprimir_red(noh * r){
  if(r == NULL) return;
  printf("%d ", r->dado);
  imprimir_red(r->esq);
  imprimir_red(r->dir);
}

void imprimir_erd(noh * r){
  if(r == NULL) return;
  imprimir_erd(r->esq);
  printf("%d ", r->dado);
  imprimir_erd(r->dir);
}

noh * adiciona_elemento(noh * r, int d){
  if(r == NULL){
    return criar_noh(d);
  }
  if(r->dado >= d){
    r->esq = adiciona_elemento(r->esq, d);
  }else if(r->dado < d){
    r->dir = adiciona_elemento(r->dir, d);
  }
  return r;
}

//devolve o endereco do noh se existir
//NULL se nÃ£o existir
noh * buscar_elemento(noh * r, int d){
  if(r == NULL) return NULL;
  if(r->dado == d) return r;
  if(r->dado >= d) return buscar_elemento(r->esq, d);
  else return buscar_elemento(r->dir, d);
}

int main(int argc, char * argv[]){
  noh * raiz = NULL;
  raiz = adiciona_elemento(raiz, 10);
  raiz = adiciona_elemento(raiz, 7);
  raiz = adiciona_elemento(raiz, 3);
  raiz = adiciona_elemento(raiz, 15);
  raiz = adiciona_elemento(raiz, 14);
  raiz = adiciona_elemento(raiz, 19);
  raiz = adiciona_elemento(raiz, 11);

//(10, (7, (3, , ), ), (15, (14, (11, , ), ), (19, , )))

  if(buscar_elemento(raiz, 11) == NULL){
    printf("Naum existe 11\n");
  }else{
    printf("Existe 11\n");
  }
  if(buscar_elemento(raiz, 15) == NULL){
    printf("Naum existe 15\n");
  }else{
    printf("Existe 15\n");
  }

  if(buscar_elemento(raiz, 20) == NULL){
    printf("Naum existe 20\n");
  }else{
    printf("Existe 20\n");
  }

  imprimir_arvore(raiz);
  printf("\n");
  return 0;
}