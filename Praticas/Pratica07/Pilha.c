#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"

void Pilha_Inicia(Pilha *pPilha)
{
    pPilha->proximo = NULL;
    pPilha->tamanho = 0;
}

int Pilha_EhVazia(Pilha *pPilha)
{
    if(pPilha->proximo == NULL)
    {
        return 1;
    }
    return 0;
}

void Pilha_Push(Pilha *pPilha, Item *x)
{
    Celula *celula = (Celula*) malloc(sizeof(Celula));

    celula->proximo = pPilha->proximo;

    strcpy(celula->item, x);
    pPilha->proximo = celula;
    pPilha->tamanho++;
}

int Pilha_Pop(Pilha *pPilha, Item **pX)
{
    if(pPilha == NULL)
    {
        return 0;
    }

    Celula *celula = pPilha->proximo;

    pPilha->proximo = celula->proximo;

    strcpy(*pX, celula->item);

    free(celula);

    pPilha->tamanho--;

    return 1;
}

void Pilha_Libera(Pilha *pilha)
{
    char *string = malloc(sizeof(char));

    while(!Pilha_EhVazia(pilha))
    {
        Pilha_Pop(pilha, &string);
    }
}

int Pilha_Tamanho(Pilha *pPilha)
{
    return pPilha->tamanho;
}

void Imprime_Pilha(Pilha *pPilha)
{
    Celula *aux = pPilha->proximo;

    while(aux != NULL)
    {
        printf("%s\n", aux->item);
        aux = aux->proximo;
    }
}

Pilha Pilha_Reversa(Pilha *pPilha)
{
    Pilha pilha_reversa;

    Pilha_Inicia(&pilha_reversa);

    Item *string_aux = malloc(sizeof(Item));

    while(!Pilha_EhVazia(pPilha))
    {
        Pilha_Pop(pPilha, &string_aux);
        Pilha_Push(&pilha_reversa, string_aux);
    }

    return pilha_reversa;
}

int Verifica_Caracter(Celula *celula)
{
    if(strcmp(celula->item, "*") == 0)
    {
        return 1;
    }
    else if(strcmp(celula->item, "/") == 0)
    {
        return 2;
    }
    else if(strcmp(celula->item, "+") == 0)
    {
        return 3;
    }
    else if(strcmp(celula->item, "-") == 0)
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

int Converte_String_To_Int(Item *item)
{
    char *ptr;
    return strtol(item, &ptr, 10);
}

void Converte_Int_To_String(int resultado, Item *pItem)
{
    sprintf(pItem, "%d", resultado);
}

int Operacoes(int numero1, int numero2, int operacao)
{
    if(operacao == 1)
    {
        return numero1 * numero2;
    }
    else if(operacao == 2)
    {
        return numero1 / numero2;
    }
    else if(operacao == 3)
    {
        return numero1 + numero2;
    }
    else
    {
        return numero1 - numero2;
    }
}

void caluladoraHP(Pilha *pPilha)
{
    Pilha pilha_reversa = Pilha_Reversa(pPilha);

    Pilha pilha_extra;

    Pilha_Inicia(&pilha_extra);

    Celula *avanca_celula = pilha_reversa.proximo;

    int numero1, numero2, operador, resultado;
    char *string_aux = malloc(sizeof(char));

    while(avanca_celula != NULL)
    {
        if(Verifica_Caracter(avanca_celula) == -1)
        {
            numero1 = Converte_String_To_Int(avanca_celula->item);

            avanca_celula = avanca_celula->proximo;

            if(avanca_celula == NULL) 
            {
                printf("%d\n", numero1);
                Pilha_Libera(&pilha_reversa);
                Pilha_Libera(pPilha);
                break;
            }
            if(Verifica_Caracter(avanca_celula) == -1)
            {
                numero2 = Converte_String_To_Int(avanca_celula->item);
                avanca_celula = avanca_celula->proximo;

                if(avanca_celula == NULL) 
                {
                    printf("%d\n", numero2);
                    Pilha_Libera(&pilha_reversa);
                    Pilha_Libera(pPilha);
                    break;
                }

                operador = Verifica_Caracter(avanca_celula);

                if(operador >= 1 && operador <= 4)
                {
                    resultado = Operacoes(numero1, numero2, operador);

                    Converte_Int_To_String(resultado, string_aux);

                    Pilha_Push(&pilha_extra, string_aux);

                    avanca_celula = avanca_celula->proximo;

                    if(avanca_celula == NULL)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                printf("Entrada inconsistente.\n");

                Pilha_Libera(&pilha_reversa);

                break;
            }
        }
        else
        {
            break;
        }
    }


    Celula *celula_extra = pilha_extra.proximo;

    if(avanca_celula != NULL)
    {
        while(avanca_celula != NULL)
        {
            if(celula_extra != NULL)
            {
                Pilha_Pop(&pilha_extra, &string_aux);
                numero1 = Converte_String_To_Int(string_aux);

                if(Pilha_EhVazia(&pilha_extra))
                {
                    printf("Entrada inconsistente.\n");
                    Pilha_Libera(&pilha_reversa);
                    Pilha_Libera(&pilha_extra);
                    break;
                }

                Pilha_Pop(&pilha_extra, &string_aux);
                numero2 = Converte_String_To_Int(string_aux);
                operador = Verifica_Caracter(avanca_celula);
                resultado = Operacoes(numero1, numero2, operador);

                if(Pilha_EhVazia(&pilha_extra))
                {
                    printf("%d\n", resultado);
                    Pilha_Libera(&pilha_reversa);
                    Pilha_Libera(&pilha_extra);
                    break;
                }

                Converte_Int_To_String(resultado, string_aux);
                Pilha_Push(&pilha_extra, string_aux);
                avanca_celula = avanca_celula->proximo;
            }
            else
            {
                printf("Entrada inconsistente.\n");
                Pilha_Libera(&pilha_reversa);
                Pilha_Libera(&pilha_extra);
                break;
            }
        }
    }

    if(!Pilha_EhVazia(&pilha_extra))
    {
        printf("%s\n", celula_extra->item);
    }


    Imprime_Pilha(&pilha_extra);
    free(string_aux);
    Pilha_Libera(&pilha_extra);
}