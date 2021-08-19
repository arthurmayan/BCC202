typedef char Item;

typedef struct Fila{
    int tamanho;
    struct Celula *proximo, *fim;
} Fila;

void Fila_Inicia(Fila *pFila);

int Fila_EhVazia(Fila *pFila);

void Fila_Enfileira(Fila *pFila, Item *x);

void Fila_Desenfileira(Fila *pFila, Item **pX);

int Fila_Tamanho(Fila *pFila);
