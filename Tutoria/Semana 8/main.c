#include <stdio.h>
#include <stdlib.h>
#include "buscaBinaria.h"
#include "buscaSequencial.h"

int main() 
{
    int tamanho_vetor = 200, comparacoes = 0, comparacoes_BS = 0;

    Array array;
    ArrayBS array_BS;
    Chave item_pesquisar = 999;
    ChaveBS item_pesquisar_BS = 999;

    inicializaArray(&array, tamanho_vetor);
    inicializaArrayBS(&array_BS, tamanho_vetor);

    int *v = (int*) malloc(tamanho_vetor * sizeof(int));

    lerTXT(v, tamanho_vetor, "ordenado.txt");

    insereBusca(&array, v);
    insereBuscaBS(&array_BS, v);

    free(v);

    if(pesquisaBinariaArray(&array, item_pesquisar, &comparacoes) != -1)
        printf("Comparacoes Busca Binaria: %d\n", comparacoes);
    else
        printf("Comparacoes Busca Binaria: %d\n", comparacoes);

    if(pesquisaSequencialArray(&array_BS, item_pesquisar_BS, &comparacoes_BS) != -1)
        printf("Comparacoes Busca Sequencial: %d\n", comparacoes_BS);
    else
        printf("Comparacoes Busca Sequencial: %d\n", comparacoes_BS);

    deletaArray(&array);
    deletaArrayBS(&array_BS);

    return 0;
}

