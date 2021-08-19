#include "heap.h"

int main() 
{
    int n;
    int tamanho_vetor;

    printf("Quantos vetores você deseja ordenar? ");
    scanf("%d", &n);
    printf("\n");

    Item *v;
    do{
        printf("Qual o tamanho do vetor? ");
        scanf("%d", &tamanho_vetor);
        printf("Digite o vetor: ");

        v = (Item*) malloc(tamanho_vetor * sizeof(Item));

        for(int i = 0; i < tamanho_vetor; i++) {
            scanf("%d", &v[i].item);
        }

        heapSort(v, tamanho_vetor);
        imprimeVetor(v, tamanho_vetor);

        free(v);
        
        n--;
    } while (n > 0);
    return 0;
}




