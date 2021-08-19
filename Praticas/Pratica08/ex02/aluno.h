typedef struct Aluno
{
    int matricula;
    float prova;
    float trabalho_pratico;
    float nota_final;
} Aluno;


int getAlunoMatricula(Aluno aluno);
float getAlunoProva(Aluno aluno);
float getAlunoTrabalhoPratico(Aluno aluno);
float getAlunoNotaFinal(Aluno aluno);

void setAlunoMatricula(Aluno *aluno, int matricula);
void setAlunoProva(Aluno *aluno, float prova);
void setAlunoTrabalhoPratico(Aluno *aluno, float trabalho_pratico);
void setAlunoNotaFinal(Aluno *aluno, float nota_final);

Aluno criaAluno(int matricula, float prova, float trabalho_pratico);

void deletaAluno(Aluno **aluno);

float calculaNotaFinal(Aluno aluno);

void insertionSort(Aluno *aluno, int n);

void imprimeAluno(Aluno *aluno, int n);

Aluno* criaVetorAluno(int qt_alunos);

void mergeSort(Aluno *aluno, int inicioVetorEsquerda, int finalVetorDireita);

void merge(Aluno *aluno, int inicioVetorEsquerda, int meioVetor, int finalVetorDireita);
