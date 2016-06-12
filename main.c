#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30], autor[20], editora[30];
	int ano;
}LIVRO;

typedef struct no{
	LIVRO conteudo;
	struct no *prox;
}NO_FILA;

typedef struct {
	NO_PILHA *inicio;
	NO_FILA *fim;
}FILA;



void criaFila (FILA *fila){
	fila = NULL;
}

//INÍCIO DA FUNÇÃO TAMANHO FILA
int tamanho(FILA fila){
	int cont = 0;
	NO_FILA *aux = fila.inicio;
	if(aux == NULL)
		return cont;
	else{
		do{
			aux = aux->prox;
			cont++;
		}while(aux != NULL);
	}
	return cont;
}

//INÍCIO DA FUNÇÃO LIBERAR FILA
void liberar (FILA *fila){
	NO_FILA *aux = fila->inicio;
	if(aux == NULL)
		printf("Fila Vazia\n");
	else{
		do{
			fila->inicio = fila->inicio->prox;
			free(aux);
			aux = fila->inicio;
		}while(aux != NULL);
	}
}

//INÍCIO DA FUNÇÃO ENFILEIRAR FILA
void enfileirar(FILA *fila, LIVRO dados){
	NO_FILA *novo = (NO_FILA*) malloc(sizeof(NO_FILA));
	if(novo == NULL)
		printf("Não existe memória\n");
	else{
		novo->conteudo = dados;
		novo->prox = NULL;

		if(fila->fim == NULL)
			fila->inicio = novo;
		else
			fila->fim->prox = novo;
		fila->fim = novo;
	}
}

//INÍCIO DA FUNÇÃO DESENFILEIRAR FILA
void desenfileirar(FILA *fila){
	NO_FILA *novo = (NO_FILA*) malloc(sizeof(NO_FILA));
	if(novo == NULL)
		printf("Fila Vazia\n");
	else{
		fila->inicio = fila->inicio->prox;

		if(fila->inicio == NULL){
			fila->inicio = NULL;
			free(aux);
		}
		else
			fila->fim = fila->fim->prox;
	}
}


//INÍCIO DA FUNÇÃO PESQUISAR FILA
void pesquisar (FILA *fila, int ano){
	NO_FILA *aux = fila->inicio;
	int armazena;
	if (aux == NULL)
		printf ("Nao existem livros cadastrados \n");
	else{
		while(aux != NULL && aux->conteudo.ano != idade){
			aux = aux->prox;
		}
		if(aux == NULL)
			printf("Livro não encontrado\n");
		else{
			printf ("\n NOME: %s \n", aux->conteudo.nome);
			printf (" ANO: %d \n", aux->conteudo.ano);
			printf (" AUTOR: %s \n", aux->conteudo.autor);
			printf (" EDITORA: %s \n \n", aux->conteudo.editora);
		}
	}
}

//INÍCIO DA FUNÇÃO MOSTRAR FILA
void mostrar(FILA *fila){
	NO_FILA *aux = fila->inicio;
	if (aux == NULL)
		printf ("Nao existem livros cadastrados \n");
	else{
		while(aux != NULL){
			printf ("\n NOME: %s \n", aux->conteudo.nome);
			printf (" ANO: %d \n", aux->conteudo.ano);
			printf (" AUTOR: %s \n", aux->conteudo.autor);
			printf (" EDITORA: %s \n \n", aux->conteudo.editora);
		}
	}
}

//INÍCIO DA FUNÇÃO MAIN
int main (){
	FILA *fila = NULL;
	LIVRO dados;
	int op, ano;
	criaFila(&fila);
	
	do{
		printf (" \n \tESCOLHA UMA OPCAO DE MENU \n");
		printf ("----------------------------------------- \n");
		printf (" 1 - Enfileirar Livros \n");
		printf (" 2 - Desenfileirar Livros \n");
		printf (" 3 - Listar Todos os Livros \n");
		printf (" 4 - Pesquisar Livros \n");
		printf (" 5 - Esvaziar \n");
		printf (" 6 - Tamanho \n");
		printf (" 7 - Sair \n");
		printf (" Opcao: ");
		scanf ("%d", &op);
		
		switch (op){
			case 1:
				printf (" \n \t INSERCAO DE LIVROS \n");
				printf ("----------------------------------------- \n");
				printf (" Fornecas as informacoes abaixo \n");
				printf (" NOME: ");
				scanf ("%s", dados.nome);
				printf (" AUTOR: ");
				scanf ("%s", dados.autor);
				printf (" EDITORA: ");
				scanf ("%s", dados.editora);
				printf (" ANO: ");
				scanf ("%d", &dados.ano);
				enfileirar(&fila, dados);
				break;
			case 2:
				printf (" \n \t REMOCAO DE LIVROS \n");
				printf ("----------------------------------------- \n");
				desenfileirar(&fila);
				break;
			case 3:
				printf (" \n \t TODOS LIVROS CADASTRADOS \n");
				printf ("----------------------------------------- \n");
				mostrar(&fila);
				break;
			case 4:
				printf (" \n \t PESQUISA DE LIVROS \n");
				printf ("----------------------------------------- \n");
				printf (" Informe o ano \n");
				printf (" ANO: ");
				scanf ("%d", &ano);
				pesquisar (&fila, ano);
				break;
			case 5:
				printf (" \n \t ESVAZIANDO A FILA \n");
				printf ("----------------------------------------- \n");
				liberar (&fila);
				break;
			case 6:
				printf (" \n \t TAMANHO \n");
				printf ("----------------------------------------- \n");
				printf (" Tamanho: %d ", tamanho(&fila));
				break;
			case 7:
				printf  (" Programa Encerrado \n");
				break;
			default:
				printf (" Escolha uma valor valido \n");
		}
	}while (op != 7);
}