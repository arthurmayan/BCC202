typedef int Chave;

typedef struct{
    Chave chave;
} Item;

typedef struct {
    Item *array;
    int tamanho_array, tamanho_max;
} Array;

void inicializaArray(Array *, int);
void insereRegistroArray(Array *, Item);
int pesquisaBinariaArray(Array *, Chave, int *);
void imprimeArray(Array *);
void deletaArray(Array *a);

