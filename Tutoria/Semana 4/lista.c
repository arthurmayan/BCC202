#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct lista
{
    ListaNo *prim;
}Lista;

typedef struct listaNo
{
   char nome[20];
   int idade;
   ListaNo *prox;
}ListaNo;

Lista *criarLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->prim = NULL;
}

ListaNo *criarListaNo(char *nome, int idade)
{
    ListaNo *listaNo = malloc(sizeof(ListaNo));
    listaNo->idade = idade;

    strcpy(listaNo->nome, nome);
    listaNo->prox = NULL;
}

void inserirInicio(Lista *lista, char *nome, int idade)
{
    ListaNo *listaNo = criarListaNo(nome, idade);
    listaNo->prox = lista->prim;
    lista->prim = listaNo;
}

void inserirFinal(Lista *lista, char *nome, int idade)
{
    ListaNo *listaNo = criarListaNo(nome, idade);
    ListaNo *aux = lista->prim;
    ListaNo *proximo;

    if (aux == NULL)
    {
        lista->prim = listaNo;
    }
    else
    {
        proximo = aux->prox;
        while (proximo != NULL)
        {
            aux = proximo;
        }
        aux->prox = listaNo;
    }
}


/*void lst_imprime (Lista *l)
{
    for (ListaNo *aux = l->prim; aux != NULL; aux = aux->prox)
    {
        printf("Nome:%s\nIdade: %d\n", aux->nome, aux->idade);
    }
    printf("\n");

}*/

void lst_imprime (Lista *l)
{
    ListaNo *aux = l->prim;

    while(aux != NULL)
    {
        imprimeListaNo(aux);
        aux = aux->prox;
    }
}

void imprimeListaNo(ListaNo *listaNo)
{
    if (listaNo != NULL)
    {
        printf("Nome: %s\nIdade: %d\n", listaNo->nome, listaNo->idade);
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

void lst_insere_ordenado ( Lista *l, char conteudo)
{
    ListaNo *anterior = NULL;
    ListaNo *proximo = l->prim;
    while(proximo != NULL && proximo->idade < conteudo){
        anterior = proximo;
        proximo = proximo->prox;
    }
    ListaNo * novo = (ListaNo*) malloc(sizeof(ListaNo));
    novo->idade = conteudo;
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

void lst_pertence(Lista *l, char conteudo)
{
    for (ListaNo *aux = l->prim; aux != NULL; aux = aux->prox)
    {
        aux = aux->prox;

        if(strcmp(aux->nome, &conteudo) == 0)
        {
            printf("NOME ENCONTRADO!");
        }
    }
}

void lst_retira (Lista *l, int idade, char nome)
{
    // idade 

    ListaNo *anterior = NULL ;
    ListaNo *proximo= l->prim;

    while(proximo != NULL && proximo->idade != idade)
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

    /// nome

    while(  (proximo != NULL) &&  (strcmp(proximo->nome, &nome) != 0) )
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




