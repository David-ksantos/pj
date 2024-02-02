#include<stdio.h>
#include<stdlib.h>
#include <string.h>


#include "bst.h"


void inicializar(arvore_bst *raiz){
    *raiz = NULL;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
}

dado pegar_dado(){
    dado novo = (dado)malloc(sizeof(docente));

    getchar();
    printf("digite o codigo: ");
    scanf("%d", novo->codigo);
    limpar_buffer();

    printf("digite o nome: ");
    fgets(novo->nome, 30, stdin);
    limpar_buffer();

    printf("digite o curso: ");
    fgets(novo->curso, 30, stdin);
    limpar_buffer();

    printf("digite a disciplina: ");
    fgets(novo->disciplina, 30, stdin);
    limpar_buffer();

    printf("digite o sexo: ");
    scanf("%c", novo->sexo);
    limpar_buffer();

    return novo;
}



