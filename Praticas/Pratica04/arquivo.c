#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

//Struct que possui os atibutos do arquivo
typedef struct file
{
    char file_name[20];
    char file_type[20];
    float file_size;
}File;

//Gets do Arquivo (ler os atributos do arquivo)
char* getFileName(File *file)
{
    return file->file_name;
}

char* getFileType(File *file)
{
    return file->file_type;
}

float getFileSize(File *file)
{
    return file->file_size;
}

//Sets do Arquivo (atualiza os atributos do arquivo)
void setFileName(File *file, char *file_name)
{
    strcpy(file->file_name, file_name);
}

void setFileType(File *file, char *file_type)
{
    strcpy(file->file_type, file_type);
}

void setFileSize(File *file, float file_size)
{
    file->file_size = file_size;
}

//Funcao responsavel por criar o arquivo (Alocar)
File* createFile(char *file_name, char *file_type, float file_size)
{
    File *aux = (File*) malloc(sizeof(File));

    if(aux == NULL){
        printf("Memoria Insuficiente\n");
        exit(1);
    }

    strcpy(aux->file_name, file_name);
    strcpy(aux->file_type, file_type);
    aux->file_size = file_size;

    return aux;
}

//Funcao responsavel por deletar o Arquivo (Desalocar)
void deleteFile(File **file)
{
    free(*file);
    *file = NULL;
}
