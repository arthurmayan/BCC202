typedef struct Celula
{
    char nome[250];
    struct Celula *proximo;
}Celula;
    

typedef struct Pilha
{
    int tamanho;
    struct Celula *proximo, *fim;
    
}Pilha;

void inicia(Pilha *pilha);
int ehVazia(Pilha *pilha);
void enfileira(Pilha *pilha, char *nome);
void desenfileira(Pilha *pilha);
void imprime(Pilha *pilha);