#include "heap.h"

int comparacoes = 0;
int movimentacoes = 0;


void heapConstroi(Item *v, int n) 
{
    int esquerda;
    esquerda = (n / 2) - 1;
    
    while (esquerda >= 0)
    {
        heapRefaz(v, esquerda, n-1);
        esquerda--;
    }
}

void heapRefaz(Item *v, int esquerda, int direita)
{
    int i = esquerda;
    int j = i * 2 + 1;

    Item aux = v[i];

    while (j <= direita)
    {
        comparacoes++;
        if((j < direita) && (v[j].item < v[j + 1].item))
            j++;
        if(aux.item >= v[j].item)
            break;
        v[i] = v[j];
        movimentacoes++;
        i = j;
        j = i * 2 + 1;
    }
    v[i] = aux;
    movimentacoes++;
}

void heapSort(Item *v, int n)
{
    Item aux;
    heapConstroi(v, n);
    while (n > 1)
    {
        aux = v[n - 1];
        v[n-1] = v[0];
        v[0] = aux;
        n--;
        heapRefaz(v, 0, n - 1); // refaz o heap
    }
    
}

void imprimeVetor(Item *v, int tamanho_vetor)
{
    printf("\nOrdenado:\n");
    for(int i = 0; i < tamanho_vetor; i++)
    {
        printf("%d ", v[i].item);
    }
    printf("\n\nComparações: %d\nMovimentações: %d\n\n", comparacoes, movimentacoes);
    printf("\n");

    comparacoes = 0;
    movimentacoes = 0;
}