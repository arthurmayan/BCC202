typedef int ChaveBS;

typedef struct{
    ChaveBS chave;
} ItemBS;

typedef struct {
    ItemBS *array;
    int tamanho_array, tamanho_max;
} ArrayBS;

void deletaArrayBS(ArrayBS *a);
void inicializaArrayBS(ArrayBS *, int);
void insereRegistroArrayBS(ArrayBS *, ItemBS);
int pesquisaSequencialArray(ArrayBS *, ChaveBS, int *);
void imprimeArrayBS(ArrayBS *);


void insereBusca(Array *, int *);
void insereBuscaBS(ArrayBS *, int *);
void imprimeVetor(int *, int);
void lerTXT(int *, int, char[]);