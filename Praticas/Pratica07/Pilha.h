
typedef char Item;

typedef struct Celula{
    Item item[20];
    struct Celula *proximo;
} Celula;

typedef struct Pilha{
    int tamanho;
    struct Celula *proximo;
} Pilha;

void Pilha_Inicia(Pilha *pPilha);

int Pilha_EhVazia(Pilha *pPilha);

void Pilha_Push(Pilha *pPilha, Item *x);

int Pilha_Pop(Pilha *pPilha, Item **pX);

int Pilha_Tamanho(Pilha *pPilha);

void Imprime_Pilha(Pilha *pPilha);

Pilha Pilha_Reversa(Pilha *pPilha);

void caluladoraHP(Pilha *pPilha);
