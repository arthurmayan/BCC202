#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

void inicia(Pilha *pilha)
{
    pilha->tamanho = 0;
    pilha->proximo = NULL;
    pilha->fim = NULL;
}

int ehVazia(Pilha *pilha)
{
    if (pilha->tamanho == 0)
    {
        return 1;
    }
    return 0;
}

void enfileira(Pilha *pilha, char *nome)
{
    Celula *celula = (Celula*) malloc(sizeof(Celula));

    celula->proximo = pilha->proximo;

    strcpy(celula->nome, nome);

    pilha->proximo = celula;

    pilha->tamanho++;
}

void desenfileira(Pilha *pilha)
{
    Celula *aux = pilha->proximo;

    if (pilha->tamanho > 0)
    {
        pilha->proximo = aux->proximo;
        free(aux);
        pilha->tamanho--;

        if (pilha->proximo == NULL)
        {
            pilha->fim = NULL;
        }
    }
}

void imprime(Pilha *pilha)
{
    Celula *aux = pilha->proximo;

    while (aux != NULL)
    {
        printf("%s\n", aux->nome);
        aux = aux->proximo;
    }
}