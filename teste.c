#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "bst.c"

int main(int argc, char * argv[]) {
	tabela tab;
	int opcao;
	int valor;
	char nome[30];
	inicializarTabela(&tab);

	while(1) {
		printf("1-altura\n2-cadastrar\n3-preorder\n4-inorder\n5-posorder\n6-buscar (codigo)\n7-remover (codigo)\n10-salvar arquivo\n11-carregar arquivo\n");
		scanf("%d", &opcao);

		switch(opcao) {
				case 1:
						printf("%d\n", altura(tab.indices));
						break;
				case 2:
						adicionarDado(&tab, pegar_dado());
						break;
				case 3:
						pre_order(tab.indices, &tab);
						printf("\n");
						break;
				case 4:
						in_order(tab.indices, &tab);
						printf("\n");
						break;
				case 5:
						pos_order(tab.indices, &tab);
						printf("\n");
						break;
				case 6:
						printf("digite a chave de procura por codigo: ");
						scanf("%d", &valor);
						dado *reg = buscar_codigo(valor, tab.indices, &tab);
						if( reg != NULL){
							printf("\n");
							printf("Registro valido\n");
							printf("\tchave: %d\n", reg->codigo);
							printf("\tNome: %s\n", reg->nome);
							printf("\tCurso: %s\n", reg->curso);
							printf("\tDisciplina: %s\n", reg->disciplina);
							printf("\tSexo: %s\n", reg->sexo);
							printf("\n");
						}
						else{
							printf("Registro inexistente\n");
						}
						break;
				case 7: 
						printf("digite o codigo do registro a ser removido: ");
						scanf("%d", &valor);
						tab.indices = remover_codigo(valor, tab.indices);
						break;
				case 8:
						printf("Digite o nome para buscar: ");
                		char nome[30];
                		getchar(); 
                		fgets(nome, 30, stdin);
                		nome[strlen(nome) - 1] = '\0'; 
                		dado *reg_nome = buscar_nome(nome, tab.indices, &tab);
                		if (reg_nome != NULL) {
                    	printf("Registro encontrado:\n");
                    	printf("Chave: %d\n", reg_nome->codigo);
                    	printf("Nome: %s\n", reg_nome->nome);
                    	printf("Curso: %s\n", reg_nome->curso);
                    	printf("Disciplina: %s\n", reg_nome->disciplina);
                    	printf("Sexo: %s\n", reg_nome->sexo);
                		} 	else
					 	{ printf("Registro não encontrado\n");
                		}
                		break;

				case 10:
						salvar_arquivo("dados.dat", tab.indices);
						break;

				case 11:
						tab.indices = carregar_arquivo("dados.dat", tab.indices);
						break;
					 
				case 99:
						finalizar(&tab);
						exit(0);
						break;
				default:
						printf("opcao invalida\n");
		}
	}
}
