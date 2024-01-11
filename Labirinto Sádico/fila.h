#include <stdlib.h>

//Definicao do tipo fila
typedef struct tfila * fila;

//funcao que cria fila e aloca memoria
fila criarfila();

//funcao que recebe uma fila e um novo elemento que vai entrar na fila
//nessa implementacao a fila nao precisa ser alterada, por isso uma 
//adicao nao precisa retornar nada
void colocarnafila(fila F, int x);

//funcao que devolve o primeiro elemento da fila (a fila nao pode estar vazia)
int retirardafila(fila F);

//funcao que verifica se uma fila esta vazia
int filavazia(fila F);

//funcao que libera toda memoria alocada na fila, incluindo elementos que ainda
//possam ter ficado nela.
void liberarfila(fila F);

