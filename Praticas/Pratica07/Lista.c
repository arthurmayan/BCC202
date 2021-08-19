#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void Lista_Inicia(Lista *pLista){
    pLista->inicio = NULL;
    pLista->fim = NULL;
    pLista->tamanho = 0;
}

int Lista_EhVazia(Lista *pLista){
    if(pLista->inicio == NULL)
        return 1;
    return 0;
}

void Lista_Insere(Lista *pLista, int p, Item *x){
    Celula *celula = (Celula*) malloc(sizeof(Celula));
    Celula *ant = NULL;
    Celula *prox =  NULL;
    Celula *aux = pLista->inicio;
    int posicao = 0;
    strcpy(celula->item, x);
    celula->proximo = NULL;

    while(aux != NULL)
    {
        if(posicao == p)
        {
            ant = aux;
            break;
        }

        posicao++;
        aux = aux->proximo;
    }

    if (ant != NULL)
    {
        while(aux != NULL)
        {
            if (posicao == p-1)
            {
                prox = ant->proximo;
                ant->proximo = celula;
                celula->proximo = prox;
                break;
            }
            aux = aux->proximo;
        }
    }

    if(ant == NULL){
        celula->proximo = pLista->inicio;
        pLista->inicio = celula;
        pLista->tamanho++;
    }
}

int Lista_Remove(Lista *pLista, int p, Item **pX){
    Celula *celula = pLista->inicio;
    pLista->inicio = celula->proximo;
    strcpy(*pX, celula->item);
    free(celula);
    pLista->tamanho--;
    return 1;
}

int Lista_Tamanho(Lista *pLista){
    return pLista->tamanho;
}