#include "insertionSort.h"
#include <stdio.h>
#include <stdlib.h>

void insertioSort(int *v, int n)
{
    int aux, j;
    
    for(int i = 1; i < n; i++)
    {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && aux < v[j])
        {
            v[j + 1] = v[j];
            j--;
        }
        
        v[j + 1] = aux;
    }
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
