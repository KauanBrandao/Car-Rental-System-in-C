#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

extern void menuPrincipal();

void menuCliente();
void registroCliente();
void loginCliente();

struct Cliente{
    char nomeCliente[50];
    char cpfCnpj[20];
    int idade;
    char usuario[20];
    char senha[20];
} info;

typedef Carro{
	char carrosDisponiveis[50];
} carros;

bool menorIdade(){
	if(info.idade < 18){
		return true;
	}
	return false;
}

bool usuarioOuSenhaInvalido(char usuarioOuSenha[20]){
	if(strlen(usuarioOuSenha) > 20){
		return true;
	}
	return false;
}

void registroCliente(){
	fflush(stdin);
	printf("Digite o seu nome: ");
    gets(info.nomeCliente);
    
    printf("\nDigite o seu CPF/CNPJ: ");
    gets(info.cpfCnpj);
    
    printf("\nDigite a sua idade: ");
    scanf(" %d", &info.idade);
    
    if(menorIdade()){
    	printf("\nVoc� tem menos de 18 anos e por isso n�o poder� concluir o cadastro!\n");
    	system("pause");
    	system("cls");
		return menuCliente();
	}
	
	fflush(stdin);
	printf("\nEscolha um usu�rio (MAX 20 CARACTERES): ");
	gets(info.usuario);
	
	if(usuarioOuSenhaInvalido(info.usuario)){
		system("cls");
		printf("ERROR: Usu�rio maior que 20 caracteres!\n\n");
		return registroCliente();
	}
	
	printf("\nEscolha uma senha (MAX 20 CARACTERES): ");
	gets(info.senha);
	
	if(usuarioOuSenhaInvalido(info.senha)){
		system("cls");
		printf("ERROR: Senha maior que 20 caracteres!\n\n");
		return registroCliente();
	}
	
	printf("\nCadastro conclu�do!\n");
	system("pause");
	system("cls");
	menuCliente();
}

bool loginInvalido(char usuario[20], char senha[20]){
	if(strcmp(usuario, info.usuario) != 0 || strcmp(senha, info.senha) != 0){
		return true;
	}
	return false;
}

void loginCliente(){
	char usuario[20];
	char senha[20];
	
	fflush(stdin);
	printf("Insira seu nome de usu�rio: ");
	gets(usuario);
	
	printf("\nInsira sua senha: ");
	gets(senha);
	
	if(loginInvalido(usuario, senha)){
		system("cls");
		printf("Usu�rio ou senha inv�lidos. Tente Novamente\n\n");
		return loginCliente();
	}
	printf("\nLogin efetuado com sucesso.\n");
	system("pause");
	system("cls");
	menuCliente();
}

void regrasLocadora(){
	printf("******** REGRAS LOCADORA ********\n\n");
	
	printf("1. O CARRO DEVE SER ENTREGUE E FEITO O CHECKLIST DE IMEDIATO\n");
	printf("2. O CARRO DEVE SER ENTREGUE COM O TANQUE CHEIO\n");
	printf("3. O CARRO DEVE SER ENTREGUE LIMPO\n");
	printf("4. O LOCADOR DEVE SER RESPONS�VEL POR QUAISQUER DANOS AO VE�CULO.\n");
	printf("5. MULTAS DE TR�NSITO S�O RESPONSABILIDADE DO LOCADOR\n");
	printf("6. O PAGAMENTO DEVE SER FEITO ANTES DE PEGAR O VE�CULO\n");
	printf("7. A CAU��O DEVE SER PAGO COM ANTECED�NCIA\n");
	printf("8. PAGAMENTO DEVE SER FEITO VIA PIX, NO CART�O (EM AT� 12X/ JUROS DE 2% DO CART�O), OU EM ESP�CIE\n\n");
	
	system("pause");
	system("cls");
	return menuCliente();
}

void simularAluguel(){ 
     int i, dias;
     float preco_diario = 100.0; 

     printf(" ### Simular Aluguel ### \n\n");
     carrosDisponiveis();

     printf("Digite o n�mero do carro que deseja simular o aluguel: ");
     scanf("%d", &i);
    
     if (i < 1 || i > total_carros || !carros[i - 1].disponivel) {
        printf("Carro inv�lido ou n�o dispon�vel.\n");
     } else {
        printf("Digite o n�mero de dias que deseja alugar: ");
        scanf("%d", &dias);
        printf("Custo total para alugar o %s, %d por %d dias �: R$%.2f\n", 
            carros[i - 1].modelo, carros[i - 1].ano, dias, preco_diario * dias);
     }
      system("pause");
      system("cls");
      menuCliente();
}

void controleMenuCliente(int opcao){
	switch(opcao){
		case 1:
			registroCliente();
			break;
		case 2:
			loginCliente();
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
			regrasLocadora();
			break;
		case 7: 
			menuPrincipal();
		default:
			printf("Escolha uma op��o v�lida!\n\n");
			menuCliente();
	}
}

void menuCliente(){
	int escolha;
	
	printf("******* Menu de Clientes *******\n\n");
	
	printf("|1 - Registro\n");
	printf("|2 - Login\n");
	printf("|3 - Carros dispon�veis\n");
	printf("|4 - Alugar um veiculo\n");
	printf("|5 - Simular Loca��o\n");
	printf("|6 - Regras da locadora\n");
	printf("|7 - Voltar para o menu inicial\n");
	printf("Escolha uma op��o [1-7]: ");
	scanf("%d", &escolha);
	
	system("cls");
	controleMenuCliente(escolha);
}
