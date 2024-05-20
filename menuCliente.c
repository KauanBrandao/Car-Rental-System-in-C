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
			printf("Escolha uma opção válida!\n\n");
			menuCliente();
	}
}

void menuCliente(){
	int escolha;
	
	printf("******* Menu de Clientes *******\n");
	
	printf("|1 - Registro\n");
	printf("|2 - Login\n");
	printf("|3 - Carros disponíveis\n");
	printf("|4 - Alugar um veiculo\n");
	printf("|5 - Simular Locação\n");
	printf("|6 - Regras da locadora\n");
	printf("Escolha uma opção [1-6]: ");
	scanf("%d", &escolha);
	
	system("cls");
	controleMenuCliente(escolha);
}

void regrasLocadora(){
	
	printf("******** REGRAS LOCADORA ********\n ");
	
	printf("1. O CARRO DEVE SER ENTREGUE E FEITO O CHECKLIST DE IMEDIATO\n");
	printf("2. O CARRO DEVE SER ENTREGUE COM O TANQUE CHEIO\n");
	printf("3. O CARRO DEVE SER ENTREGUE LAVADO\n");
	printf("4. O LOCADOR DEVE SER RESPONSÁVEL POR QUAISQUER DANO AO VEÍCULO.\n");
	printf("5. MULTAS DE TRÂNSITO SÃO RESPONSABILIDADE DO LOCADOR\n");
	printf("6. O PAGAMENTO DEVE SER FEITO ANTES DE PEGAR O VEÍCULO\n");
	printf("7. O CAUÇÃO DEVE SER PAGO COM ANTECEDÊNCIA PAGO NO PIX OU EM ESPÉCIE\n");
	printf("8. PAGAMENTO DA LOCAÇÃO DEVE SER FEITO VIA PIX, NO CARTÃO (EM ATÉ 12X/ JUROS DE 2% DO CARTÃO), OU EM ESPÉCIE\n");
	
	
}
