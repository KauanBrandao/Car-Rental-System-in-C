#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "menuCliente.c"
#include "menuFuncionario.c"
#include "menuFrontEnd.c"
#include "menuCliente.h"
#include "menuFuncionario.h"
#include "menuFrontEnd.h"

void menuPrincipal();

void corrigirAcentuacao(){
	setlocale(LC_ALL, "Portuguese");
}

void creditos(){
	printf("\033[32mDesenvolvido por: Caio Navarro, Emanuel Lucas, Gustavo Santos, Kauan Brandão, Miguel Neto e Samuel Falcão\n\n");
	system("pause");
	system("cls");
	menuPrincipal();
}

void sair(){
	printf("\033[32mObrigado por usar nosso sistema!");
}

#include <stdio.h>

void printCompleteBanner(); 

void controleMenuPrincipal(char opcao){
	switch(opcao){
		case '1':
			menuClienteRegistro();
			break;
		case '2':
			loginFuncionario();
			break;
		case '3':
			creditos();
			break;
		case '4':
			sair();
			exit(0);
		default:
			printf("\033[37mEscolha uma opção válida!\n\n");
			menuPrincipal();
	}
}

void menuPrincipal(){
	char opcao; 
	
	printCompleteBanner();
	
	
	printf("\n \n");
	
	printf("------- Menu Inicial -------\n\n");
	printf("|1 - Menu de clientes\n");
	printf("|2 - Menu de funcionários\n");
	printf("|3 - Créditos\n");
	printf("|4 - Sair do sistema\n");
	printf("Escolha uma opção [1-4]: ");
	scanf(" %c", &opcao);
	
	system("cls");
	controleMenuPrincipal(opcao);
}  

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	menuPrincipal();
}
