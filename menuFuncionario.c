#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "menuFuncionario.h"
#include "menuCliente.h"

void printBanner3() {
    printf("L       OOO    CCCC    A     N   N    A     I\n");
    printf("L      O   O  C       A A    NN  N   A A    I\n");
    printf("L      O   O  C      A   A   N N N  A   A   I\n");
    printf("L      O   O  C      AAAAA   N  NN  AAAAA   I\n");
    printf("L      O   O  C      A   A   N   N  A   A   I\n");
    printf("LLLLL   OOO    CCCC  A   A   N   N  A   A   I\n");
}

void loginFuncionario(){
    char login[10];
    char senha[10];
    
    printBanner3();
    printf("\n \n");
 
    fflush(stdin);
    printf("Insira o login: ");
    scanf(" %s", login);
    
    printf("\nInsira a senha: ");
    scanf(" %s", senha);
    
    if(strcmp(login, "ADMIN") == 0 && strcmp(senha, "0000") == 0){
        printf("\033[32m\nLogin bem sucedido!\n");
        system("pause");
        system("cls");
        menuFuncionario();
    } else {
        system("cls");
        printf("\033[31mLogin ou senha inválidos.\n\n");
        loginFuncionario();
    }
}
void liberarVeiculo(char codigo[]) {
	
	printBanner3();
    printf("\n \n");
    
    for (int i = 0; i < totalVeiculos; i++) {
        if (strcmp(veiculos[i].codigo, codigo) == 0) {
            if (!veiculos[i].disponivel) {
                veiculos[i].disponivel = true;
                printf("\033[32mVeículo %s liberado com sucesso.\n\n", veiculos[i].nomeVeiculo);
                
                totalLocacoes--;
    			strcpy(info[clienteAtual].carroAlugado, "");
    			veiculos[clienteAtual].disponivel = true;
                
                system("pause");
                system("cls");
                menuFuncionario();
            } else {
                printf("\033[32mO veículo %s já está disponível.\n\n", veiculos[i].nomeVeiculo);
                system("pause");
                system("cls");
                menuFuncionario();
            }
        }
    }
    printf("\033[31mVeículo com código %s não encontrado.\n\n", codigo);
    system("pause");
    system("cls");
    menuFuncionario();
}

void auxLiberarveiculo(){
	char codigo[10];
	
	printBanner3();
    printf("\n \n");
	
	printf("Digite o código do veículo a ser liberado: ");
    scanf(" %s", codigo);
    liberarVeiculo(codigo);
}

bool categoriaInvalida(char categoria[10]){
    for (int i = 0; categoria[i] != '\0'; i++) {
        categoria[i] = tolower(categoria[i]);
    }

    if(strcmp(categoria, "hatch") != 0 && 
       strcmp(categoria, "sedan") != 0 && 
       strcmp(categoria, "suv") != 0 && 
       strcmp(categoria, "picape") != 0) {
        return true;
    }
    return false;
}

bool codigoVeiculoInvalido(char codigo[10]){
	for(int i = 0; i < totalVeiculos; i++){
		if(strcmp(codigo, veiculos[i].codigo) ==0){
			return true;
		}else{
			return false;
		}
	}
}

