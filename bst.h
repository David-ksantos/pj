#ifndef BST_H
#define BST_H


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

typedef struct indice2{
    char chave[30];
    int indice2;
}tipo_dado2;

typedef struct no_bst{ 
    tipo_dado *dado;
    struct no_bst *esq;
    struct no_bst *dir;
}no_bst;
typedef no_bst *arvore1;

typedef struct no_avl{ 
    tipo_dado *dado;
    int fb;
    struct no_avl *esq;
    struct no_avl *dir;
}no_avl;
typedef no_avl *arvore2;


typedef struct tabela{
    FILE *arquivo_dados;
    arvore1 indices;
    arvore2 indices2;
    
    
}tabela;

// teste commit
int inicializarTabela(tabela *tab);
void finalizar (tabela *tab);
void adicionarDado(tabela *tab, dado *docente);
void inicializar(arvore1 *raiz);
arvore1 adicionar (tipo_dado *valor, arvore1 raiz);
int altura(arvore1 raiz);
int maior(int a, int b);
tipo_dado * maior_elemento(arvore1 raiz);
tipo_dado * menor_elemento(arvore1 raiz);
void pre_order(arvore1 raiz, tabela *tab);
void in_order(arvore1 raiz, tabela *tab);
void pos_order(arvore1 raiz, tabela *tab);
arvore1 remover (int valor, arvore1 raiz);
void imprimir_elemento(arvore1 raiz, tabela *tab);
dado * pegar_dado();
void tirar_enter(char *string);
void salvar_arquivo(char *nome, arvore1 a);
void salvar_auxiliar(arvore1 raiz, FILE *arq);
arvore1 carregar_arquivo(char *nome, arvore1 a);




#endif
