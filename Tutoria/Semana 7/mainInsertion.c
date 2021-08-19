#include <stdio.h>
#include <stdlib.h>

#include "insertionSort.h"

int main() 
{
    int n;
    int *v;
    
    FILE *arquivo = fopen("dados.txt", "r");
    
    fscanf(arquivo, "%d", &n);
    
    v = (int*) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++)
    {
        fscanf(arquivo, "%d", &v[i]);
    }
    
    insertioSort(v, n);
    imprimeVetor(v, n);
    
    return 0;
}



