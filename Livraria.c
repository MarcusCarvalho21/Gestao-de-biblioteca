#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct livro{
	char *titulo;
	char *autor;
	char *isbn;
	char *anoEdicao;
	char *editora;
	int situacao;
};
typedef struct livro Livro;

Livro *novoLivro(char *titulo, char *autor, char *isbn, char *anoEdicao, char *editora, int situacao){
	Livro *book = (Livro*)malloc(sizeof(Livro));
	
	book->titulo = titulo;
	book->autor = autor;
	book->isbn = isbn;
	book->anoEdicao = anoEdicao;
	book->editora = editora;
	book->situacao = situacao;
	
	
	return book;
}

void freeLivros(Livro *livro){
	
	free(livro->titulo);
	free(livro->autor);
	free(livro->isbn);
	free(livro->anoEdicao);
	free(livro->editora);
	free(livro);
}

int main(){
	
	int i = 0;
	int x = 0;
	int operacao = 0;
	int indice = 0;
	
	Livro **livro = (Livro**)malloc(100 * sizeof(Livro*));
	
	for(i = 0; i < 100; i++){
		livro[i] = NULL;
	}
	
	printf("Bem Vindo! ");
	
	while(x == 0){
		
		printf("\n\nQual operacao realizar? \n[1] - Cadastrar Livro \n[2] - Remover livro \n[3] - Emprestar Livro \n[4] - Devolver Livro \n[5] - Listar Livros Emprestador \n[6] - Listar Livros Disponiveis \n[7] - Sair do sistema ");
		scanf(" %d", &operacao);
		
		if(operacao == 1){
			for(i = 0; i < 100; i++){
				if(livro[i] == NULL){
					char *titulo = (char*)malloc(50 * sizeof(char));
					char *autor = (char*)malloc(50 * sizeof(char));
					char *isbn = (char*)malloc(20 * sizeof(char));
					char *anoEdicao = (char*)malloc(10 * sizeof(char));
					char *editora = (char*)malloc(50 *sizeof(char));
					int situacao = 0;
					
					printf("Informe o titulo: ");
					setbuf(stdin, NULL);
					gets(titulo);
					printf("Informe o autor: ");
					setbuf(stdin, NULL);
					gets(autor);
					printf("Informe o ISBN: ");
					setbuf(stdin, NULL);
					gets(isbn);
					printf("Informe o ano da edicao: ");
					setbuf(stdin, NULL);
					gets(anoEdicao);
					printf("Informe a editora: ");
					setbuf(stdin, NULL);
					gets(editora);
					printf("Informe a situacao: [0] - Emprestado [1] - Disponivel");
					scanf(" %d", &situacao);
					
					livro[i] = novoLivro(titulo, autor, isbn, anoEdicao, editora, situacao);
					break;
				}
			}
		}else if(operacao == 2){
			printf("Informe o indice do livro pra remover: ");
			scanf(" %d", &indice);
			
			if(livro[indice] == NULL){
				printf("\nO livro nesse indece nao existe ou ja foi removido!");
			}else{
				livro[indice] = NULL;
			}
		}else if(operacao == 3){
			printf("Informe o indice do livro pra Emprestar: ");
			scanf(" %d", &indice);
			if(livro[indice] == NULL){
				printf("\nO livro nesse indece nao existe!");
			}else{
				livro[indice]->situacao = 0;;
			}			
		}else if(operacao == 4){
			printf("\nInforme o indice do livro pra Devolver: ");
			scanf(" %d", &indice);
		
			if(livro[indice] == NULL){
				printf("\nO livro nesse indece nao existe!");
			}else{
				livro[indice]->situacao = 1;
			}		
		}else if(operacao == 5){
			for(i = 0; i < 100; i++){
				if(livro[i] != NULL && livro[i]->situacao == 0){
					printf("\nLivro: %s Indice: %d \n", livro[i]->titulo, i);
				}
			}
		}else if(operacao == 6){
			for(i = 0; i < 100; i++){
				if(livro[i] != NULL && livro[i]->situacao == 1){
					printf("\nLivro: %s Indice: %d \n", livro[i]->titulo, i);
				}
			}
		}
		else if(operacao == 7){
			x = 1;
			for(i = 0; i < 100; i++){
				if(livro[i] != NULL){
				
					freeLivros(livro[i]);
				
				}
			}
			free(livro);
		}	
	}
			
	return 0;
}
