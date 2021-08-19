#include "ponto.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct ponto
{
    float x, y;
};

Ponto* pto_cria(float x, float y)
{
    Ponto* aux = (Ponto*) malloc(sizeof(Ponto));
    
    if(aux==NULL){
        printf("Memoria eh insuficiente\n");
        exit(1);
    }

    aux->x= x;
    aux->y = y;

    return aux;
}

void pto_imprime(Ponto* p1)
{
    printf("Ponto 1: (X = %.1f, y = %.1f)\n", p1->x, p1->y);
}

void pto_libera(Ponto* p)
{
    free(p);
}

void pto_acessa(Ponto* p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}

void pto_atribui(Ponto* p, float x, float y)
{
    p->x = x;
    p->y = y;
}

float pto_distancia(Ponto* p1, Ponto *p2)
{
    float n1 = pow((p2->x - p1->x), 2);
    float n2 = pow((p2->y - p1->y), 2);
    float n3 = n1 + n2;
    float resultado = sqrt(n3);

    return resultado;
    
}

