// Arthur Mayan Faria de Almeida - 18.2.4149

#include <stdio.h>
#include "rec.h"

int main()
{
    // ************************ EX01 ****************************************
    printf(" EX 01 \n");

    int v[5] = {1, 2, 3, 4, 5};
    int chave = 4;

    int tamanho = sizeof(v)/sizeof(int);


    printf("POSICAO: %d\n\n", pesquisaBinaria(v, chave, 0, tamanho - 1));

    // ************************ EX02 ****************************************
    printf(" EX 02 \n");

    int x = 4;

    printf("Fatorial de %d é igual a %d\n\n", x, fatorialRecursiva(x));


    // ************************ EX03 ****************************************
    printf(" EX 03 \n");

    int dividendo = 153;
    int divisor = 15;
    int resto;

    printf("%d dividido por %d é igual a %d\n", dividendo, divisor, divisaoRecursiva(dividendo, divisor, &resto));
    printf("Resto: %d\n", resto);

    return 0;
}




