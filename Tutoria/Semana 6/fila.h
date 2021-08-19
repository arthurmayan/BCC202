typedef struct Celula
{
    char nome[250];
    char descricao[250];
    struct Celula *proximo;
}Celula;
    

typedef struct Fila
{
    int tamanho;
    struct Celula *proximo, *fim;
    
}Fila;

void inicia(Fila *fila);
int ehVazia(Fila *fila);
void enfileira(Fila *fila, char *nome, char *descricao);
void desenfileira(Fila *fila);
void removeTodos(Fila *fila);
int tamanho(Fila *fila);
void imprime(Fila *fila);


