#include <stdio.h>
#include "ponto.h"

int main()
{
    float x1, y1;
    float x2, y2;

    scanf("%f %f", &x1, &y1);
    
    Ponto* p1 = pto_cria(2.0,4.0);
    
    pto_imprime(p1);
    
    pto_acessa(p1, &x1, &y1);
    
    printf("%.1f %.1f\n", x1, y1);

    scanf("%f %f", &x1, &y1);

    scanf("%f %f", &x2, &y2);

    pto_atribui(p1, x1, y1);

    pto_imprime(p1);

    Ponto* p2 = pto_cria(x2, y2);

    pto_imprime(p2);

    pto_acessa(p2, &x2, &y2);

    printf("A distancia entre P1(%.1f, %.1f) e P2(%.1f, %.1f) = %.1f\n", x1, y1, x2, y2, pto_distancia(p1, p2));

    pto_libera(p1);
    pto_libera(p2);
    
    return 0;
}

