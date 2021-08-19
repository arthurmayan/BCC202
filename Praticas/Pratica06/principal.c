#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    int opcode;
    int elemento;

    Lista *lista = lst_cria();


    scanf("%d", &opcode);

    while(opcode != -1)
    {   
        switch (opcode)
        {
            case 2:
            {
                scanf("%d", &elemento);  
                lst_insere_ordenado (lista, elemento);
                break;
            }
            case 3:
            {
                scanf("%d", &elemento);  
                lst_retira (lista, elemento);
                break;
            }
            case 4:
            {
                scanf("%d", &elemento);
                lst_pertence(lista, elemento);
                break;
            }
            case 5:
            {
                lst_imprime (lista);
                break;
            }
        }
        scanf("%d", &opcode);
    }

    lst_liberar(lista);

    return 0;
}