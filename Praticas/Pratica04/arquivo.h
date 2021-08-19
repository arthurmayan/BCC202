    //Struct que possui os atibutos do arquivo
    typedef struct file File;

    //Funcao responsavel por criar o arquivo (Alocar)
    File* createFile(char *file_name, char *file_type, float file_size);

    //Gets do Arquivo (ler os atributos do arquivo)
    char* getFileName(File *file);
    char* getFileType(File *file);
    float getFileSize(File *file);

    //Sets do Arquivo (atualiza os atributos do arquivo)
    void setFileName(File *file, char *file_name);
    void setFileType(File *file, char *file_type);
    void setFileSize(File *file, float file_size);

    //Funcao responsavel por deletar o Arquivo (Desalocar)
    void deleteFile(File **file);


