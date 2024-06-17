#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "menuCliente.c"
#include "menuFuncionario.c"
#include "menuFuncionario.h"
#include "menuCliente.h"

void menuPrincipal();

void corrigirAcentuacao(){
	setlocale(LC_ALL, "Portuguese");
}

void creditos(){
	printf("\033[32mDesenvolvido por: Caio Navarro, Emanuel Lucas, Gustavo Santos, Kauan Brand�o, Miguel Neto e Samuel Falc�o\n\n");
	system("pause");
	system("cls");
	menuPrincipal();
}

void sair(){
	printf("\033[32mObrigado por usar nosso sistema!");
}

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
			printf("\033[31mEscolha uma op��o v�lida!\n\n");
			menuPrincipal();
	}
}

void menuPrincipal(){
	char opcao; 
	
	printBanner();
	
	printf("\033[37m------- Menu Inicial -------\n\n");
	printf("\033[37m|1 - Menu de clientes\n");
	printf("\033[37m|2 - Menu de funcion�rios\n");
	printf("\033[37m|3 - Cr�ditos\n");
	printf("\033[37m|4 - Sair do sistema\n");
	printf("\033[33mEscolha uma op��o [1-4]: ");
	scanf(" %c", &opcao);
	
	system("cls");
	controleMenuPrincipal(opcao);
}  

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	carregarClientes();
	carregarVeiculos();
	menuPrincipal();
}