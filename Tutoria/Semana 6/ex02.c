#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

int main() 
{
    char nome[250];

    int opcode;
    Pilha pilha;
    inicia(&pilha);

    int tamanho_string;
    int tamanho_string1;


    do {
        scanf("%d", &opcode);
        fflush(stdin);

        switch (opcode) 
        {
            case 1:
            {
                scanf("%s", nome);
                
                enfileira(&pilha, nome);

                break;
            }
            case 2:
            {
                desenfileira(&pilha);
                break;
            }
            case 3:
            {
                imprime(&pilha);
                break;
            }
            case -1:
            {
                printf("Fim de execucao\n");
            }
        }
    } while(opcode != -1);

    return 0;
}