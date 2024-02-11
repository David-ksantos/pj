#ifndef BST_C
#define BST_C

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "bst.h"


// BST --------------------------------------------------------------------------------------------------------------------
dado * buscar_codigo(int chave, arvore1 raiz, tabela *tab) {
    if (raiz == NULL) {
        return NULL;
    }

    if (chave == raiz->dado->chave) {
        dado *registro_encontrado = (dado *)malloc(sizeof(dado));
        if (registro_encontrado == NULL) {
            printf("Erro de alocacao\n");
            exit(1);
        }
        fseek(tab->arquivo_dados, raiz->dado->indice, SEEK_SET);
        if (fread(registro_encontrado, sizeof(dado), 1, tab->arquivo_dados) != 1) {
            printf("Erro ao ler registro\n");
            exit(1);
        }
        return registro_encontrado;
    }
    else if (chave > raiz->dado->chave) {
        return buscar_codigo(chave, raiz->dir, tab);
    }
    else {
        return buscar_codigo(chave, raiz->esq, tab);
    }
}

arvore1 remover_codigo (int valor, arvore1 raiz) {
	if(raiz == NULL) 
		return NULL;
	
	if(raiz->dado->chave == valor) {		
		if(raiz->esq == NULL) {
			return raiz->dir;
		}
		if(raiz->dir == NULL) {
			return raiz->esq;
		}
		raiz->dado = maior_elemento(raiz->esq);
		raiz->esq = remover_codigo(raiz->dado->chave, raiz->esq);
		return raiz;
	}	
	if(valor > raiz->dado->chave) {
			raiz->dir = remover_codigo(valor, raiz->dir);
	} else {
			raiz->esq = remover_codigo(valor, raiz->esq);
	}
	return raiz;
}

arvore1 adicionar (tipo_dado *valor, arvore1 raiz) {
	if(raiz == NULL) {
		arvore1 novo = (arvore1) malloc(sizeof(struct no_bst));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}

	if(valor->chave > raiz->dado->chave) {
		raiz->dir = adicionar(valor, raiz->dir);
	} else {
		raiz->esq = adicionar(valor, raiz->esq);
	}
	return raiz;
}

//AVL ----------------------------------------------------------------------------------------------------------------------------------
/*dado * buscar_nome(char *nome, arvore1 raiz, tabela *tab) {
    if (raiz == NULL) {
        return NULL;
    }

    int comparacao = strcmp(nome, raiz->dado->nome);

    if (comparacao == 0) {
        dado *registro_encontrado = (dado *)malloc(sizeof(dado));
        if (registro_encontrado == NULL) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
        fseek(tab->arquivo_dados, raiz->dado->indice, SEEK_SET);
        if (fread(registro_encontrado, sizeof(dado), 1, tab->arquivo_dados) != 1) {
            printf("Erro ao ler registro do arquivo de dados.\n");
            exit(1);
        }
        
        return registro_encontrado;
    }
    else if (comparacao > 0) {
        return buscar_nome(nome, raiz->dir, tab);
    }
    else {
        return buscar_nome(nome, raiz->esq, tab);
    }
}*/

void inicializar(arvore1 *raiz){
    *raiz = NULL;
}

int inicializarTabela(tabela *tab) {
	inicializar(&tab->indices);	
	tab->arquivo_dados = fopen("dados.dat", "a+b");
	tab->indices = carregar_arquivo("indices.dat", tab->indices);
	if(tab->arquivo_dados != NULL)
		return 1;
	else
		return 0;
}

void finalizar (tabela *tab) {
	fclose(tab->arquivo_dados);
	salvar_arquivo("indices.dat", tab->indices);
}



void adicionarDado(tabela *tab, dado *docente){
	if(tab->arquivo_dados != NULL) {
			tipo_dado * novo = (tipo_dado *) malloc(sizeof(tipo_dado));
			if (novo == NULL) {
            printf("Erro de alocacao\n");
            exit(1);
        }
			novo->chave = docente->codigo;

			fseek(tab->arquivo_dados, 0L, SEEK_END);
			novo->indice = ftell(tab->arquivo_dados);

			fwrite(docente, sizeof(dado), 1, tab->arquivo_dados);
			tab->indices = adicionar(novo, tab->indices);
	}
}




