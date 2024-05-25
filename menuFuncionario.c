#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "menuFuncionario.h"
#include "menuCliente.h"

extern void menuPrincipal();

void menuFuncionario();
void cadastrarVeiculo();
void removerVeiculo();
void buscarVeiculo();

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

void buscarUsuario() {
	char opcao;
    char cpfCnpj[18];
    char usuario[20];
    bool encontrado = false;

    fflush(stdin);
    printf("Fazer pesquisa por:\n");
    printf("1 - CPF\n");
    printf("2 - Usuário\n");
    printf("3 - Voltar\n");
    printf("Escolha [1-3]: ");
    scanf(" %c", &opcao);
    
    if(opcao == '1'){
    	system("cls");
    	fflush(stdin);
    	printf("Informe o CPF/CNPJ: ");
    	gets(cpfCnpj);
    	
    	for (int i = 0; i < codigoCliente; i++) {
	        if (strcmp(cpfCnpj, info[i].cpfCnpj) == 0) {
	        	encontrado = true;
	            system("cls");
	            printf("Usuário encontrado.\n\n");
	
	            printf("Nome: %s\n", info[i].nomeCliente);
	            printf("Idade: %d\n", info[i].idade);
	            printf("CPF: %s\n", info[i].cpfCnpj);
	            printf("Usuário de Login: %s\n\n", info[i].usuario);
	            
	            system("pause");
	            system("cls");
				return menuFuncionario();
	        }
	    }
	}else if(opcao == '2'){
		system("cls");
		fflush(stdin);
		printf("Informe o usuário: ");
    	gets(usuario);
    	
    	for (int i = 0; i < codigoCliente; i++) {
	        if (strcmp(usuario, info[i].usuario) == 0) {
	        	encontrado = true;
	            system("cls");
	            printf("Usuário encontrado.\n\n");
	
	            printf("Nome: %s\n", info[i].nomeCliente);
	            printf("Idade: %d\n", info[i].idade);
	            printf("CPF: %s\n", info[i].cpfCnpj);
	            printf("Usuário de Login: %s\n\n", info[i].usuario);
	            
	            system("pause");
	            system("cls");
				return menuFuncionario();
	        }
	    }
	}else if(opcao == '3'){
		system("cls");
		return menuFuncionario();
	}else{
		system("cls");
		printf("Opção inválida!\n\n");
		return buscarUsuario();
	}
	
	if(! encontrado){
		system("cls");
    	printf("Usuário não encontrado.\n\n");
    	return menuFuncionario();
	}
}

void controleMenuFuncionario(int opcao){
    switch(opcao) {
        case '1':
            cadastrarVeiculo();
            break;
        case '2':
            removerVeiculo();
            break;
        case '3':
            buscarVeiculo();
            break;
        case '4':
            //consultarLocacoes();
            break;
        case '5': 
        	menuPrincipal();
        	break;
        case '6':
        	buscarUsuario();
        	break;
        default:
            printf("Escolha uma opção válida!\n\n");
            menuFuncionario();
    }
}

void menuFuncionario(){
    char opcao;
    
    printf("******* Menu de Funcionário *******\n\n");
    
    printf("|1 - Cadastrar veiculo\n");
    printf("|2 - Remover veiculos\n");
    printf("|3 - Buscar veiculos\n");
    printf("|4 - Consultar locações\n");    
    printf("|5 - Voltar para o menu inicial\n");
    printf("|6 - Buscar usuário\n");
    printf("Escolha uma opção [1-6]: ");
    scanf(" %c", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}

bool modeloValido(char categoria[40]){
	if(strcmp(categoria, "Hatch") ==0 || strcmp(categoria, "Sedan") ==0 || strcmp(categoria, "SUV") ==0 || strcmp(categoria, "Picape") ==0){
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
    gets(veiculos[totalVeiculos].nome);
	
	printf("\n-> Hatch\n");
	printf("-> Sedan\n");
	printf("-> SUV\n");
	printf("-> Picape\n");
	printf("Escreva a categoria do carro: ");
    gets(veiculos[totalVeiculos].categoria);
    
    if(modeloValido(veiculos->categoria)){
    	printf("\nDigite o código para esse veículo: ");
    	scanf(" %d", &veiculos[totalVeiculos].codigo);

    	totalVeiculos++;
    	system("cls");
	
    	printf("**** CARRO CADASTRADO COM SUCESSO ****\n\n");

   	 	system("pause");
   		system("cls");
    	return menuFuncionario();
	}
	
    system("cls");
    printf("Modelo de carro inválido! Tente novamente\n\n");
    return cadastrarVeiculo();
}

void removerVeiculo(){
	char opcao;
	int codigoCarro;
	char nomeCarro[40];
	bool carroEncontrado = false;
	
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }
    
    printf("Remover veículo por: \n");
    printf("1. Código\n");
    printf("2. Nome\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &opcao);
    
    switch(opcao){
    	case '1':
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
        			printf("\nVeículo de código '%d' removido! \n\n", codigoCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
            	}
        	}
        	break;
        case '2':
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
	char opcao;
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
    scanf(" %c", &opcao);

    switch(opcao){
    	case '1':
        	system("cls");
    		printf("Informe o código do veículo: ");
    		scanf(" %d", &codigoCarro);

	        for (int i = 0; i < totalVeiculos; i++) {
	            if (veiculos[i].codigo == codigoCarro) {
	                carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("Código: %d\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
	            }
	    	}
	    	break;
	    case '2':
	    	system("cls");
    		printf("Informe o nome do veículo: ");
    		scanf(" %s", nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome)==0) {
    				carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Categoria: %s\n", veiculos[i].categoria);
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