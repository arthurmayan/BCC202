#include <stdio.h>
#include <stdlib.h>
#include "carro.h"

int main()
{
    int n;
    printf("Qual a quantidade de carros? ");
    scanf("%d", &n);

    Carro **carro = malloc(n * sizeof(Carro*));

    char modelo[20], cor[20];
    int ano;
    double preco, km;

    printf("\nN = %d", n);

    for(int i = 0; i < n; i++)
    {
        printf("\n\nDigite o nome do modelo: ");
        scanf("%s", modelo);
        printf("\nDigite o nome da cor: ");
        scanf("%s", cor);
        printf("\nDigite o ano: ");
        scanf("%d", &ano);
        printf("\nDigite o preço: ");
        scanf("%lf", &preco);
        printf("\nDigite a quilometragem: ");
        scanf("%lf", &km);
        
        carro[i] = criarCarro(modelo, cor, ano, preco, km);
    }

    char buscar[20];
    printf("\nQual carro você gostaria de buscar? ");
    scanf("%s", buscar);

	mostrarCarroEspecifico(carro, buscar, n);
	return 0;
}

