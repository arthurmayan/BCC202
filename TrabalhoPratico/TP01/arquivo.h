// Arthur Mayan - 18.2.4149

// ********************************* EX 01 ********************************

typedef struct matriz Matriz;

void jogoDaVelha(int linha, int coluna);

void rodadas(int vezes, int *ptsUsuario, int *ptsComputador, int *qntRodadas);


Matriz *criarMatriz(int linha, int coluna);
void alocarMatriz(int ***aux, int linha, int coluna);

void printarMatriz(Matriz *matriz);
void exibeTabuleiro(Matriz *matriz);
void zeraTabuleiro(Matriz *matriz);

void escolhaUsuario(Matriz *matriz, int linha, int coluna);
void escolhaComputador(Matriz *matriz, int linha, int coluna);

void verificaComputador(Matriz *matriz);


int verificaGanhador(Matriz *matriz);
int verificaLinha(Matriz *matriz);
int verificaColuna(Matriz *matriz);
int verificaDiagonal(Matriz *matriz);

int verificaEmpate(Matriz *matriz);

void desacolaMatriz(int ***matriz, int linha);
void deletarMatrizStruct(Matriz **m);



// ********************************* EX 02 ********************************

typedef struct placar Placar;

Placar *criarPlacar();

int getPontos_Usuario(Placar *placar);
int getPontos_computador(Placar *placar);
int getEmpates(Placar *placar);
int getRodadas(Placar *placar);
int getEscolha_usuario(Placar *placar);
int getEscolha_computador(Placar *placar);

void setPontos_Usuario(Placar *placar, int pontos_Usuarios);
void setPontos_computador(Placar *placar, int pontos_computador);
void setEmpates(Placar *placar, int empates);
void setRodadas(Placar *placar, int rodadas);
void setEscolha_usuario(Placar *placar, int escolha_usuario);
void setEscolha_computador(Placar *placar, int escolha_computador);

void deletePlacar(Placar **placar);

int sortear(int max);

void jokempo(Placar *placar);
void verificaVencedor(Placar *placar);
void escolhas(Placar *placar);
void placarAtualizado(Placar *placar);

// ********************************* EX 03 ********************************

void ler(char *vetor, int tamanho, int incremento);
int criptografia(int n);
void maiusculo_minusculo(char **vetor, int tamanho);
void vetor_inverso(char **vetor, char *vetor_aux, int tamanho, int incremento);
void mudar_caracter(char **vetor, int tamanho, int incremento);
void copiar_vetor(char **vetor_final, char *vectorSource, int incremento);








