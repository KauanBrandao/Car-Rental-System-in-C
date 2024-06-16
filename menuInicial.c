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
	printf("\033[32mDesenvolvido por: Caio Navarro, Emanuel Lucas, Gustavo Santos, Kauan Brandão, Miguel Neto e Samuel Falcão\n\n");
	system("pause");
	system("cls");
	menuPrincipal();
}

void sair(){
	printf("\033[32mObrigado por usar nosso sistema!");
}

#include <stdio.h>

void printBanner() {
    printf("L       OOO    CCCC    A     N   N    A     I\n");
    printf("L      O   O  C       A A    NN  N   A A    I\n");
    printf("L      O   O  C      A   A   N N N  A   A   I\n");
    printf("L      O   O  C      AAAAA   N  NN  AAAAA   I\n");
    printf("L      O   O  C      A   A   N   N  A   A   I\n");
    printf("LLLLL   OOO    CCCC  A   A   N   N  A   A   I\n");
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
			printf("Escolha uma opção válida!\n\n");
			menuPrincipal();
	}
}

void menuPrincipal(){
	char opcao; 
	
	printBanner();
	
	
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
