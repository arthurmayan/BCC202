#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define MAXTAM 1000

typedef struct lista 
{
        int conteudo[MAXTAM];
        int n;
}Lista;


Lista *lst_cria()
{
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->n = 0;

    return l;
}


void lst_imprime (Lista *l)
{
    for (int i = 0; i < l->n; i++)
    {
        printf("%d ", l->conteudo[i]);
    }
    printf("\n");

}

int lst_pertence(Lista *l, int conteudo)
{
    for (int i = 0; i < l->n; i++)
    {
        if(l->conteudo[i] == conteudo)
        {
            return 1;
        }
    }

}

void lst_insere_ordenado (Lista *l, int conteudo)
{
    l->conteudo[l->n] = conteudo;
    l->n = l->n+1;

    int aux = 0;

    for (int i = 0; i < l->n; i++)
    {
        for (int j = 0; j < l->n; j++)
        {
            if (l->conteudo[i] < l->conteudo[j])
            {
                aux = l->conteudo[i];
                l->conteudo[i] = l->conteudo[j];
                l->conteudo[j] = aux;
            }
        }
    }
}

void lst_retira (Lista *l, int conteudo)
{
    for(int i = 0; i < l->n; i++ )
    {
        if( l->conteudo[i] == conteudo )
        {
            for(int j = i; j < l->n-1; j++ )
            {
                l->conteudo[j] = l->conteudo[j+1];
            }
        l->n--;
        }
    }
}

void lst_liberar_vetor(Lista **l)
{
    free(*l);
}





