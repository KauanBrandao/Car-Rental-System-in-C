#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VEICULOS 100

struct Veiculo{
    char nome[40];
    char modelo[15];
    int codigo;
} veiculos[MAX_VEICULOS];

int totalVeiculos = 0;

extern void menuPrincipal();
void menuFuncionario();
void cadastrarVeiculo();
void removerVeiculo();
void buscarVeiculo();


void controleMenuFuncionario(int opcao){
    switch(opcao) {
        case 1:
            cadastrarVeiculo();
            break;
        case 2:
            removerVeiculo();
            break;
        case 3:
            buscarVeiculo();
            break;
        case 4:
            //consultarLocacoes();
            break;
        case 5: 
        	menuPrincipal();
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
    
    if(strcmp(login, "ADMIN") == 0 && strcmp(senha, "0000") == 0) {
        printf("\nLogin bem sucedido!\n");
        system("pause");
        system("cls");
        menuFuncionario();
    } else {
        system("cls");
        printf("Login ou senha inválidos.\n\n");
        loginFuncionario();
    }
}

void menuFuncionario(){
    int opcao;
    
    printf("******* Menu de Funcionário *******\n\n");
    
    printf("|1 - Cadastrar veiculo\n");
    printf("|2 - Remover veiculos\n");
    printf("|3 - Buscar veiculos\n");
    printf("|4 - Consultar locações\n");    
    printf("|5 - Voltar para o menu inicial\n");
    printf("Escolha uma opção [1-5]: ");
    scanf("%d", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}

bool modeloValido(char modelo[40]){
	if(strcmp(modelo, "Hatch") ==0 || strcmp(modelo, "Sedan") ==0 || strcmp(modelo, "SUV") ==0 || strcmp(modelo, "Picape") ==0){
		return true;
	}
	return false;
}

void cadastrarVeiculo(){
    if (totalVeiculos >= MAX_VEICULOS) {
        printf("Limite de veículos cadastrados atingido!\n\n");
        return;
    }
	
	fflush(stdin);
    printf("Informe o nome do carro: ");
    gets(veiculos->nome);
	
	printf("\n-> Hatch\n");
	printf("-> Sedan\n");
	printf("-> SUV\n");
	printf("-> Picape\n");
	printf("Escreva o modelo do carro: ");
    gets(veiculos->modelo);
    
    if(modeloValido(veiculos->modelo)){
    	printf("\nDigite o código para esse veículo: ");
    	scanf(" %d", &veiculos->codigo);

    	totalVeiculos++;
    	system("cls");
	
    	printf("**** CARRO CADASTRADO COM SUCESSO ****\n\n");

   	 	system("pause");
   		system("cls");
    	menuFuncionario();
	}
	
    system("cls");
    printf("Modelo de carro inválido! Tente novamente\n\n");
    return cadastrarVeiculo();
}

void removerVeiculo(){
	int opcao;
	int codigoCarro;
	char nomeCarro[40];
	bool carroEncontrado = false;
	
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }
    
    printf("Buscar veículo por: \n");
    printf("1. Código\n");
    printf("2. Nome\n");
    printf("Escolha uma opção: ");
    scanf(" %d", &opcao);
    
    switch(opcao){
    	case 1:
    		system("cls");
    		printf("Informe o código do veículo: ");
    		scanf(" %d", &codigoCarro);
    		
    		for (int i = 0; i < totalVeiculos; i++) {
            	if (veiculos[i].codigo == codigoCarro) {
	            	carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\nVeículo de codigo '%d' removido! \n\n", codigoCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
            	}
        	}
        	break;
        case 2:
        	system("cls");
    		printf("Informe o nome do veículo: ");
    		scanf(" %s", nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome)==0) {
    				carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\nVeículo '%s' removido! \n\n", nomeCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
				}
			}
			break;
		default:
			system("cls");
			printf("Opção Inválida!\n\n");
			return removerVeiculo();
	}

    if (!carroEncontrado){
        printf("\nVeículo não encontrado!\n");
	}

    system("pause");
    system("cls");
    menuFuncionario();
}

void buscarVeiculo(){
	int opcao;
	int codigoCarro;
	char nomeCarro[40];
	bool carroEncontrado = false;
	
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }

    printf("Buscar veículo por: \n");
    printf("1. Código\n");
    printf("2. Nome\n");
    printf("Escolha uma opção: ");
    scanf(" %d", &opcao);

    switch(opcao){
    	case 1:
        	system("cls");
    		printf("Informe o código do veículo: ");
    		scanf(" %d", &codigoCarro);

	        for (int i = 0; i < totalVeiculos; i++) {
	            if (veiculos[i].codigo == codigoCarro) {
	                carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Modelo: %s\n", veiculos[i].modelo);
	                printf("Código: %d\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
	            }
	    	}
	    	break;
	    case 2:
	    	system("cls");
    		printf("Informe o nome do veículo: ");
    		scanf(" %s", nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome)==0) {
    				carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Modelo: %s\n", veiculos[i].modelo);
	                printf("Código: %d\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
				}
			}
			break;
		default:
			system("cls");
			printf("Opção Inválida!\n\n");
			return buscarVeiculo();
		}
	
	if (!carroEncontrado){
        printf("\nVeículo não encontrado!\n");
	}
	
    system("pause");
    system("cls");
    menuFuncionario();
}