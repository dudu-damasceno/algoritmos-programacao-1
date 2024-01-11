
struct tminHeap{
  int * V;
  int n;
};

typedef struct tminHeap minHeap;

minHeap * cria_minHeap();

int remove_min(minHeap * H);

int verifica_min(minHeap * H);

void adiciona_elemento_minHeap(minHeap * H, int e);

void constroi_minHeap(minHeap * H);

void imprime_minHeap(minHeap * H);
