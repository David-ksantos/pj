#ifndef bst_h
#define bst_h

typedef struct docente{
    int codigo;
    char nome[30];
    char curso[30];
    char disciplina[30];
    char sexo;
}docente;
typedef docente *dado;


typedef struct indice{
    int chave;
    int indice;
}indice;

typedef struct no_bst{ 
    indice *dado;
    struct no *esq;
    struct no *dir;
}no_bst;
typedef no_bst *arvore_bst;


typedef struct tabela{
    FILE *arquivo;
    arvore_bst indices;
    
}tabela;


#endif
