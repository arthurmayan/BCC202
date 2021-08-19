#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int *v, int tamanho_vetor);

int main() 
{
    int tamanho_vetor = 200;

    int *v = (int*) malloc(tamanho_vetor * sizeof(int));

    preencheVetor(v, tamanho_vetor);

    quickSort(v, 0, tamanho_vetor -1);

    geradorTXTOrdenado(v, tamanho_vetor, "ordenado.txt");

    free(v);

    return 0;
}

void preencheVetor(int *v, int tamanho_vetor)
{
    int nro;
    for(int i = 0; i < tamanho_vetor; i++){
        nro = i+1;
        v[i] = nro;
    }
}


