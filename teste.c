#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "bst.c"

int main(int argc, char * argv[]) {
	tabela tab;
	int opcao;
	inicializarTabela(&tab);

	while(1) {
		printf("1-altura\n2-cadastrar\n3-pre-order\n10-salvar arquivo\n11-carregar arquivo");
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
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
						pre_order(tab.indices, &tab);
						printf("\n");
						break;
				case 5:
						pre_order(tab.indices, &tab);
						printf("\n");
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
		}
	}
return 0;}
