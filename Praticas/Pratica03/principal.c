#include <stdio.h>
#include "ponto.h"
#include "circulo.h"


int main()
{
    Ponto* p1 = pto_cria(8.0,15.0); // aloca dinamic.
    Ponto* p2 = pto_cria(8.0, 16.0);

    Circulo* circ = circ_cria(p2, 4.9);

    printf ("Area do Circulo: %.2f\n", circ_area(circ));

    if(circ_interior(circ,p1) == 1 )
    {
        printf ("P1 está dentro do Circulo\n") ;
    }
    else
    {
        printf ("P1 não está dentro do Circulo\n") ;
    }
    
    // chamar função para liberar memoria de circulo.
    pto_libera (p1);
    circ_libera (circ);
    return 0;
}