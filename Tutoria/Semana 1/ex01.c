// Arthur Mayan
// 18.2.4149

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nome[20];
    float nota1, nota2, nota3;
    int falta;
    char conceito;
}Aluno;


int main ()
{
    int n, i;
    double media;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &n);

    Aluno* dados = malloc(n * sizeof(Aluno));

    if (dados==NULL)
    {
        printf("Nao tem memoria");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nInforme a matricula do aluno(%d): ", i+1);
        scanf("%d", &dados[i].matricula);

        printf("\nInforme o nome do aluno(%d): ",i+1);
        scanf("%s", dados[i].nome);

        printf("\nInforme a nota da prova 01 do aluno(%d): ",i+1);
        scanf("%f", &dados[i].nota1);

        printf("\nInforme a nota da prova 02 do aluno(%d): ",i+1);
        scanf("%f", &dados[i].nota2);

        printf("\nInforme a nota da prova 03 do aluno(%d): ",i+1);
        scanf("%f", &dados[i].nota3);

        printf("\nInforme a quantidade de faltas do aluno(%d): \n",i+1);
        scanf("%d", &dados[i].falta);
    }

    for (i = 0; i < n; i++)
    {
       media = (dados[i].nota1 +  dados[i].nota2 +  dados[i].nota3) / 3;

       if (dados[i].falta > 18)
       {
           dados[i].conceito = 'F';
       }
       else if (media < 6)
       {
           dados[i].conceito = 'R';
       }
       else if (media < 7.5)
       {
           dados[i].conceito = 'C';
       }
       else if (media < 9)
       {
           dados[i].conceito = 'B';
       }
       else if (media < 10)
       {
           dados[i].conceito = 'A';
       }

       printf("Nome: %s, Conceito: %c \n", dados[i].nome, dados[i].conceito);
    }

    free(dados);
}

