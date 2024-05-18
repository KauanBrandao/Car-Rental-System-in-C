#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct registroDePessoa {
	char nome[50];
	int dataNascimento[50];
	char cpf[15];
	char usuario[20];
	char senha[10];
} Cliente; 

void desenvolvedores () {
	printf("Desenvolvido por: Caio Navarro, Emanuel Lucas, Gustavo Santos, Kauan Brandao, Miguel Ribeiro e Samuel Falc�o");

}

void menuCliente () {
	int operadorCliente;
	

	printf("   ******* Menu de clientes *******\n");
	
	printf("1 - Registrar Informa��es\n");
	printf("2 - Login\n");
	printf("3 - Carros dispon�veis\n");
	printf("4 - Pre�os di�rias\n");
	printf("5 - Simular Loca��o\n");
	printf("6 - Regras da locadora\n");
	printf("7 - Alugar um veiculo\n");
	printf("\n8 - Escolha uma op��o: ");
	scanf("%d", &operadorCliente);
	
}

void menuFuncionario () {
	int operadorFuncionario, token;
	
	/*printf("*** Menu de funcion�rios ***\n");
	printf("Informe o token de acesso: ");
	scanf("%d", token);
	
	system("cls");*/
	
	printf("1 - Cadastrar veiculos\n");
	printf("2 - Remover veiculos\n");
	printf("3 - Buscar veiculos\n");
	printf("4 - Consultar loca��es\n");	
	printf("\n5 - Escolha uma op��o: ");
	scanf("%d", &operadorFuncionario);
	
}

void menu () {
	int escolha; 
	printf("------- Menu Inicial locadora veicular -------\n\n");
	printf("1 - Menu de clientes\n");
	printf("2 - Menu de funcion�rios\n");
	printf("3 - Desenvolvedores\n");
	printf("4 - Sair do sistema\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &escolha);
	
	switch(escolha) {
		case 1:
			fflush(stdin);
			system("cls");
			menuCliente();
			break;
		case 2: 
			fflush(stdin);
			system("cls");
			menuFuncionario();
			break;
		case 3:
			fflush(stdin);
			system("cls");
			desenvolvedores();
			break;
		default: 
			abort();
		}
	}  


int main () {
	setlocale(LC_ALL, "Portuguese");
	
	menu();
	
}
