#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "diretorio.h"

//Structs que possui os atribudos do diretorio
typedef struct folder
{
    char folder_name[20];
    char folder_path[20];
    float folder_size;
    int folder_file_length;
    File **setof_files;
} Folder;

//Gets do Diretorio (ler os atributos do diretorio)
char* getFolderName(Folder *folder)
{
    return folder->folder_name;
}

char* getFolderPath(Folder *folder)
{
    return folder->folder_path;
}

float getFolderSize(Folder *folder)
{
    return folder->folder_size;
}

int getFolderFileLength(Folder *folder)
{
    return folder->folder_file_length;
}

File **getFolderSetOfFile(Folder *folder)
{
    return folder->setof_files;
}

//Sets do Diretorio (atualiza os atributos do diretorio)
void setFolderName(Folder *folder, char *folder_name)
{
    strcpy(folder->folder_name, folder_name);
}

void setFolderPath(Folder *folder, char *folder_path)
{
    strcpy(folder->folder_path, folder_path);
}

void setFolderSize(Folder *folder, float folder_size)
{
    folder->folder_size = folder_size;
}

void setFolderSetOfFiles(Folder *folder, File **setof_files)
{
    folder->setof_files = setof_files;
}

void setFolderFileLength(Folder *folder, int folder_file_length)
{
    folder->folder_file_length = folder_file_length;
}

//Funcao Responsavel por retornar um vetor de Arquivos devidamente alocados
File **createFilePassByAdress(int file_length)
{
    File **file = malloc(file_length * sizeof(File*));

    for(int i = 0; i < file_length; i++){
        file[i] = NULL;
    }

    return file;
}

//Funcao responsavel por retornar um Diretorio devidamente alocado
Folder* createFolder(char *folder_name, int folder_file_length)
{
    Folder *aux = (Folder*) malloc(sizeof(Folder));

    if(aux == NULL)
    {
        printf("Memoria Insuficiente\n");
        exit(1);
    }

    strcpy(aux->folder_name, folder_name);
    aux->folder_file_length = folder_file_length;

    aux->setof_files = createFilePassByAdress(folder_file_length);

    return aux;
}

//Funcao responsavel por ler todos os arquivos do Diretorio
void listFolderFile(Folder *folder)
{
    for(int i = 0; i < folder->folder_file_length; i++)
    {
        if(folder->setof_files[i] != NULL)
        {
            printf("%s\n", getFileName(folder->setof_files[i]));
        }
    }
}

//Funcao responsavel por adicionar um(varios) arquivo(os) ao Diretorio
void addFileFolder(Folder *folder)
{
    static int count_file = 0;
    static int i = 0;
    int n_file;

    char file_name[20];
    char file_type[20];
    float file_size;

    scanf("%d", &n_file);
    fflush(stdin);
    count_file = count_file + n_file;

    if(count_file <= folder->folder_file_length){
        for(; i < count_file; i++){
            scanf("%s %s %f", file_name, file_type, &file_size);
            folder->setof_files[i] = createFile(file_name, file_type, file_size);
            fflush(stdin);
        }
    }
}

//Funcao resposavel por remover um arquivo do Diretorio, e retornar 1 caso sucesso
int removeFileFolder(Folder *folder)
{
    char file_name_aux1[20];

    scanf("%s", file_name_aux1);
    fflush(stdin);
    for(int i = 0; i < folder->folder_file_length; i++)
    {
        if(strcmp(getFileName(folder->setof_files[i]), file_name_aux1) == 0){
            deleteFile(&folder->setof_files[i]);
            return 1;
        }
    }

    return -1;

}

//Funcao responsavel por renomerar o diretorio
void renameFolder(Folder *folder)
{
    char file_name_aux[20];

    scanf("%s", file_name_aux);
    fflush(stdin);

    setFolderName(folder, file_name_aux);
}

//Funcao responsavel por renomear um arquivo do Diretorio
int renameFileFolder(Folder *folder)
{
    char file_name_aux[20];
    char file_name_aux1[20];

    scanf("%s %s", file_name_aux, file_name_aux1);
    fflush(stdin);
    for(int i = 0; i < folder->folder_file_length; i++)
    {
        if(strcmp(getFileName(folder->setof_files[i]), file_name_aux) == 0){
            strcpy(getFileName(folder->setof_files[i]), file_name_aux1);
            return 1;
        }
    }

    return 0;
}

//Funcao responsavel por retornar a soma do tamanho de todos os arquivos do Diretorio
float folderSize(Folder *folder)
{

    float folder_size = 0;

    for(int i = 0; i < folder->folder_file_length; i++){
        if(folder->setof_files[i] != NULL){
            folder_size += getFileSize(folder->setof_files[i]);
        }
    }

    return folder_size;
}


//Funcao responsavel por retornar a soma do tamanho de todos os arquivos do Diretorio
void deleFilesAndFolder(Folder *folder)
{
    for(int i = 0; i < folder->folder_file_length; i++)
    {
        free(folder->setof_files[i]);
    }

    deleteFile(folder->setof_files);

    deletefolder(&folder);
}

//Funcao responsavel por retornar a soma do tamanho de todos os arquivos do Diretorio
void deletefolder(Folder **folder)
{
    free(*folder);
    *folder = NULL;
}
