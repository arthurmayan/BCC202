#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circulo
{
    Ponto* centro;
    float raio;
};

Circulo* circ_cria(Ponto* centro, float raio)
{
    Circulo* circ = (Circulo*) malloc(sizeof(Circulo));
    if(circ == NULL)
    {
        printf("MEMORIA INSUFICIENTE");
        exit(1);
    }
    circ->centro = centro;
    circ->raio = raio;

    return circ;
}

Circulo* circ_pto_cria(float x, float y, float raio)
{
    // TEM QUE FAZER
}

void circ_libera(Circulo* circ)
{
    pto_libera (circ->centro);
    free(circ);
}

float circ_area(Circulo* circ)
{
    // A = π . r²
    float resultado;
    resultado = PI * pow(circ->raio,2);
    return resultado;
}

int circ_interior(Circulo* circ, Ponto* pt)
{
    float x = pto_distancia(circ->centro, pt);
    if ( x < (circ->raio))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}