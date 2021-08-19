#include "carro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct carro
{
    char modelo[20];
    char cor[20];
    int ano;
    double preco;
    double km;
};

Carro* criarCarro(char *modelo, char *cor, int ano, double preco, double km)
{
    Carro* carro = malloc(sizeof(Carro));
    
    if(carro==NULL){
        printf("Memoria eh insuficiente\n");
        exit(1);
    }

    setModelo(carro, modelo);

    strcpy(carro->cor, cor);
    carro->ano = ano;
    carro->preco = preco;
    carro->km = km;

    return carro;
}

char *getModelo(Carro* carro)
{
    return carro->modelo;
}

char *getCor(Carro* carro)
{
    return carro->cor;
}

int getAno(Carro* carro)
{
    return carro->ano;
}

double getPreco(Carro* carro)
{
    return carro->preco;
}

double getKm(Carro* carro)
{
    return carro->km;
}



void setModelo(Carro *carro, char *modelo)
{
   strcpy(carro->modelo, modelo); 
}

void setCor(Carro *carro, char *cor)
{
   strcpy(carro->cor, cor); 
}

void setAno(Carro *carro, int ano)
{
   carro->ano = ano;
}

void setPreco(Carro *carro, double preco)
{
   carro->preco = preco;
}

void setKM(Carro *carro, double km)
{
   carro->km = km;
}


void deletaCarro(Carro* carro)
{
    free(carro);
}


Carro *buscaCarro(Carro **carro, char *modelo, int qntCarros){
    int i;
    for(i = 0; i < qntCarros; i++) {
        if (strcmp(getModelo(carro[i]), modelo) == 0){
            return carro[i];
        }
    }

    return NULL;
}

void mostrarCarroEspecifico(Carro** carro, char *buscar, int n)
{
    Carro *car = buscaCarro(carro, buscar, n);

    if (car != NULL)
    {
        printf("\nModelo: %s\nCor: %s \nAno: %d\nPreço: %.2lf\nQuilometragem: %.2lf\n", getModelo(car), getCor(car), getAno(car), getPreco(car), getKm(car));
    }
    else
    {
        printf("\nCarro não encontrado!\n");
    } 
}

