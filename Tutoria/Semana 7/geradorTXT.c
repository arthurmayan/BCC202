#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n, numero;
    srand(time(NULL));
    FILE *arquivo = fopen("dados.txt", "w+");
    
    printf("Digite a quantidade de valores a serem inseridos no txt: ");
    
    scanf("%d", &n);
    
    fprintf(arquivo, "%d\n", n);
    
    for(int i = 0; i < n; i++)
    {
        numero = rand() % 100000 + 1;
        fprintf(arquivo, "%d\n", numero);
    }
    
    fclose(arquivo);
    return 0;
}
