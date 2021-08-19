#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista 
{
        ListaNo *prim;
}Lista;

typedef struct listaNo
{
    int conteudo;
    ListaNo *prox;
    
}ListaNo;


Lista *lst_cria()
{
    Lista *l = malloc(sizeof(Lista));
    l->prim = NULL;

    return l;
}

ListaNo *criarListaNo(ListaNo *listaNo, int conteudo)
{
   ListaNo *no = malloc(sizeof(ListaNo));
   no->conteudo = conteudo;
   no->prox = NULL;

   return no;
}


int getConteudo(ListaNo *listaNo)
{
    return listaNo->conteudo;
}

void setConteudo(ListaNo *listaNo, int conteudo)
{
    listaNo->conteudo = conteudo;
}


void lst_imprime (Lista *l)
{
    for (ListaNo *aux = l->prim; aux != NULL; aux = aux->prox)
    {
        printf("%d ", aux->conteudo);
    }
    printf("\n");

}

int lst_pertence(Lista *l, int conteudo)
{
    for (ListaNo *aux = l->prim; aux != NULL; aux = aux->prox)
    {
        aux = aux->prox;

        if(aux->conteudo == conteudo)
        {
            return 1;
        }
    }

}

void lst_insere_ordenado ( Lista *l, int conteudo)
{
    ListaNo *anterior = NULL;
    ListaNo *proximo = l->prim;
    while(proximo != NULL && proximo->conteudo < conteudo){
        anterior = proximo;
        proximo = proximo->prox;
    }
    ListaNo * novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->conteudo = conteudo;
    if(anterior == NULL)
    {
        novo->prox = l->prim ;
        l->prim = novo ;
    }else
    {
        novo->prox = anterior->prox ;
        anterior->prox = novo;
    }
}

void lst_retira (Lista *l, int conteudo)
{
    ListaNo *anterior = NULL ;
    ListaNo *proximo= l->prim;

    while(proximo != NULL && proximo->conteudo != conteudo)
    {
        anterior = proximo;
        proximo = proximo->prox ;
    }

    if(proximo != NULL)
    {
        if(anterior == NULL)
            l->prim = proximo->prox ;
        else
            anterior->prox = proximo->prox;
        free(proximo);
    }
}

void lst_liberar(Lista *l)
{
    ListaNo *aux = l->prim;

    while(aux != NULL)
    {
        ListaNo *auxNo = aux->prox;
        free(aux);
        aux = auxNo;
    }
    free(l);
}





