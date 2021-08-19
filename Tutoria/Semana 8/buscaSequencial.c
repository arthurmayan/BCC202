#include <stdio.h>
#include <stdlib.h>
#include "buscaSequencial.h"
#include "buscaBinaria.h"


void inicializaArrayBS(ArrayBS *a, int tamanho_max)
{
    a->tamanho_array = 0;
    a->tamanho_max = tamanho_max;
    a->array = (ItemBS*) malloc(tamanho_max * sizeof(ItemBS));
}

void insereRegistroArrayBS(ArrayBS *a, ItemBS x)
{
    if(a->tamanho_array == a->tamanho_max){
        a->tamanho_max *= 2;
        a->array = (ItemBS*) realloc(a->array, a->tamanho_max * sizeof(ItemBS));
    }

    a->array[a->tamanho_array++] = x;
}

void imprimeArrayBS(ArrayBS *a)
{
    for(int i = 0; i < a->tamanho_array; i++)
        printf("%d\n", a->array[i].chave);
    printf("\n");
}

int pesquisaSequencialArray(ArrayBS *a, ChaveBS x, int *comparacoes)
{
    for(int i = 0; i < a->tamanho_array; i++){
        *comparacoes = *comparacoes + 1;
        if(a->array[i].chave == x)
            return a->array[i].chave;
    }
    return -1;
}

void deletaArrayBS(ArrayBS *a)
{
    free(a->array);
}

void insereBusca(Array *a, int *v){
    Item aux;
    for(int i = 0; i < a->tamanho_max; i++) {
        aux.chave = v[i];
        insereRegistroArray(a, aux);
    }
}

void insereBuscaBS(ArrayBS *a, int *v){
    ItemBS aux;
    for(int i = 0; i < a->tamanho_max; i++) {
        aux.chave = v[i];
        insereRegistroArrayBS(a, aux);
    }
}

void imprimeVetor(int *v, int tamanho_vetor){
    for(int i = 0; i < tamanho_vetor; i++)
        printf("%d\n", v[i]);
    printf("\n");
}

void lerTXT(int *v, int tamanho_vetor, char nome_do_txt[]){
    FILE *arquivo = fopen(nome_do_txt, "r");
    for(int i = 0; i < tamanho_vetor; i++)
        fscanf(arquivo, "%d\n", &v[i]);
    fclose(arquivo);
}

