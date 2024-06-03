#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "menuFuncionario.h"
#include "menuCliente.h"

void loginFuncionario(){
    char login[10];
    char senha[10];
 
    fflush(stdin);
    printf("Insira o login: ");
    scanf(" %s", login);
    
    printf("\nInsira a senha: ");
    scanf(" %s", senha);
    
    if(strcmp(login, "ADMIN") == 0 && strcmp(senha, "0000") == 0){
        printf("\nLogin bem sucedido!\n");
        system("pause");
        system("cls");
        menuFuncionario();
    } else {
        system("cls");
        printf("Login ou senha inv�lidos.\n\n");
        loginFuncionario();
    }
}

bool categoriaInvalida(char categoria[10]){
	if(strcmp(categoria, "Hatch") !=0 && strcmp(categoria, "Sedan") !=0 && strcmp(categoria, "SUV") !=0 && strcmp(categoria, "Picape") !=0){
		return true;
	}
	return false;
}

void cadastrarVeiculo(){
    if (totalVeiculos >= MAX_VEICULOS) {
        printf("Limite de ve�culos cadastrados atingido!\n\n");
        return;
    }
	
	fflush(stdin);
    printf("Informe o nome do carro: ");
    gets(veiculos[totalVeiculos].nome);
	
	printf("\n-> Hatch\n");
	printf("-> Sedan\n");
	printf("-> SUV\n");
	printf("-> Picape\n");
	printf("Escreva a categoria do carro (Ex. Hatch): ");
    gets(veiculos[totalVeiculos].categoria);
    
    if(categoriaInvalida(veiculos[totalVeiculos].categoria)){
    	system("cls");
    	printf("Categoria de carro inv�lida! Tente novamente\n\n");
    	return cadastrarVeiculo();
	}
	
	printf("\nInforme o ano do carro: ");
	scanf(" %s", veiculos[totalVeiculos].ano);
	
	printf("\nInforme a quilometragem do carro (km): ");
	scanf(" %f", &veiculos[totalVeiculos].quilometragem);
	
	fflush(stdin);
	printf("\nInforme o valor da di�ria do carro (R$): ");
	scanf(" %f", &veiculos[totalVeiculos].valorDiaria);
	
	printf("\nDigite o c�digo para esse ve�culo: ");
    scanf(" %s", veiculos[totalVeiculos].codigo);
	
	
    totalVeiculos++;
    system("cls");
	
    printf("**** CARRO CADASTRADO COM SUCESSO ****\n\n");

   	system("pause");
   	system("cls");
    return menuFuncionario();
	
}

void removerVeiculo(){
	char opcao;
	char codigoCarro[10];
	char nomeCarro[40];
	bool carroEncontrado = false;
	
    if (totalVeiculos == 0) {
        printf("Nenhum ve�culo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }
    
    printf("Remover ve�culo por: \n");
    printf("1. C�digo\n");
    printf("2. Nome\n");
    printf("Escolha uma op��o: ");
    scanf(" %c", &opcao);
    
    switch(opcao){
    	case '1':
    		fflush(stdin);
    		system("cls");
    		printf("Informe o c�digo do ve�culo: ");
    		gets(codigoCarro);
    		
    		for (int i = 0; i < totalVeiculos; i++) {
            	if (strcmp(veiculos[i].codigo, codigoCarro)==0) {
	            	carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\nVe�culo de c�digo '%s' removido! \n\n", codigoCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
            	}
        	}
        	break;
        case '2':
        	fflush(stdin);
        	system("cls");
    		printf("Informe o nome do ve�culo: ");
    		gets(nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome) ==0) {
    				carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\nO ve�culo '%s' foi removido! \n\n", nomeCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
				}
			}
			break;
		default:
			system("cls");
			printf("Op��o Inv�lida!\n\n");
			return removerVeiculo();
	}

    if (!carroEncontrado){
        printf("\nVe�culo n�o encontrado!\n");
	}

    system("pause");
    system("cls");
    menuFuncionario();
}

