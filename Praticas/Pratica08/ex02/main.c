#include <stdio.h>
#include "aluno.h"

int main()
{
    int n, qt_alunos;
    Aluno *aluno = NULL;
    scanf("%d", &n);
    printf("\n");
    
    do
    {
        scanf("%d", &qt_alunos);
        
        aluno = criaVetorAluno(qt_alunos);
        
        mergeSort(aluno, 0, qt_alunos - 1);
        
        imprimeAluno(aluno, qt_alunos);
        
        deletaAluno(&aluno);
        
        if(n >= 2)
        {
            printf("\n");
        }
        n--;
    }while(n > 0);
    
    return 0;
}
