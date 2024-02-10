#ifndef bst_h
#define bst_h

typedef struct docente{
    int codigo;
    char nome[30];
    char curso[30];
    char disciplina[30];
    char sexo[20];
}dado;

typedef struct indice{
    int chave;
    int indice;
}tipo_dado;

typedef struct no_bst{ 
    tipo_dado *dado;
    struct no_bst *esq;
    struct no_bst *dir;
}no_bst;
typedef no_bst *arvore;


typedef struct tabela{
    FILE *arquivo_dados;
    arvore indices;
    
}tabela;
// teste commit
int inicializarTabela(tabela *tab);
void finalizar (tabela *tab);
void adicionarDado(tabela *tab, dado *docente);
	

void inicializar(arvore *raiz);
arvore adicionar (tipo_dado *valor, arvore raiz);

int altura(arvore raiz);
int maior(int a, int b);
tipo_dado * maior_elemento(arvore raiz);
tipo_dado * menor_elemento(arvore raiz);
void pre_order(arvore raiz, tabela *tab);
void in_order(arvore raiz, tabela *tab);

void pos_order(arvore raiz, tabela *tab);
arvore remover (int valor, arvore raiz);
void imprimir_elemento(arvore raiz, tabela *tab);
dado * pegar_dado();
void tirar_enter(char *string);

void salvar_arquivo(char *nome, arvore a);
void salvar_auxiliar(arvore raiz, FILE *arq);
arvore carregar_arquivo(char *nome, arvore a);

#endif
