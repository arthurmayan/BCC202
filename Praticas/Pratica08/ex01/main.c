#include <stdio.h>
#include "aluno.h"

int main() {
    int n, qt_alunos;
    Aluno *aluno = NULL;
    scanf("%d", &n);
    printf("\n");
    
    do{
        scanf("%d", &qt_alunos);
        
        aluno = criaVetorAluno(qt_alunos);
        
        insertionSort(aluno, qt_alunos);
        
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
