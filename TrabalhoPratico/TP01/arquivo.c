// Arthur Mayan - 18.2.4149

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arquivo.h"

// ********************************* EX 01 ********************************

typedef struct matriz
{
    int **matriz;
    int linha;
    int coluna;
    int ptsUsuario;
    int ptsComputador;
} Matriz;

void jogoDaVelha(int linha, int coluna)
{
    char contin[1];
    strcmp(contin, "c");
    int vezes = 3;

    int ptsUsuario;
    int ptsComputador;
    int qntRodadas;
    
    rodadas(vezes, &ptsUsuario, &ptsComputador, &qntRodadas);

    printf("PLACAR USUARIO: %d \n", ptsUsuario);
    printf("PLACAR COMPUTADOR: %d\n", ptsComputador);

    printf("DESEJA JOGAR NOVAMENTE?\nc - CONTINUAR\np - PARAR O JOGO\n");
    scanf("%s", contin);

    fflush(stdin);

    if (strcmp(contin, "c") == 0)
    {
        do{
        rodadas(2, &ptsUsuario, &ptsComputador, &qntRodadas);
        printf("\nPLACAR USUARIO: %d \n", ptsUsuario);
        printf("PLACAR COMPUTADOR: %d \n\n", ptsComputador);
        
        printf("DESEJA JOGAR NOVAMENTE?\nc - CONTINUAR\np - PARAR O JOGO\n");
        scanf("%s", contin);
        fflush(stdin);
        }while (strcmp(contin, "p") != 0);
    }
    
}

void rodadas(int vezes, int *ptsUsuario, int *ptsComputador, int *qntRodadas)
{
    for (int i = 0; i < vezes; i++)
    {
        int linha = 3;
        int coluna = 3;
        printf("\n\nUSUARIO: X\nCOMPUTADOR: O\n\n");
        Matriz *matriz = criarMatriz(linha, coluna);

        zeraTabuleiro(matriz);
        exibeTabuleiro(matriz);

        for (int i = 0; i < 3; i++)
        {
            printf("\nESCOLHA UMA LINHA E UMA COLUNA: ");
            scanf("%d %d", &linha, &coluna);

            escolhaUsuario(matriz, linha, coluna);
            exibeTabuleiro(matriz);

            verificaComputador(matriz);

            exibeTabuleiro(matriz);
        }

        int aux = verificaGanhador(matriz);

        if (aux == 1)
        {
            printf("\nESCOLHA UMA LINHA E UMA COLUNA: ");
            scanf("%d %d", &linha, &coluna);

            escolhaUsuario(matriz, linha, coluna);
            verificaComputador(matriz);

            exibeTabuleiro(matriz);
            aux = verificaGanhador(matriz);
        }

        if (aux == 1)
        {
            printf("\nUSUARIO, ESCOLHA UMA LINHA E UMA COLUNA: ");
            scanf("%d %d", &linha, &coluna);

            escolhaUsuario(matriz, linha, coluna);
            exibeTabuleiro(matriz);

            verificaEmpate(matriz);
        }
        *ptsUsuario = matriz->ptsUsuario;
        *ptsComputador = matriz->ptsComputador;
    
        deletarMatrizStruct(&matriz);
    }
}

Matriz *criarMatriz(int linha, int coluna)
{
    Matriz *aux = malloc(sizeof(Matriz));
    alocarMatriz(&aux->matriz, linha, coluna);
    aux->linha = linha;
    aux->coluna = coluna;
    aux->ptsComputador = 0;
    aux->ptsUsuario = 0;
    return aux;
}

void alocarMatriz(int ***aux, int linha, int coluna)
{
    *aux = malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++)
        (*aux)[i] = calloc(coluna, sizeof(int));
}

void printarMatriz(Matriz *matriz)
{
    for (int i = 0; i < matriz->linha; i++)
    {
        for (int j = 0; j < matriz->coluna; ++j)
        {
            printf("%d ", matriz->matriz[i][j]);
        }
        printf("\n");
    }
}

void exibeTabuleiro(Matriz *matriz)
{
    int linha, coluna;
    putchar('\n');

    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            if ((*matriz).matriz[linha][coluna] == 0)
            {
                printf("    ");
            }
            else if ((*matriz).matriz[linha][coluna] == 1)
            {
                printf("  X ");
            }
            else
            {
                printf("  O ");
            }

            if (coluna != (3 - 1))
            {
                printf("|");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

void zeraTabuleiro(Matriz *matriz)
{
    int linha, coluna;
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 3; coluna++)
        {
            (*matriz).matriz[linha][coluna] = 0;
        }
    }
}

