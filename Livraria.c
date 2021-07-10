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

int main(){
	
	int i = 0;
	int x = 0;
	int operacao = 0;
	
	Livro **livro = (Livro**)malloc(100 * sizeof(Livro*));
	
	for(i = 0; i < 100; i++){
		livro[i] = NULL;
	}
	
	while(x == 0){
		
		printf("Qual operação realizar? ");
		scanf(" %d", &operacao);
		
		if(operacao == 1){
			char *titulo = (char*)malloc(sizeof(char));
			char *autor = (char*)malloc(sizeof(char));
			char *isbn = (char*)malloc(sizeof(char));
			char *anoEdicao = (char*)malloc(sizeof(char));
			char *editora = (char*)malloc(sizeof(char));
			int situacao = 0;
			
			printf("Informe o titulo: ");
			scanf(" %s", titulo);
			printf("Informe o autor: ");
			scanf(" %s", autor);
			printf("Informe o ISBN: ");
			scanf(" %s", isbn);
			printf("Informe o ano da edicao: ");
			scanf(" %s", anoEdicao);
			printf("Informe a editora: ");
			scanf(" %s", editora);
			printf("Informe a situacao: [1] - Disponivel [2] - Emprestado");
			scanf(" %d", &situacao);
			
			livro[0] = novoLivro(titulo, autor, isbn, anoEdicao, editora, situacao);
			
		}
	}
		
	return 0;
}
