#include <stdio.h>
#include <stdlib.h>

typedef struct item{
  int item;
} Item;

void heapConstroi(Item *v, int n);
void heapRefaz(Item *v, int esquerda, int direita);
void heapSort(Item *v, int n);
void imprimeVetor(Item *v, int tamanho_vetor);
