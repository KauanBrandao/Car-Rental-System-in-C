#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuFuncionario();

void controleMenuFuncionario(int opcao){
	switch(opcao){
		case 1:
			cadastrarVeiculo();
			break;
		case 2:
			//removerVeiculo();
			break;
		case 3:
			//carrosDisponiveis();
			break;
		case 4:
			//alugarVeiculo();
			break;
		default:
			printf("Escolha uma opção válida!\n\n");
			menuFuncionario();
	}
}

void loginFuncionario(){
	char login[10];
	char senha[10];
	
	fflush(stdin);
	printf("Insira o login: ");
	scanf(" %s", login);
	
	printf("\nInsira a senha: ");
	scanf(" %s", senha);
	
	if(strcmp(login, "ADMIN")==0 && strcmp(senha, "0000")==0){
		printf("\nLogin bem sucedido!\n");
		system("pause");
		system("cls");
		menuFuncionario();
	}else{
		system("cls");
		printf("Login ou senha inválidos.\n\n");
		loginFuncionario();
	}
}

void menuFuncionario(){
	int opcao;
	
	printf("******* Menu de Funcionário *******\n");
	
	printf("|1 - Cadastrar veiculo\n");
	printf("|2 - Remover veiculos\n");
	printf("|3 - Buscar veiculos\n");
	printf("|4 - Consultar locações\n");	
	printf("Escolha uma opção: ");
	scanf("%d", &opcao);
	
	system("cls");
	controleMenuFuncionario(opcao);
}

void cadastrarVeiculo(){
	char nomecarros [40];
	char modelocarros [40];
	int codigocarros [4];
	
	printf("Digite o nome do carro: \n");
	scanf("%s", nomecarros);
	
	printf("Digite o modelo do carro: \n");
	scanf("%s", modelocarros);
	
	printf("Digite o codígo para esse veículo: \n");
	scanf("%d", codigocarros);
	
	system("cls");
	
	printf("**** CARRO CADASTRADO COM SUCESSO ****");
	menuFuncionario();
}