void escolhaUsuario(Matriz *matriz, int linha, int coluna)
{
    (*matriz).matriz[linha][coluna] = 1;
}

void escolhaComputador(Matriz *matriz, int linha, int coluna)
{
    (*matriz).matriz[linha][coluna] = 2;
    printf("COMPUTADOR ESCOLHEU: %d %d\n", linha, coluna);
}

void verificaComputador(Matriz *matriz)
{
    int linha = rand() % 3;
    int coluna = rand() % 3;

    int verifica = 0;

    while (verifica == 0)
    {
        if (((*matriz).matriz[linha][coluna] != 1) && ((*matriz).matriz[linha][coluna] != 2))
        {
            escolhaComputador(matriz, linha, coluna);
            verifica = 1;
        }
        else
        {
            linha = rand() % 3;
            coluna = rand() % 3;
        }
    }
}

int verificaGanhador(Matriz *matriz)
{
    int aux1 = verificaLinha(matriz);
    int aux2 = verificaColuna(matriz);
    int aux3 = verificaDiagonal(matriz);

    if (aux1 == 1 && aux2 == 1 && aux3 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificaLinha(Matriz *matriz)
{
    // linha 01
    
    if (((*matriz).matriz[0][0] == 1) && ((*matriz).matriz[0][1] == 1) && ((*matriz).matriz[0][2] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;
        return 0;
    }

    else if (((*matriz).matriz[0][0] == 2) && ((*matriz).matriz[0][1] == 2) && ((*matriz).matriz[0][2] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;
        return 0;
    }

    // linha 02

    else if (((*matriz).matriz[1][0] == 1) && ((*matriz).matriz[1][1] == 1) && ((*matriz).matriz[1][2] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[1][0] == 2) && ((*matriz).matriz[1][1] == 2) && ((*matriz).matriz[1][2] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;

        return 0;
    }

    // linha 03

    else if (((*matriz).matriz[2][0] == 1) && ((*matriz).matriz[2][1] == 1) && ((*matriz).matriz[2][2] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[2][0] == 2) && ((*matriz).matriz[2][1] == 2) && ((*matriz).matriz[2][2] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;

        return 0;
    }
    else
    {
        return 1;
    }
}

int verificaColuna(Matriz *matriz)
{
    // coluna 01

    if (((*matriz).matriz[0][0] == 1) && ((*matriz).matriz[1][0] == 1) && ((*matriz).matriz[2][0] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[0][0] == 2) && ((*matriz).matriz[1][0] == 2) && ((*matriz).matriz[2][0] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;
        return 0;
    }

    // coluna 02

    else if (((*matriz).matriz[0][1] == 1) && ((*matriz).matriz[1][1] == 1) && ((*matriz).matriz[2][1] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[0][1] == 2) && ((*matriz).matriz[1][1] == 2) && ((*matriz).matriz[2][1] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;

        return 0;
    }

    // linha 03

    else if (((*matriz).matriz[0][2] == 1) && ((*matriz).matriz[1][2] == 1) && ((*matriz).matriz[2][2] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[0][2] == 2) && ((*matriz).matriz[1][2] == 2) && ((*matriz).matriz[2][2] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;

        return 0;
    }
    else
    {
        return 1;
    }
}

int verificaDiagonal(Matriz *matriz)
{
    // diagonal 01

    if (((*matriz).matriz[0][0] == 1) && ((*matriz).matriz[1][1] == 1) && ((*matriz).matriz[2][2] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[0][0] == 2) && ((*matriz).matriz[1][1] == 2) && ((*matriz).matriz[2][2] == 2))
    {
        printf("COMPUTADOR GANHOU!\n");
        matriz->ptsComputador =  matriz->ptsComputador +1;

        return 0;
    }

    // diagonal 02

    else if (((*matriz).matriz[0][2] == 1) && ((*matriz).matriz[1][1] == 1) && ((*matriz).matriz[2][0] == 1))
    {
        printf("VOCÊ GANHOU!\n");
        matriz->ptsUsuario =  matriz->ptsUsuario +1;

        return 0;
    }

    else if (((*matriz).matriz[0][2] == 2) && ((*matriz).matriz[1][1] == 2) && ((*matriz).matriz[2][0] == 2))
    {
        printf("COMPUTADOR GANHOU! 16");
        matriz->ptsComputador =  matriz->ptsComputador +1;

        return 0;
    }
    else
    {
        return 1;
    }
}

int verificaEmpate(Matriz *matriz)
{
    int aux = verificaGanhador(matriz);
    if (aux == 1)
    {
        printf("EMPATE!!");
    }
}

void desacolaMatriz(int ***matriz, int linha)
{
    for (int i = 0; i < linha; ++i)
    {
        free((*matriz)[i]);
    }
    free(*matriz);
    *matriz = NULL;
}

void deletarMatrizStruct(Matriz **m)
{
    desacolaMatriz(&(*m)->matriz, (*m)->linha);
    free(*m);
    m = NULL;
}

// ********************************* EX 02 ********************************

// 0 - pedra,
// 1 - papel
// 2 - tesoura.

typedef struct placar
{
    int pontos_usuario;
    int pontos_computador;
    int empates;
    int rodadas;
    int escolha_usuario;
    int escolha_computador;
} Placar;

Placar *criarPlacar()
{
    Placar *aux = malloc(sizeof(Placar));

    aux->pontos_usuario = 0;
    aux->pontos_computador = 0;
    aux->empates = 0;
    aux->rodadas = 0;
    aux->escolha_usuario = 0;
    aux->escolha_computador = 0;

    return aux;
}

int getPontos_Usuario(Placar *placar)
{
    return placar->pontos_usuario;
}

int getPontos_computador(Placar *placar)
{
    return placar->pontos_computador;
}

int getEmpates(Placar *placar)
{
    return placar->empates;
}

int getRodadas(Placar *placar)
{
    return placar->rodadas;
}

int getEscolha_usuario(Placar *placar)
{
    return placar->escolha_usuario;
}

int getEscolha_computador(Placar *placar)
{
    return placar->escolha_computador;
}

void setPontos_Usuario(Placar *placar, int pontos_Usuarios)
{
    placar->pontos_usuario += pontos_Usuarios;
}

void setPontos_computador(Placar *placar, int pontos_computador)
{
    placar->pontos_computador += pontos_computador;
}

void setEmpates(Placar *placar, int empates)
{
    placar->empates += empates;
}

void setRodadas(Placar *placar, int rodadas)
{
    placar->rodadas += rodadas;
}

void setEscolha_usuario(Placar *placar, int escolha_usuario)
{
    placar->escolha_usuario = escolha_usuario;
}

void setEscolha_computador(Placar *placar, int escolha_computador)
{
    placar->escolha_computador = escolha_computador;
}

void deletePlacar(Placar **placar)
{
    free(*placar);
    *placar = NULL;
}

int sortear(int max)
{
    srand(time(NULL));
    return rand() % max;
}

void jokempo(Placar *placar)
{
    while (placar->rodadas < 5)
    {
        setRodadas(placar, 1);
        escolhas(placar);
        verificaVencedor(placar);
    }
    placarAtualizado(placar);

    char continuacao[1];

    printf("VOCÊ DESEJA CONTINUAR?\n\n");
    printf("DIGITE \n\nc - PARA CONTINUAR\np - PARA ENCERRAR O JOGO.\n\n");

    scanf("%s", continuacao);

    while (strcmp(continuacao, "c") == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            setRodadas(placar, 1);
            escolhas(placar);
            verificaVencedor(placar);
        }

        placarAtualizado(placar);
        printf("VOCÊ DESEJA CONTINUAR?\n\n");
        printf("DIGITE \n\nc - PARA CONTINUAR\np - PARA ENCERRAR O JOGO.\n\n");

        scanf("%s", continuacao);
    }

    deletePlacar(&placar);
}

// 0 ganha 2
// 1 ganha 0
// 2 ganha 1

void verificaVencedor(Placar *placar)
{
    printf("\nCOMPUTADOR ESCOLHEU: %d\n\n", placar->escolha_computador);

    if (placar->escolha_computador == placar->escolha_usuario)
    {
        setEmpates(placar, 1);
        printf("EMPATE!\n");

    }
    else if ((placar->escolha_computador == 0) && (placar->escolha_usuario == 2))
    {
        setPontos_computador(placar, 1);
        printf("COMPUTADOR GANHOU!\n");

    }
    else if ((placar->escolha_computador == 2) && (placar->escolha_usuario == 0))
    {
        setPontos_Usuario(placar, 1);
        printf("VOCÊ GANHOU!!\n");

    }
    else if ((placar->escolha_computador == 1) && (placar->escolha_usuario == 0))
    {
        setPontos_computador(placar, 1);
        printf("COMPUTADOR GANHOU!\n");

    }
    else if ((placar->escolha_computador == 0) && (placar->escolha_usuario == 1))
    {
        setPontos_Usuario(placar, 1);
        printf("VOCÊ GANHOU!!\n");

    }
    else if ((placar->escolha_computador == 2) && (placar->escolha_usuario == 1))
    {
        setPontos_computador(placar, 1);
        printf("COMPUTADOR GANHOU!\n");

    }
    else if ((placar->escolha_computador == 1) && (placar->escolha_usuario == 2))
    {
        setPontos_Usuario(placar, 1);
        printf("VOCÊ GANHOU!!\n");

    }
}

void escolhas(Placar *placar)
{
    printf("\n---- RODADA %d ----\n", getRodadas(placar));
    printf("\nQUAL SUA ESCOLHA?\n\n0 - PEDRA\n1 - PAPEL\n2 - TESOURA\n\n");
    int aux_escolha_usuario;
    scanf("%d", &aux_escolha_usuario);
    setEscolha_usuario(placar, aux_escolha_usuario);
    setEscolha_computador(placar, sortear(3));
}

void placarAtualizado(Placar *placar)
{
    printf("\n\n#### PLACAR ATUALIZADO ####\n\n");
    printf("TOTAL DE RODADAS: %d\n", getRodadas(placar));
    printf("PONTOS DO USUARIO: %d\n", getPontos_Usuario(placar));
    printf("PONTOS DO COMPUTADOR: %d\n", getPontos_computador(placar));
    printf("TOTAL DE EMPATES: %d\n", getEmpates(placar));

    if ((placar->pontos_computador) > (placar->pontos_usuario))
    {
        printf("\nO GANHADOR DAS %d RODADAS FOI O COMPUTADOR!\n\n", getRodadas(placar));
    }
    else if ((placar->pontos_computador) < (placar->pontos_usuario))
    {
        printf("\nO GANHADOR DAS %d RODADAS FOI VOCÊ!!\n\n", getRodadas(placar));
    }
    else
    {
        printf("\nEMPATE!!\n\n");
    }

    printf("----------------------------\n\n");
}



// ********************************* EX 03 ********************************

int criptografia(int n)
{
    char vetor[103];
    int tamanho;
    char *vetor1;
    char *vetor2;
    fflush(stdin);

    if (n < 0)
    {
        return 0;
    }
    fgets(vetor, 103, stdin);
    fflush(stdin);
    tamanho = strlen(vetor);

    vetor1 = malloc(tamanho * sizeof(char));
    vetor2 = malloc(tamanho * sizeof(char));

    copiar_vetor(&vetor1, vetor, 0);
    maiusculo_minusculo(&vetor1, tamanho);
    copiar_vetor(&vetor2, vetor1, 0);
    vetor_inverso(&vetor1, vetor2, tamanho, 0);
    mudar_caracter(&vetor1, tamanho, 0);
    ler(vetor1, tamanho, 0);
    printf("\n");

    free(vetor1);
    free(vetor2);
    return criptografia(n - 1);
}

void ler(char *vetor, int tamanho, int incremento)
{
    if (incremento < tamanho)
    {
        printf("%c", vetor[incremento]);
        ler(vetor, tamanho, incremento + 1);
    }
}

void copiar_vetor(char **vetor_final, char *vetor_inicial, int incremento)
{
    int tamanho = strlen(vetor_inicial);

    if (incremento < tamanho)
    {
        (*vetor_final)[incremento] = vetor_inicial[incremento];
        copiar_vetor(vetor_final, vetor_inicial, incremento + 1);
    }
}

void maiusculo_minusculo(char **vetor, int tamanho)
{
    tamanho = tamanho - 1;

    if (tamanho >= 0)
    {
        if (((*vetor)[tamanho] >= 65 && (*vetor)[tamanho] <= 90) || ((*vetor)[tamanho] >= 97 && (*vetor)[tamanho] <= 132))
            (*vetor)[tamanho] += 3;
        maiusculo_minusculo(vetor, tamanho);
    }
}

void vetor_inverso(char **vetor, char *vetor_aux, int tamanho, int incremento)
{
    tamanho = tamanho - 1;
    if (tamanho >= 0)
    {
        (*vetor)[incremento] = vetor_aux[tamanho];
        vetor_inverso(vetor, vetor_aux, tamanho, incremento + 1);
    }
}

void mudar_caracter(char **vetor, int tamanho, int incremento)
{
    int meio;

    if (tamanho % 2 != 0)
        meio = (tamanho / 2) + 1;
    else
        meio = tamanho / 2;

    if (incremento < tamanho)
    {
        if (incremento >= meio)
        {
            (*vetor)[incremento] -= 1;
        }
        mudar_caracter(vetor, tamanho, incremento + 1);
    }
}
