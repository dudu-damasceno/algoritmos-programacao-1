/***************************
Labirinto Sádico: Um jogador é jogado aleatoriamente em uma das salas de um
labirinto na qual ele deve chegar até a saída. Em cada sala toca uma sirene,
com um som de sertanejo universitário, que é mais baixa, quanto mais perto
estiver da saida. O objetivo do jogo é sair antes que voce fique maluco.
Autores: João Vítor Botrel e Luís Eduardo Damasceno
Data da última atualização: 19/10/2022
***************************/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h" //Biblioteca incluida com o intuito de colocar as funções para a TAD fila

//Não estava funcionando se não declarasse aqui
typedef struct telemento
{
  int dado;
  struct telemento *prox;
} elemento;

struct tfila
{
  elemento *cabeca;
};


//Função que vai transformar a matriz char em inteira e colocar seus volumes nas salas
void distancias(char **matriz, int n)
{
  int **Ant = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    Ant[i] = (int *)malloc(n * sizeof(int));
  }

  // Percorrendo a matriz para igualar ela a n*n
  for (int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++){
      Ant[i][j] = n*n;
    }  
  }
  // Igualando a primeira casa das matrizes a 0
  matriz[0][0] = 0;
  Ant[0][0] = 0;

  // Fila criada 
  fila F = criarfila();
  // Colocando o unico volume conhecido na fila
  colocarnafila(F, 0);
  colocarnafila(F, 0);

  //loop para descubrir os volumes de cada sala
  while (!filavazia(F))
  {
    int i = retirardafila(F);
    int j = retirardafila(F);
     if ((i!= n-1) && (matriz[i+1][j] == '0') && (Ant[i+1][j] == n*n))
      { 
        colocarnafila(F, i+1);
        colocarnafila(F, j);  
        Ant[i+1][j] = Ant[i][j] + 1;

      }
      if( (i!= 0) && (matriz[i-1][j] == '0')  && (Ant[i-1][j]== n*n)){
        colocarnafila(F, i-1);
        colocarnafila(F, j);  
        Ant[i-1][j] = Ant[i][j] + 1;
      }
      if( (j!= 0) && (matriz[i][j-1] == '0') && (Ant[i][j-1] == n*n)){
        colocarnafila(F, i);
        colocarnafila(F, j-1);  
        Ant[i][j-1] = Ant[i][j] + 1;
      }
      if( (j!= n-1) && (matriz[i][j+1] == '0') && (Ant[i][j+1] == n*n)){
        colocarnafila(F, i);
        colocarnafila(F, j+1);  
        Ant[i][j+1] = Ant[i][j] + 1;
      }

    }
  
  // For para imprimir a matriz
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", Ant[i][j]);
    }
    printf("\n");
  }

  //Liberando memoria da fila
  free(F);
  //Liberando memoria da matrize
  for (int i = 0; i < n; i++)
    {
        free(Ant[i]);
    }

    free(Ant);

}



// Função principal do jogo
int main(int argc, char *argv[])
{
  //Declarar as variáveis
  char **matriz;
  int n;

  //Ler a dimensão do tabuleiro
  scanf("%d", &n);

  //Alocação dinâmica da primeira matriz que será o tabuleiro
  matriz = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++)
  {
    matriz[i] = (char *)malloc(n * sizeof(char));
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf(" %c", &(matriz[i][j]));
    }
  }
 

  //Imprimir a matriz inteira com os volumes em cada sala
  distancias(matriz, n);

  //Liberando a memória da matriz char
   for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
  return 0;
}