#include <stdlib.h>
#include "Lista.h"

#include "Fila.h"

void Fila_Inicia(Fila *pFila){
    pFila->tamanho = 0;
    pFila->proximo = NULL;
    pFila->fim = NULL;
}

int Fila_EhVazia(Fila *pFila){
    Lista aux;
    aux.inicio = pFila->proximo;
    aux.fim = pFila->fim;
    aux.tamanho = pFila->tamanho;
    return Lista_EhVazia(&aux);
}

void Fila_Enfileira(Fila *pFila, Item *x){
    Lista aux;
    Lista_Inicia(&aux);
    if(Fila_EhVazia(pFila)){
        Lista_Insere(&aux, pFila->tamanho, x);
        pFila->proximo = aux.inicio;
        pFila->fim = aux.fim;
        pFila->tamanho = aux.tamanho;
    }else{
        aux.inicio = pFila->proximo;
        aux.fim = pFila->fim;
        aux.tamanho = pFila->tamanho;
        Lista_Insere(&aux, pFila->tamanho, x);
        pFila->proximo = aux.inicio;
        pFila->fim = aux.fim;
        pFila->tamanho = aux.tamanho;
    }
}

void Fila_Desenfileira(Fila *pFila, Item **pX){
    Lista aux;
    aux.inicio = pFila->proximo;
    aux.fim = pFila->fim;
    aux.tamanho = pFila->tamanho;
    Lista_Remove(&aux, pFila->tamanho, pX);
    pFila->proximo = aux.inicio;
    pFila->fim = aux.fim;
    pFila->tamanho = aux.tamanho;
}

int Fila_Tamanho(Fila *pFila){
    Lista aux;
    aux.tamanho = pFila->tamanho;
    Lista_Tamanho(&aux);
    pFila->tamanho = aux.tamanho;
    return pFila->tamanho;
}