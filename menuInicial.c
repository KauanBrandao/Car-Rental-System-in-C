#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "menuCliente.c"
#include "menuFuncionario.c"

void menuPrincipal();

struct RegistroDePessoa{
	char nome[50];
	int dataNascimento;
	char cpf[15];
	char usuario[20];
	char senha[20];
} cliente; 

void corrigirAcentuacao(){
	setlocale(LC_ALL, "Portuguese");
}

void creditos(){
	printf("Desenvolvido por: Caio Navarro, Emanuel Lucas, Gustavo Santos, Kauan Brandao, Miguel Neto e Samuel Falcão\n\n");
	system("pause");
	system("cls");
	menuPrincipal();
}

void sair(){
	printf("Saindo...");
}

void controleMenuPrincipal(int escolha){
	switch(escolha){
		case 1:
			menuCliente();
			break;
		case 2:
			loginFuncionario();
			break;
		case 3:
			creditos();
			break;
		case 4:
			sair();
			exit(0);
		default:
			printf("Escolha uma opção válida!\n\n");
			menuPrincipal();
	}
}

void menuPrincipal(){
	int escolha; 
	
	printf("------- Menu Inicial -------\n\n");
	printf("|1 - Menu de clientes\n");
	printf("|2 - Menu de funcionários\n");
	printf("|3 - Créditos\n");
	printf("|4 - Sair do sistema\n");
	printf("Escolha uma opção [1-4]: ");
	scanf("%d", &escolha);
	
	system("cls");
	controleMenuPrincipal(escolha);
}  

int main(){
	corrigirAcentuacao();
	
	menuPrincipal();
}
