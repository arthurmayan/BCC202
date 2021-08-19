typedef struct lista Lista;
typedef struct listaNo ListaNo;

Lista *criarLista();
ListaNo *criarListaNo(char *nome, int idade);
void inserirInicio(Lista *lista, char *nome, int idade);
void inserirFinal(Lista *lista, char *nome, int idade);
void lst_imprime (Lista *l);
void imprimeListaNo(ListaNo *listaNo);
void lst_liberar(Lista *l);
void lst_insere_ordenado ( Lista *l, char conteudo);
void lst_pertence(Lista *l, char conteudo);
void lst_retira (Lista *l, int idade, char nome);


