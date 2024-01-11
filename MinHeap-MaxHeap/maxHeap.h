
struct tmaxHeap{
  int * V;
  int n;
};

typedef struct tmaxHeap maxHeap;

maxHeap * cria_maxHeap();

int remove_max(maxHeap * H);

int verifica_max(maxHeap * H);

void adiciona_elemento_maxHeap(maxHeap * H, int e);

void constroi_maxHeap(maxHeap * H);

void imprime_maxHeap(maxHeap * H);
