 #include "arquivo.h"
    //Structs que possui os atribudos do diretorio
    typedef struct folder Folder;

    //************************* CRIANDO O CRUD *************************
    //Funcao responsavel por criar o Diretorio (Alocar)
    Folder* createFolder(char *folder_name, int folder_file_length);
    File **createFilePassByAdress(int file_length);

    //Gets do Diretorio (ler os atributos do diretorio)
    char* getFolderName(Folder *folder);
    char* getFolderPath(Folder *folder);
    float getFolderSize(Folder *folder);
    int getFolderFileLength(Folder *folder);
    File **getFolderSetOfFile(Folder *folder);

    //Sets do Diretorio (atualiza os atributos do diretorio)
    void setFolderName(Folder *folder, char *folder_name);
    void setFolderPath(Folder *folder, char *folder_path);
    void setFolderSize(Folder *folder, float folder_size);
    void setFolderFileLength(Folder *folder, int folder_file_length);
    void setFolderSetOfFiles(Folder *folder, File **setof_files);

    //Funcao responsavel por deletar o Diretorio (Desalocar)
    void deletefolder(Folder **folder);

    //Funcao responsavel por deletar o Diretorio e seus arquivos (Desalocar)
    void deleFilesAndFolder(Folder *folder);
    //************************* FIM DO CRUD ****************************

    //************************* FUNCOES COMPLEMENTARES DO DIRETORIO *********************************
    //Adiciona um(ou mais) aquivo(s) no diretorio
    void addFileFolder(Folder *folder);

    //Remove um aquivo no diretorio
    int removeFileFolder(Folder *folder);

    //Retornar tamanho do diretorio
    float folderSize(Folder *folder);

    //Listar nomes do arquivos
    void listFolderFile(Folder *folder);

    //Renomeia um arquivo do Diretorio
    int renameFileFolder(Folder *folder);

    //Renomeia o Diretorio
    void renameFolder(Folder *folder);

    //Ler o nome do Diretorio
    char* readFolderName(Folder *folder);
    //************************* FIM DAS FUNCOES
