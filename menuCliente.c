#include <stdio.h>
#include <stdlib.h>

void menuCliente();

void controleMenuCliente(int opcao){
	switch(opcao){
		case 1:
			//registroCliente();
			break;
		case 2:
			//loginCliente();
			break;
		case 3:
			//carrosDisponiveis();
			break;
		case 4:
			//alugarVeiculo();
			break;
		case 5:
			//simularAluguel();
			break;
		case 6:
			//regrasLocadora();
			break;
		default:
			printf("Escolha uma op��o v�lida!\n\n");
			menuCliente();
	}
}

void menuCliente(){
	int escolha;
	
	printf("******* Menu de Clientes *******\n");
	
	printf("|1 - Registro\n");
	printf("|2 - Login\n");
	printf("|3 - Carros dispon�veis\n");
	printf("|4 - Alugar um veiculo\n");
	printf("|5 - Simular Loca��o\n");
	printf("|6 - Regras da locadora\n");
	printf("Escolha uma op��o [1-6]: ");
	scanf("%d", &escolha);
	
	system("cls");
	controleMenuCliente(escolha);
}