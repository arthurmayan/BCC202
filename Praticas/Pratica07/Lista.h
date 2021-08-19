typedef char Item;

typedef struct Celula{
    Item item[20];
    struct Celula *proximo, *fim;
}Celula;

typedef struct Lista{
    int tamanho;
    struct Celula *inicio, *fim;
} Lista;

/* inicia uma lista */
void Lista_Inicia(Lista *pLista);
/* retorna 1 se a lista for vazia e 0 caso contrario */
int Lista_EhVazia(Lista *pLista);
/* insere o elemento x na posição p da lista */
void Lista_Insere(Lista *pLista, int p, Item *x);
/* retira o elemento da posição p da lista e o retorna pelo parâmetro pX
* a função retorna 0 caso não haja elemento na posição p da lista e 1 caso contrario */
int Lista_Remove(Lista *pLista, int p, Item **pX);
/* retorna o tamanho da lista */
int Lista_Tamanho(Lista *pLista);
