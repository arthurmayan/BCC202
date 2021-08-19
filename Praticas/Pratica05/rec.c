// Arthur Mayan Faria de Almeida - 18.2.4149

#include <stdio.h>
#include "rec.h"

int fibonacci(int n, int *quantidade) 
{
    if (n==0) 
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else 
    {
        *quantidade = *quantidade + 2;
        return fibonacci(n-1, quantidade)+ fibonacci(n-2, quantidade);
    }
}

void reverso(int qnt, int vetor[])
{
    qnt = qnt - 1;
    if (qnt >= 0)
    {
        printf("%d ", vetor[qnt]);
        reverso(qnt, vetor);
    }
}

int multiplo(long long int n9, int *grau)
{
    if (n9 == 9)
    {
        *grau = *grau +1;
        return *grau;
    }
    else if (n9 < 9)
    {
        return 0;
    }
    else
    {
        *grau+=1;
        long long int aux = digitos(n9, grau);
        *grau = multiplo(aux, grau);
    }
}

long long int digitos(long long int n9, int *grau)
{
    long long int resto = 0;
    long long int total = 0;

    while (n9 != 0)
    {
        resto = n9 % 10;
        n9 = n9 / 10;
        total = total + resto;
    }

    if (total == 9 && *grau != 1)
    {
        *grau-=1;
    }

    return total;
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