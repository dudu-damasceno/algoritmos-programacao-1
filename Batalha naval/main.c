#include <stdio.h>
#include <stdlib.h>

//Árvore binária que define o oceano
typedef struct tnoh{
  int dadox, dadoy;
  struct tnoh * esq;
  struct tnoh * dir;  
}oceano;

//Cria o primeiro nó da árvore binária
oceano * criar_oceano(int x, int y){
  oceano * n = (oceano *) malloc(sizeof(oceano));
  n->dadox = x;
  n->dadoy = y;
  n->esq = NULL;
  n->dir = NULL;
  return n;
}

//Função que adiciona um ponto
oceano * adiciona_ponto(oceano * r, int x, int y){
  //Cria a raiz
  if(r == NULL) return criar_oceano(x, y);
  //Adiciona e defina para que lado vai o ponto
  if(r->dadox >= x){
    if(r->dadox == x){
      if(r->dadoy > y){
        r->esq = adiciona_ponto(r->esq, x, y);
        return r;
      }
      else if(r-> dadoy < y){
        r->dir = adiciona_ponto(r->dir, x, y);
        return r;
      }
    }
    r->esq = adiciona_ponto(r->esq, x, y);
    return r;
  }else if(r->dadox < x){
    r->dir = adiciona_ponto(r->dir, x, y);
    return r;
  }
  return r;
}

//Função que busca se o ponto existe dentro da árvore binária
int busca_ponto(oceano * r, int x, int y){
  //Retorna 0 quando não for o ponto pedido ou nao existir
  if(r == NULL) return 0;
  //Retorna 1 quando existe ponto
  if(r->dadox == x && r->dadoy == y) return 1;
  if(r->dadox < x) return busca_ponto(r->dir, x, y);
  if(r->dadox >= x){
    if(r->dadox == x){
      if(r->dadoy > y){
        return busca_ponto(r->esq, x, y);
      }
      else return busca_ponto(r->dir, x, y);
    }
    return busca_ponto(r->esq, x, y);
  } 
  return 0;
}

//Função que libera a memória
void libera_oceano(oceano * r){
  free(r);
}

int main(int argc, char * argv[]){
  int dimensao;
  int num_pontos;
  int num_tiros;
  
  //TODO: GUARDAR OS OCEANOS DE A E B, MUDE PARA A ESTRUTURA
  //DE DADOS QUE VOCE QUISER
  oceano *pontosJA = NULL;
  oceano *pontosJB = NULL;

  scanf("%d %d %d", &dimensao, &num_pontos, &num_tiros);
  printf("Campo %d x %d\nCada jogador coloca %d barcos\n\n", dimensao, dimensao, num_pontos);
  
  //Definindo uma semente para gerar os mesmos pontos
  srand(dimensao);
 
  //Jogador A gera pontos para colocar os barcos
  printf("Jogador A coloca barcos:\n");
  for(int i = 0; i < num_pontos; i++){
    int x, y;
    //sorteia um ponto que ja nao tenha um barco
    do{
      x = rand() % dimensao;
      y = rand() % dimensao;
    }while(busca_ponto(pontosJA, x, y) != 0); //TODO: Procura no oceano A se x, y ja tem barco
  
    if(i<5) printf("(%d, %d)\n", x, y);
    
    pontosJA = adiciona_ponto(pontosJA, x, y);
  }
  
  //Jogador 2 gera pontos
  printf("...\n\nJogador B coloca barcos:\n");
  for(int i = 0; i < num_pontos; i++){
    int x, y;
    //sorteia um ponto que ja nao tenha um barco
    do{
      x = rand() % dimensao;
      y = rand() % dimensao;
    }while(busca_ponto(pontosJB, x, y) != 0); //TODO: Procura no oceano B se x, y ja tem barco
      
    if(i<5) printf("(%d, %d)\n", x, y);
    
    pontosJB = adiciona_ponto(pontosJB, x, y); //TODO: Adiciona x, y no oceano B
  }
  
  printf("...\n\nCada jogador vai dar %d tiros\n", num_tiros);
  
  
  //Jogador 1 ataca pontos (aleatorios)
  int acertosJA = 0;
  printf("\nJogador A atira:\n");
  for(int i = 0; i < num_tiros; i++){
    int x = rand() % dimensao;
    int y = rand() % dimensao;
    if(i<5) printf("(%d, %d)\n", x, y);
    
    //Jogador A ataca os pontos de B
    if(busca_ponto(pontosJB, x, y) == 1) acertosJA++; //TODO: Procura no oceano B se x, y tem barco
  }
  
  //Jogador B ataca pontos (aleatorios)
  int acertosJB = 0;
  printf("...\n\nJogador B atira:\n");
  for(int i = 0; i < num_tiros; i++){
    int x = rand() % dimensao;
    int y = rand() % dimensao;
    if(i<5) printf("(%d, %d)\n", x, y);

    //Jogador B ataca os pontos de A
    if(busca_ponto(pontosJA, x, y) == 1) acertosJB++; //TODO: Procura no oceano A se x, y ja tem barco
  }
  
  printf("...\n\nResultado: Jogador A acertou %d e Jogador B %d\n", acertosJA, acertosJB);
  
  libera_oceano(pontosJA); libera_oceano(pontosJB); //TODO: Liberar memorias
  return 0;
}