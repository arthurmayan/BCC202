#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>


int getAlunoMatricula(Aluno aluno)
{
    return aluno.matricula;
}

float getAlunoProva(Aluno aluno)
{
    return aluno.prova;
}

float getAlunoTrabalhoPratico(Aluno aluno)
{
    return aluno.trabalho_pratico;
}

float getAlunoNotaFinal(Aluno aluno)
{
    return aluno.nota_final;
}


void setAlunoMatricula(Aluno *aluno, int matricula)
{
    aluno->matricula = matricula;
}

void setAlunoProva(Aluno *aluno, float prova)
{
    aluno->prova = prova;
}

void setAlunoTrabalhoPratico(Aluno *aluno, float trabalho_pratico)
{
    aluno->trabalho_pratico = trabalho_pratico;
}

void setAlunoNotaFinal(Aluno *aluno, float nota_final)
{
    aluno->nota_final = nota_final;
}


Aluno criaAluno(int matricula, float prova, float trabalho_pratico)
{
    Aluno aluno;
    setAlunoMatricula(&aluno, matricula);
    setAlunoProva(&aluno, prova);
    setAlunoTrabalhoPratico(&aluno, trabalho_pratico);
    setAlunoNotaFinal(&aluno, calculaNotaFinal(aluno));
    return aluno;
}


Aluno* criaVetorAluno(int qt_alunos)
{
    int matricula;
    float prova, trabalho_pratico;
    Aluno *aluno  = (Aluno*)  malloc(qt_alunos * sizeof(Aluno));

    if(aluno == NULL)
    {
        printf("Memoria Insuficiente!\n");
        exit(1);
    }

    for(int i = 0; i < qt_alunos; i++)
    {
        scanf("%d %f %f", &matricula, &prova, &trabalho_pratico);
        aluno[i] = criaAluno(matricula, prova, trabalho_pratico);
    }

    return aluno;
}


void deletaAluno(Aluno **aluno)
{
    free(*aluno);
    *aluno = NULL;
}


float calculaNotaFinal(Aluno aluno)
{
    float resultado = (float) ((getAlunoProva(aluno) * 0.7 + getAlunoTrabalhoPratico(aluno) * 0.3) / (0.7 + 0.3));
    return resultado;
}


void insertionSort(Aluno *aluno, int n)
{
    Aluno aux;
    int j;

    for(int i = 1; i < n; i++)
    {
        aux = aluno[i];
        j = i - 1;
        while(j >= 0 && getAlunoNotaFinal(aux) > getAlunoNotaFinal(aluno[j])){
            aluno[j + 1] = aluno[j];
            j--;
        }
        aluno[j + 1] = aux;
    }
}


void imprimeAluno(Aluno *aluno, int n)
{
	printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d %.1f\n", getAlunoMatricula(aluno[i]), getAlunoNotaFinal(aluno[i]));
    }
}