void buscarVeiculo(){
	char opcao;
	char codigoCarro[10];
	char nomeCarro[40];
	bool carroEncontrado = false;
	
    if (totalVeiculos == 0) {
        printf("Nenhum ve�culo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }

    printf("Buscar ve�culo por: \n");
    printf("1. C�digo\n");
    printf("2. Nome\n");
    printf("Escolha uma op��o: ");
    scanf(" %c", &opcao);

    switch(opcao){
    	case '1':
    		fflush(stdin);
        	system("cls");
    		printf("Informe o c�digo do ve�culo: ");
    		gets(codigoCarro);

	        for (int i = 0; i < totalVeiculos; i++) {
	            if (strcmp(veiculos[i].codigo, codigoCarro) ==0) {
	                carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("Ano: %s\n", veiculos[i].ano);
	                printf("Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
	                printf("Valor da di�ria: %.fR$\n", veiculos[i].valorDiaria);
	                printf("C�digo: %s\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
	            }
	    	}
	    	break;
	    case '2':
	    	fflush(stdin);
	    	system("cls");
    		printf("Informe o nome do ve�culo: ");
    		gets(nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome)==0) {
    				carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("Ano: %s\n", veiculos[i].ano);
	                printf("Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
	                printf("Valor da di�ria: %.fR$\n", veiculos[i].valorDiaria);
	                printf("C�digo: %s\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
				}
			}
			break;
		default:
			system("cls");
			printf("Op��o Inv�lida!\n\n");
			return buscarVeiculo();
		}
	
	if (!carroEncontrado){
        printf("\nVe�culo n�o encontrado!\n");
	}
	
    system("pause");
    system("cls");
    menuFuncionario();
}

void consultarLocacoes(){
	//A fazer
}

void buscarUsuario() {
	char opcao;
    char cpfCnpj[18];
    char usuario[20];
    bool encontrado = false;

    fflush(stdin);
    printf("Fazer pesquisa por:\n");
    printf("1 - CPF\n");
    printf("2 - Usu�rio\n");
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
	            printf("Usu�rio encontrado.\n\n");
	
	            printf("Nome: %s\n", info[i].nomeCliente);
	            printf("Data de nascimento: %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
	            printf("CPF: %s\n", info[i].cpfCnpj);
	            
	            if(strcmp(info[i].carroAlugado, "") ==0){
	            	printf("Carro alugado: Nenhum\n");
				}else{
					printf("Carro alugado: %s\n", info[i].carroAlugado);
				}
				
	            printf("Usu�rio de Login: %s\n\n", info[i].usuario);
	            
	            system("pause");
	            system("cls");
				return menuFuncionario();
	        }
	    }
	}else if(opcao == '2'){
		system("cls");
		fflush(stdin);
		printf("Informe o usu�rio: ");
    	gets(usuario);
    	
    	for (int i = 0; i < codigoCliente; i++) {
	        if (strcmp(usuario, info[i].usuario) == 0) {
	        	encontrado = true;
	            system("cls");
	            printf("Usu�rio encontrado.\n\n");
	
	            printf("Nome: %s\n", info[i].nomeCliente);
	            printf("Data de nascimento: %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
	            printf("CPF: %s\n", info[i].cpfCnpj);
	            
	            if(strcmp(info[i].carroAlugado, "") ==0){
	            	printf("Carro alugado: Nenhum\n");
				}else{
					printf("Carro alugado: %s\n", info[i].carroAlugado);
				}
				
	            printf("Usu�rio de Login: %s\n\n", info[i].usuario);
	            
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
		printf("Op��o inv�lida!\n\n");
		return buscarUsuario();
	}
	
	if(! encontrado){
		system("cls");
    	printf("Usu�rio n�o encontrado.\n\n");
    	return menuFuncionario();
	}
}

void controleMenuFuncionario(char opcao){
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
        	buscarUsuario();
        	break;
        case '6':
        	menuPrincipal();
        	break;
        default:
            printf("Escolha uma op��o v�lida!\n\n");
            menuFuncionario();
    }
}

void menuFuncionario(){
    char opcao;
    
    printf("******* Menu de Funcion�rio *******\n\n");
    
    printf("|1 - Cadastrar veiculo\n");
    printf("|2 - Remover veiculos\n");
    printf("|3 - Buscar veiculos\n");
    printf("|4 - Consultar loca��es\n");    
    printf("|5 - Buscar usu�rio\n");
    printf("|6 - Voltar para o menu inicial\n");
    printf("Escolha uma op��o [1-6]: ");
    scanf(" %c", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}