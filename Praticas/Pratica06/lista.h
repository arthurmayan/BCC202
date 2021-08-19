typedef struct lista Lista;
typedef struct listaNo ListaNo;

Lista *lst_cria();
ListaNo *criarListaNo(ListaNo *listaNo, int conteudo);

int getConteudo(ListaNo *listaNo);
void setConteudo(ListaNo *listaNo, int conteudo);

void lst_imprime (Lista *l);
int lst_pertence(Lista *l, int conteudo);
void lst_insere_ordenado ( Lista *l, int conteudo);
void lst_retira (Lista *l, int conteudo);
void lst_liberar(Lista *l);
void lst_liberar_vetor(Lista **l);










