#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main()
{
    char nome[20];
    int idade, n;

    Lista *inicio = criarLista();
    Lista *final = criarLista();

    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Qual o nome? ");
        scanf("%s", nome);

        printf("Qual a idade? ");
        scanf("%d", &idade);

        inserirInicio(inicio, nome, idade);
        inserirFinal(final, nome, idade);
    }

    lst_imprime(inicio);
    lst_imprime(final);

    return 0;
}