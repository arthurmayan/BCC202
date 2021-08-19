#include "buscaBinaria.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaArray(Array *a, int tamanho_max)
{
    a->tamanho_array = 0;
    a->tamanho_max = tamanho_max;
    a->array = (Item*) malloc(tamanho_max * sizeof(Item));
}

void insereRegistroArray(Array *a, Item x)
{
    if(a->tamanho_array == a->tamanho_max)
    {
        a->tamanho_max *= 2;
        a->array = (Item*) realloc(a->array, a->tamanho_max * sizeof(Item));
    }

    a->array[a->tamanho_array++] = x;
}

void imprimeArray(Array *a)
{
    for(int i = 0; i < a->tamanho_array; i++)
        printf("%d\n", a->array[i].chave);
    printf("\n");
}

int pesquisaBinariaArray(Array *a, Chave x, int *comparacoes)
{
    int i, esquerda, direita;
    if(a->tamanho_array == 0)
        return -1;
    esquerda = 0;
    direita = a->tamanho_array - 1;
    do{
        *comparacoes = *comparacoes +1;
        i = (esquerda + direita) / 2;
        if(x > a->array[i].chave)
            esquerda = i + 1;
        else
            direita = i - 1;
    }while (x != a->array[i].chave && esquerda <= direita);
    if(x == a->array[i].chave)
        return i;
    else
        return -1;
}

void deletaArray(Array *a)
{
    free(a->array);
}
