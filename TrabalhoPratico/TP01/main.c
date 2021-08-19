// Arthur Mayan - 18.2.4149

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "arquivo.h"

int main()
{
    printf("\n###### MENU ######\n\n");
    printf("1 - JOGO DA VELHA\n2 - JOKEMPO\n3 - CRIPTOGRAFIA\n\n");
    printf("QUAL A OPÇÃO DESEJADA? ");
    int opcode;
    scanf("%d", &opcode);

    switch (opcode)
    {
    case 1:
        printf("\n###### JOGO DA VELHA ######\n");
        jogoDaVelha(3,3);
        break;
    case 2:
        printf("\n###### JOKEMPO ######\n");
        Placar *placar = criarPlacar();
        jokempo(placar);
        break;
    case 3:
        printf("\n###### CRIPTOGRAFIA ######\n");
        int x;
        scanf("%d", &x);
        criptografia(x);
        break;
    }

    return 0;
}