int altura(arvore1 raiz) {
	if(raiz == NULL) {
		return 0;
	}
	return 1 + maior(altura(raiz->dir), altura(raiz->esq));
}

int maior(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

tipo_dado * maior_elemento(arvore1 raiz) {
	if(raiz == NULL)
			return NULL;
	if(raiz->dir == NULL)
			return raiz->dado;
	else
			return maior_elemento(raiz->dir);
}

tipo_dado * menor_elemento(arvore1 raiz) {
	if(raiz == NULL)
			return NULL;
	if(raiz->esq == NULL)
			return raiz->dado;
	else
			return maior_elemento(raiz->esq);
}

void pre_order(arvore1 raiz, tabela *tab) {
	if(raiz != NULL) {
		imprimir_elemento(raiz, tab);
		pre_order(raiz->esq, tab);
		pre_order(raiz->dir, tab);
	}
}

void in_order(arvore1 raiz, tabela *tab) {
	if(raiz != NULL) {
		pre_order(raiz->esq, tab);
		imprimir_elemento(raiz, tab);
		pre_order(raiz->dir, tab);
	}
}

void pos_order(arvore1 raiz, tabela *tab) {
	if(raiz != NULL) {
		pre_order(raiz->esq, tab);
		pre_order(raiz->dir, tab);
		imprimir_elemento(raiz, tab);
	}
}



void imprimir_elemento(arvore1 raiz, tabela * tab) {
	dado *temp = (dado*) malloc (sizeof(dado));
    temp->codigo = 1000;
    printf("indice: %d\n", raiz->dado->indice);

   	fseek(tab->arquivo_dados, raiz->dado->indice, SEEK_SET);
	//
	int r = fread(temp, sizeof(dado), 1, tab->arquivo_dados);

	printf("[%d, %d, %s, %s, %s ]\n", raiz->dado->chave,r, temp->nome, temp->curso, temp->disciplina);
	free(temp);
}



void tirar_enter(char *string) {
	string[strlen(string) -1] = '\0';
}

dado *pegar_dado(){
    dado *novo = (dado*)malloc(sizeof(dado));

    getchar();
   	printf("digite o nome: ");
    fgets(novo->nome, 30, stdin);
    tirar_enter(novo->nome);

    printf("digite o curso: ");
    fgets(novo->curso, 30, stdin);
    tirar_enter(novo->curso);

    printf("digite a disciplina: ");
    fgets(novo->disciplina, 30, stdin);
    tirar_enter(novo->disciplina);

	printf("digite o sexo: ");
    fgets(novo->sexo, 20, stdin);
	tirar_enter(novo->sexo);
	
	printf("digite o codigo: ");
    scanf("%d", &novo->codigo);

    
    

    return novo;
}



void salvar_arquivo(char *nome, arvore1 a) {
	FILE *arq;
	arq = fopen(nome, "wb");
	if(arq != NULL) {
		salvar_auxiliar(a, arq);
		fclose(arq);
	}
}

void salvar_auxiliar(arvore1 raiz, FILE *arq){
	if(raiz != NULL) {
		fwrite(raiz->dado, sizeof(tipo_dado), 1, arq);
		salvar_auxiliar(raiz->esq, arq);
		salvar_auxiliar(raiz->dir, arq);
	}

}

arvore1 carregar_arquivo(char *nome, arvore1 a) {
	FILE *arq;
	arq = fopen(nome, "rb");
	tipo_dado * temp;
	if(arq != NULL) {
		temp = (tipo_dado *) malloc(sizeof(tipo_dado));
		while(fread(temp, sizeof(tipo_dado), 1, arq)) {
			
			a = adicionar(temp, a);			
			temp = (tipo_dado *) malloc(sizeof(tipo_dado));

		}
		fclose(arq);

	}
	return a;
}

#endif
