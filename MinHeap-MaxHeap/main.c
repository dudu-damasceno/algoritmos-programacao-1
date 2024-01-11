#include <stdio.h>
#include <stdlib.h>
#include "maxHeap.h"
#include "minHeap.h"

double mediana(minHeap * Hmaiores, maxHeap * Hmenores){
  if(Hmaiores->n == Hmenores->n + 1){
    //maiores tem 1 a mais (tem a mediana)
    return (double) verifica_min(Hmaiores);
  }
  if(Hmaiores->n + 1 == Hmenores->n){
    //menores tem 1 a mais (tem a mediana)
    return (double) verifica_max(Hmenores);
  }
  //tem o mesmo tamanho
  return ((double) ((double) verifica_min(Hmaiores) + (double) verifica_max(Hmenores))) / 2.0;
}

int main(int argc, char * argv[]){
  minHeap * Hmaiores = cria_minHeap();
  
  maxHeap * Hmenores = cria_maxHeap();

  int novo_numero;
  scanf("%d", &novo_numero);
    while(novo_numero != -1){
    double mediana_antiga = mediana(Hmaiores, Hmenores);
    if((double) novo_numero >= mediana_antiga){
      //preciso inserir entre os maiores
      adiciona_elemento_minHeap(Hmaiores, novo_numero);
      //se tivemos problemas de balanceamento
      if(Hmaiores->n > Hmenores->n+1){
        //se Hmaiores tiver 2 elementos a mais;
        //o menor vai para o Hmenores
        adiciona_elemento_maxHeap(Hmenores, remove_min(Hmaiores));
      }
    }else{
      //preciso inserir entre os menores
      adiciona_elemento_maxHeap(Hmenores, novo_numero);
      //se tivemos problemas de balanceamento
      if(Hmenores->n > Hmaiores->n+1){
        //se Hmenores tiver 2 elementos a mais;
        //o mmaior vai para o Hmaiores
        adiciona_elemento_minHeap(Hmaiores, remove_max(Hmenores));
      }
    }
    printf("Mediana: %.1lf\n", mediana(Hmaiores, Hmenores));
    scanf("%d", &novo_numero);
  }
  
  
  return 0;
}

