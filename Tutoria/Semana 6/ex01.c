#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"

int main() 
{
    char nome[250];
    char descricao[250];
    int opcode;
    Fila fila;
    inicia(&fila);
    int tamanho_string;
    int tamanho_string1;


    do {
        scanf("%d", &opcode);
        fflush(stdin);

        switch (opcode) 
        {
            case 1:
            {
                fgets(nome, 250, stdin);
                fflush(stdin);
                fgets(descricao, 250, stdin);
                fflush(stdin);


                tamanho_string = strlen(nome);
                nome[tamanho_string - 1] = '\0';
                tamanho_string1 = strlen(descricao);
                descricao[tamanho_string1 - 1] = '\0';
                
                
                enfileira(&fila, nome, descricao);

                break;
            }
            case 2:
            {
                imprime(&fila);
                break;
            }
            case 3:
            {
                desenfileira(&fila);
                break;
            }
            case 4:
            {
                removeTodos(&fila);
                break;
            }
        }
    } while(opcode != -1);

    return 0;
}