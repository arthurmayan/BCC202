#include <stdio.h>
#include <stdlib.h>

#include "selectionSort.h"

void selectionSort(int *v, int n)
{
    int min;
    
    for(int i = 0; i < n; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(v[j] < v[min])
                min = j;
        }
        
        if(i != min)
        {
            troca(v, i, min);
        }
    }
}

void troca(int *v, int i, int min)
{
    int aux = v[i];
    
    v[i] = v[min];
    v[min] = aux;
}

void imprimeVetor(int *v, int n)
{
    printf("vetor >> [ ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}
