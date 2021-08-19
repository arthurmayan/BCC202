// Arthur Mayan Faria de Almeida - 18.2.4149

#include <stdio.h>
#include "rec.h"

int fatorialRecursiva(int x)
{
    if(x <= 1)
    {
         return 1;  
    } 

    return fatorialRecursiva(x - 1) * x;
}

int divisaoRecursiva(int dividendo, int divisor, int *resto)
{
    if (dividendo - divisor < 0 ) //caso base
    {
        *resto = dividendo;
        return 0;
    }
    else
    {
        return divisaoRecursiva(dividendo - divisor, divisor, resto) +1;
    }
    
}

int pesquisaBinaria(int *v, int chave, int esq, int dir)
{
    int meio = (esq + dir) / 2;

    if (esq > dir)
    {
        return -1;
    }

    if (v[meio] == chave)
    {
        return meio;
    }

    if (v[meio] > chave) // chave menor
    {
        return pesquisaBinaria(v, chave, esq, meio -1);
    }
    if (v[meio] < chave) // chave maior
    {
        return pesquisaBinaria(v, chave, meio +1, dir);
    }
}