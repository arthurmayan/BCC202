#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

void inicia(Fila *fila)
{
    fila->tamanho = 0;
    fila->proximo = NULL;
    fila->fim = NULL;
}

int ehVazia(Fila *fila)
{
    if (fila->tamanho == 0)
    {
        return 1;
    }
    return 0;
}

void enfileira(Fila *fila, char *nome, char *descricao)
{
    Celula *celula = (Celula*) malloc(sizeof(Celula));

    strcpy(celula->nome, nome);
    strcpy(celula->descricao, descricao);

    celula->proximo = NULL;

    if(fila->fim == NULL)
    {
        fila->proximo = celula;
        fila->fim = celula;
    }else
    {
        fila->fim->proximo = celula;
        fila->fim = celula;
    }
    fila->tamanho++;
}

void desenfileira(Fila *fila)
{
    Celula *aux = fila->proximo;

    if (fila->tamanho > 0)
    {
        fila->proximo = aux->proximo;
        free(aux);
        fila->tamanho--;

        if (fila->proximo == NULL)
        {
            fila->fim = NULL;
        }
    }
}

void removeTodos(Fila *fila)
{
   
}

int tamanho(Fila *fila)
{
    return fila->tamanho;
}

void imprime(Fila *fila)
{
    Celula *aux = fila->proximo;

    while (aux != NULL)
    {
        printf("Paciente: %s\nDescricao: %s\n", aux->nome, aux->descricao);
        aux = aux->proximo;
    }
}

