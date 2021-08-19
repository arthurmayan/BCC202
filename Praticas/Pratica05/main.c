// Arthur Mayan Faria de Almeida - 18.2.4149

#include <stdio.h>
#include "rec.h"

int main() 
{
    int opcode = 0;

    do 
    {
        scanf("%d", &opcode);
        switch (opcode)
        {
            case 1:
            {
            //********************* EX01 ***********************************
                
                int num;
                int parada = -1;
                int quantidade;

                while (parada == -1 )
                {
                    quantidade = 0;
                    scanf("%d", &num);
                    printf("%d", fibonacci(num, &quantidade));
                    printf(" %d\n", quantidade);
                    scanf("%d", &parada);

                }
                printf("\n");
                break;
            }
            case 2:
            {
            // ********************* EX02 ***********************************

                int qnt_elementos;
                scanf("%d", &qnt_elementos);
                int vetor[50];

                for (int i = 0; i < qnt_elementos; i++)
                {
                    scanf("%d", &vetor[i]);
                }

                reverso(qnt_elementos, vetor);
                printf("\n\n");
                break;

            }

            case 3:
            {
            // ********************* EX03 ***********************************
                long long int n9;
                int grau = 0;
                int parar = -1;
                int auxx;

                while (parar == -1)
                {
                    scanf("%lld", &n9);
                    //printf("%d",multiplo(n9, &grau));
                    auxx = multiplo(n9, &grau);
                    printf("%d\n", auxx);


                    scanf("%d", &parar);
                }
                printf("\n");
                break;
            }

            case 4:
            {
            // ********************* EX04 ***********************************

                int n;
                int vetor2[30];
                int k;
                int sair = -1;


                while (sair == -1)
                {
                    scanf("%d", &n);
                    for (int j = 0; j < n; j++)
                    {
                        scanf("%d", &vetor2[j]);
                    }
                    
                    scanf("%d", &k);

                    printf("%d\n", pesquisaBinaria(vetor2, k, 0, n-1));
                    scanf("%d", &sair);
                }
                printf("\n");
                break;
            }

        }
    }while(opcode != -100);

    return 0; 
}