void cadastrarVeiculo(){
	char categoria[15];
	
	printBanner3();
    printf("\n \n");
	
    if (totalVeiculos >= MAX_VEICULOS) {
        printf("\033[31mLimite de veículos cadastrados atingido!\n\n");
        return;
    }
	
	fflush(stdin);
    printf("Informe o nome do carro: ");
    gets(veiculos[totalVeiculos].nomeVeiculo);
	
	printf("\n-> Hatch\n");
	printf("-> Sedan\n");
	printf("-> SUV\n");
	printf("-> Picape\n");
	printf("Escreva a categoria do carro (Ex. Hatch): ");
	gets(veiculos[totalVeiculos].categoria);
    
    
    if(categoriaInvalida(veiculos[totalVeiculos].categoria)){
    	system("cls");
    	printf("\033[31mErro: Categoria de carro inválida! Tente novamente\n\n");
    	return cadastrarVeiculo();
	}
	
	printf("\nInforme o ano do carro: ");
	scanf(" %s", veiculos[totalVeiculos].ano);
	
	printf("\nInforme a quilometragem do carro (km): ");
	scanf(" %f", &veiculos[totalVeiculos].quilometragem);
	
	fflush(stdin);
	printf("\nInforme o valor da diária do carro (R$): ");
	scanf(" %f", &veiculos[totalVeiculos].valorDiaria);
	
	printf("\nDigite o código para esse veículo: ");
    scanf(" %s", veiculos[totalVeiculos].codigo);
    
    if(codigoVeiculoInvalido(veiculos[totalVeiculos].codigo)){
    	system("cls");
    	printf("\033[31mErro: Já existe um veículo com esse código!\n\n");
    	return menuFuncionario();
	}
	
	FILE *file = fopen("CarrosDisponiveis.txt", "a");
    if (file == NULL) {
        printf("\033[31mErro ao abrir o arquivo!\n");
        return;
    }
    
    for (int i = 0; i < totalVeiculos; i++) {
        fprintf(file, "Carro %d\n", i+1);
        fprintf(file, "Nome: %s\n", veiculos[i].nomeVeiculo);
        fprintf(file, "Categoria: %s\n", veiculos[i].categoria);
        fprintf(file, "Ano: %s\n", veiculos[i].ano);
        fprintf(file, "Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
        fprintf(file, "Valor da diária: %.2fR$\n", veiculos[i].valorDiaria);
        fprintf(file, "------------------\n\n");
    }
    
    fclose(file);

	
	veiculos[totalVeiculos].disponivel = true;
    totalVeiculos++;
    system("cls");
	
    printf("**** Carro cadastrado com sucesso ****\n\n");

   	system("pause");
   	system("cls");
    return menuFuncionario();
	
}

void removerVeiculo(){
	char opcao;
	char codigoCarro[10];
	char nomeCarro[40];
	bool carroEncontrado = false;
	
	printBanner3();
    printf("\n \n");
	
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }
    
    printf("Remover veículo por: \n");
    printf("|1. Código\n");
    printf("|2. Nome\n");
    printf("Escolha uma opção [1-2]: ");
    scanf(" %c", &opcao);
    
    switch(opcao){
    	case '1':
    		fflush(stdin);
    		system("cls");
    		printf("Informe o código do veículo: ");
    		gets(codigoCarro);
    		
    		for (int i = 0; i < totalVeiculos; i++) {
            	if (strcmp(veiculos[i].codigo, codigoCarro)==0) {
	            	carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\033[32m\nVeículo de código '%s' removido! \n\n", codigoCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
            	}
        	}
        	break;
        case '2':
        	fflush(stdin);
        	system("cls");
    		printf("Informe o nome do veículo: ");
    		gets(nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nomeVeiculo) ==0) {
    				carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\033[31m\nO veículo '%s' foi removido! \n\n", nomeCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
				}
			}
			break;
		default:
			system("cls");
			printf("\033[31mOpção Inválida!\n\n");
			return removerVeiculo();
	}

    if (!carroEncontrado){
        printf("\033[31m\nVeículo não encontrado!\n");
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
	
	printBanner3();
    printf("\n \n");
	
    if (totalVeiculos == 0) {
        printf("\033[31mNenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }

    printf("Buscar veículo por: \n");
    printf("|1. Código\n");
    printf("|2. Nome\n");
    printf("Escolha uma opção [1-2]: ");
    scanf(" %c", &opcao);

    switch(opcao){
    	case '1':
    		fflush(stdin);
        	system("cls");
    		printf("Informe o código do veículo: ");
    		gets(codigoCarro);

	        for (int i = 0; i < totalVeiculos; i++) {
	            if (strcmp(veiculos[i].codigo, codigoCarro) ==0) {
	                carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nomeVeiculo);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("Ano: %s\n", veiculos[i].ano);
	                printf("Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
	                printf("Valor da diária: %.fR$\n", veiculos[i].valorDiaria);
	                printf("Código: %s\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
	            }
	    	}
	    	break;
	    case '2':
	    	fflush(stdin);
	    	system("cls");
    		printf("Informe o nome do veículo: ");
    		gets(nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nomeVeiculo)==0) {
    				carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nomeVeiculo);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("Ano: %s\n", veiculos[i].ano);
	                printf("Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
	                printf("Valor da diária: %.fR$\n", veiculos[i].valorDiaria);
	                printf("Código: %s\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
				}
			}
			break;
		default:
			system("cls");
			printf("\033[31mOpção Inválida!\n\n");
			return buscarVeiculo();
		}
	
	if (!carroEncontrado){
        printf("\033[31m\nVeículo não encontrado!\n");
	}
	
    system("pause");
    system("cls");
    menuFuncionario();
}

void consultarLocacoes(){
	
	printBanner3();
    printf("\n \n");
    
	if (totalLocacoes == 0) {
        printf("\033[31mNenhuma locação registrada!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }

    printf("**** LISTA DE LOCAÇÕES ****\n\n");
    for (int i = 0; i < totalLocacoes; i++) {
    	printf("Cliente nº %d\n", i+1);
        printf("Nome: %s\n", info[clienteAtual].nomeCliente);
        printf("Carro: %s\n", info[clienteAtual].carroAlugado);
        printf("Dias Reservados: %d\n", veiculos[clienteAtual].dias);
        printf("--------------------\n\n");
    }
    
    FILE *file = fopen("Locações consultadas.txt", "a");
    if (file == NULL){
    	printf("\033[31mErro ao abrir o arquivo!\n");
    	return;
	}
		for (int i = 0; i < totalLocacoes; i++){
		
		fprintf(file, "Cliente nº %d\n", i+1);
        fprintf(file, "Nome: %s\n", info[clienteAtual].nomeCliente);
        fprintf(file, "Carro: %s\n", info[clienteAtual].carroAlugado);
        fprintf(file, "Dias Reservados: %d\n", veiculos[clienteAtual].dias);
        fprintf(file, "--------------------\n\n");
    }
        
        fclose(file);
	
	
    
    system("pause");
    system("cls");
    return menuFuncionario();
}

void buscarUsuario() {
	char opcao;
    char cpfCnpj[18];
    char usuario[20];
    bool encontrado = false;
    
    printBanner3();
    printf("\n \n");

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
	            printf("Data de nascimento: %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
	            printf("CPF: %s\n", info[i].cpfCnpj);
	            
	            if(strcmp(info[i].carroAlugado, "") ==0){
	            	printf("Carro alugado: Nenhum\n");
				}else{
					printf("Carro alugado: %s\n", info[i].carroAlugado);
				}
				
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
	            printf("Data de nascimento: %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
	            printf("CPF: %s\n", info[i].cpfCnpj);
	            
	            if(strcmp(info[i].carroAlugado, "") ==0){
	            	printf("Carro alugado: Nenhum\n");
				}else{
					printf("Carro alugado: %s\n", info[i].carroAlugado);
				}
				
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
		printf("\033[31mOpção inválida!\n\n");
		return buscarUsuario();
	}
	
	if(! encontrado){
		system("cls");
    	printf("\033[31mUsuário não encontrado.\n\n");
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
    		auxLiberarveiculo();
    		break;
        case '4':
            buscarVeiculo();
            break;
        case '5':
            consultarLocacoes();
            break;
        case '6': 
        	buscarUsuario();
        	break;
        case '7':
        	menuPrincipal();
        	break;

        default:
            printf("\033[31mEscolha uma opção válida!\n\n");
            menuFuncionario();
    }
}

void menuFuncionario(){
    char opcao;
    
    printBanner3();
    printf("\n \n");
    
    printf("******* Menu de Funcionário *******\n\n");
    
    printf("|1 - Cadastrar veiculo\n");
    printf("|2 - Remover veiculos\n");
    printf("|3 - Liberar veículo\n");
    printf("|4 - Buscar veiculos\n");
    printf("|5 - Consultar locações\n");    
    printf("|6 - Buscar usuário\n");
    printf("|7 - Voltar para o menu inicial\n");
    printf("Escolha uma opção [1-7]: ");
    scanf(" %c", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}
