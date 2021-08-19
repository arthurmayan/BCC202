#ifndef CARRO_H
#define CARRO_H


typedef struct carro Carro;

Carro* criarCarro(char *modelo, char *cor, int ano, double preco, double km);

char *getModelo(Carro* carro);
char *getCor(Carro* carro);
int getAno(Carro* carro);
double getPreco(Carro* carro);
double getKm(Carro* carro);

void setModelo(Carro *carro, char *modelo);
void setCor(Carro *carro, char *cor);
void setAno(Carro *carro, int ano);
void setPreco(Carro *carro, double preco);
void setKM(Carro *carro, double km);

void deletaCarro(Carro* carro);

Carro *buscaCarro(Carro **carro, char *modelo, int qntCarros);


void mostrarCarroEspecifico(Carro** carro, char *buscar, int n);


#endif
