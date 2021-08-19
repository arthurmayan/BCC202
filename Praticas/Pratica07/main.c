#include <stdio.h>
#include <string.h>
#include "Pilha.h"

int main() {
    Pilha pilha;
    Pilha_Inicia(&pilha);

    Item string[20];

    unsigned int tam;

    do
    {
        fgets(string, 20, stdin);
        fflush(stdin);
        tam = strlen(string);
        string[tam - 1] = '\0';
        if(strcmp(string, "=") != 0)
        {
            Pilha_Push(&pilha, string);
        }
        
    }while(strcmp(string, "=") != 0);

    caluladoraHP(&pilha);
    return 0;
}
