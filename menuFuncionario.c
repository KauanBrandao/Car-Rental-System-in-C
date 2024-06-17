#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "menuFuncionario.h"
#include "menuCliente.h"

void loginFuncionario(){
    char login[10];
    char senha[10];
    
    printBanner();
 
    fflush(stdin);
    printf("\033[37mInsira o login: ");
    scanf(" %s", login);
    
    printf("\033[37m\nInsira a senha: ");
    scanf(" %s", senha);
    
    if(strcmp(login, "ADMIN") == 0 && strcmp(senha, "0000") == 0){
        printf("\033[32m\nLogin bem sucedido!\n");
        system("pause");
        system("cls");
        menuFuncionario();
    }
    if (loginInvalido(login, senha)) {
    	char opcao;
        system("cls");
        printf("\033[31mUsuário ou senha inválidos!\n");
        printf("\033[33mDeseja tentar novamente? [S/N]: ");
        scanf(" %c", &opcao);
        system("cls");
        
        if(opcao == 'S' || opcao == 's'){
        	system("cls");
        	return loginCliente();
		}else if(opcao == 'N' || opcao == 'n'){
			system("cls");
			return menuPrincipal();
		} else {
			system("cls");
			printf("\033[31mOpção Inválida!\n\n");
			return menuPrincipal();		
		}
    }
}
void liberarVeiculo(char codigo[]) {
    for (int i = 0; i < totalVeiculos; i++) {
        if (strcmp(veiculos[i].codigo, codigo) == 0) {
            if (!veiculos[i].disponivel) {
            	system("cls");
                veiculos[i].disponivel = true;
                printf("\033[32mVeículo %s liberado com sucesso.\n\n", veiculos[i].nomeVeiculo);
                
                totalLocacoes--;
    			strcpy(info[clienteAtual].carroAlugado, "");
    			veiculos[clienteAtual].disponivel = true;
                
                system("pause");
                system("cls");
                menuFuncionario();
            } else {
            	system("cls");
                printf("\033[32mO veículo %s já está disponível.\n\n", veiculos[i].nomeVeiculo);
                system("pause");
                system("cls");
                menuFuncionario();
            }
        }
    }
    system("cls");
    printf("\033[31mVeículo com código %s não encontrado.\n\n", codigo);
    system("pause");
    system("cls");
    menuFuncionario();
}

void auxLiberarveiculo(){
	char codigo[10];
	
	printBanner();
	
	printf("\033[37mDigite o código do veículo a ser liberado: ");
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

void carregarVeiculos() {
    FILE *file = fopen("CarrosDisponiveis.txt", "r");

    totalVeiculos = 0;
    while (fscanf(file, "Carro %*d\n") != EOF) {
        fscanf(file, "Nome: %[^\n]\n", veiculos[totalVeiculos].nomeVeiculo);
        fscanf(file, "Categoria: %[^\n]\n", veiculos[totalVeiculos].categoria);
        fscanf(file, "Ano: %[^\n]\n", veiculos[totalVeiculos].ano);
        fscanf(file, "Quilometragem: %fkm\n", &veiculos[totalVeiculos].quilometragem);
        fscanf(file, "Valor da diária: %fR$\n", &veiculos[totalVeiculos].valorDiaria);
        fscanf(file, "Valor da diária: %fR$\n", &veiculos[totalVeiculos].valorDiaria);
        fscanf(file, "Código: %[^\n]\n", veiculos[totalVeiculos].codigo);
        fscanf(file, "------------------\n\n");

        veiculos[totalVeiculos].disponivel = true;
        totalVeiculos++;
    }

    fclose(file);
}

void cadastrarVeiculo(){
	char categoria[15];
	
	printBanner();
	
    if (totalVeiculos >= MAX_VEICULOS) {
        printf("\033[31mLimite de veículos cadastrados atingido!\n\n");
        return;
    }
	
	printf("\033[37mDigite o código para esse veículo: ");
    scanf(" %s", veiculos[totalVeiculos].codigo);
    
    if(codigoVeiculoInvalido(veiculos[totalVeiculos].codigo)){
    	system("cls");
    	printf("\033[31mErro: Já existe um veículo com esse código!\n\n");
    	return menuFuncionario();
	}
	
	fflush(stdin);
    printf("\033[37m\nInforme o nome do carro: ");
    gets(veiculos[totalVeiculos].nomeVeiculo);
    for (int i = 0; veiculos[totalVeiculos].nomeVeiculo[i]; i++) {
        veiculos[totalVeiculos].nomeVeiculo[i] = tolower((unsigned char)veiculos[totalVeiculos].nomeVeiculo[i]);
    }
	
	printf("\033[37m\n-> Hatch\n");
	printf("\033[37m-> Sedan\n");
	printf("\033[37m-> SUV\n");
	printf("\033[37m-> Picape\n");
	printf("\033[37mEscreva a categoria do carro (Ex. Hatch): ");
	gets(veiculos[totalVeiculos].categoria);
    
    if(categoriaInvalida(veiculos[totalVeiculos].categoria)){
    	system("cls");
    	printf("\033[31mErro: Categoria de carro inválida! Tente novamente\n\n");
    	return cadastrarVeiculo();
	}
	
	printf("\033[37m\nInforme o ano do carro: ");
	scanf(" %s", veiculos[totalVeiculos].ano);
	
	printf("\033[37m\nInforme a quilometragem do carro (km): ");
	scanf(" %f", &veiculos[totalVeiculos].quilometragem);
	
	fflush(stdin);
	printf("\033[37m\nInforme o valor da diária do carro (R$): ");
	scanf(" %f", &veiculos[totalVeiculos].valorDiaria);
	
	veiculos[totalVeiculos].disponivel = true;
	totalVeiculos++;
	
    system("cls");
	
    printf("\033[32m** Carro cadastrado com sucesso **\n\n");
	
	FILE *file = fopen("CarrosDisponiveis.txt", "a");
	
    fprintf(file, "Carro %d\n", totalVeiculos);
    fprintf(file, "Nome: %s\n", veiculos[totalVeiculos-1].nomeVeiculo);
    fprintf(file, "Categoria: %s\n", veiculos[totalVeiculos-1].categoria);
    fprintf(file, "Ano: %s\n", veiculos[totalVeiculos-1].ano);
    fprintf(file, "Quilometragem: %.3fkm\n", veiculos[totalVeiculos-1].quilometragem);
    fprintf(file, "Valor da diária: %.2fR$\n", veiculos[totalVeiculos-1].valorDiaria);
    fprintf(file, "Código: %s\n", veiculos[totalVeiculos-1].codigo);
    fprintf(file, "------------------\n\n");
    
    fclose(file);
    
    system("pause");
   	system("cls");
    return menuFuncionario();
}

void removerVeiculo(){
	char opcao;
	char codigoCarro[10];
	char nomeCarro[40];
	bool carroEncontrado = false;
	
	printBanner();
	
    if (totalVeiculos == 0) {
        printf("\033[31mNenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }
    
    printf("\033[37mRemover veículo por: \n");
    printf("\033[37m|1. Código\n");
    printf("\033[37m|2. Nome\n");
    printf("\033[37mEscolha uma opção [1-2]: ");
    scanf(" %c", &opcao);
    
    switch(opcao){
    	case '1':
    		fflush(stdin);
    		system("cls");
    		printf("\033[37mInforme o código do veículo: ");
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
    		printf("\033[37mInforme o nome do veículo: ");
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
	
	printBanner();
	
    if (totalVeiculos == 0) {
        printf("\033[31mNenhum veículo cadastrado!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }

    printf("\033[37mBuscar veículo por: \n");
    printf("\033[37m|1. Código\n");
    printf("\033[37m|2. Nome\n");
    printf("\033[33mEscolha uma opção [1-2]: ");
    scanf(" %c", &opcao);

    switch(opcao){
    	case '1':
    		fflush(stdin);
        	system("cls");
    		printf("\033[37mInforme o código do veículo: ");
    		gets(codigoCarro);
    		
    		for (int i = 0; codigoCarro[i]; i++) {
                codigoCarro[i] = tolower(codigoCarro[i]);
            }

	        for (int i = 0; i < totalVeiculos; i++) {
	            if (strcmp(veiculos[i].codigo, codigoCarro) ==0) {
	            	system("cls");
	                carroEncontrado = true;
	                
	                printf("\033[32mVeículo '%s' encontrado!\n", veiculos[i].nomeVeiculo);
	                printf("\033[37m\nNome: %s\n", veiculos[i].nomeVeiculo);
	                printf("\033[37mCategoria: %s\n", veiculos[i].categoria);
	                printf("\033[37mAno: %s\n", veiculos[i].ano);
	                printf("\033[37mQuilometragem: %.3fkm\n", veiculos[i].quilometragem);
	                printf("\033[37mValor da diária: %.fR$\n", veiculos[i].valorDiaria);
	                printf("\033[37mCódigo: %s\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
	            }
	    	}
	    	break;
	    case '2':
	    	fflush(stdin);
	    	system("cls");
    		printf("\033[37mInforme o nome do veículo: ");
    		gets(nomeCarro);
    		
    		for (int i = 0; nomeCarro[i]; i++) {
                nomeCarro[i] = tolower(nomeCarro[i]);
            }
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nomeVeiculo)==0) {
    				system("cls");
    				carroEncontrado = true;
	                
	                printf("\033[32mVeículo '%s' encontrado!\n", veiculos[i].nomeVeiculo);
	                printf("\033[37m\nNome: %s\n", veiculos[i].nomeVeiculo);
	                printf("\033[37mCategoria: %s\n", veiculos[i].categoria);
	                printf("\033[37mAno: %s\n", veiculos[i].ano);
	                printf("\033[37mQuilometragem: %.3fkm\n", veiculos[i].quilometragem);
	                printf("\033[37mValor da diária: %.fR$\n", veiculos[i].valorDiaria);
	                printf("\033[37mCódigo: %s\n\n", veiculos[i].codigo);
	                
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
	printBanner();
    
	if (totalLocacoes == 0) {
        printf("\033[31mNenhuma locação registrada!\n\n");
        system("pause");
        system("cls");
        return menuFuncionario();
    }

    printf("\033[37m**** LISTA DE LOCAÇÕES ****\n\n");
    for (int i = 0; i < totalLocacoes; i++) {
    	printf("\033[37mCliente nº %d\n", i+1);
        printf("\033[37mNome: %s\n", info[clienteAtual].nomeCliente);
        printf("\033[37mCarro: %s\n", info[clienteAtual].carroAlugado);
        printf("\033[37mDias Reservados: %d\n", veiculos[clienteAtual].dias);
        printf("\033[37m--------------------\n\n");
    }
	
    system("pause");
    system("cls");
    return menuFuncionario();
}

void buscarUsuario() {
	char opcao;
    char cpfCnpj[18];
    char usuario[20];
    bool encontrado = false;
    
    printBanner();

    fflush(stdin);
    printf("\033[37mFazer pesquisa por:\n");
    printf("\033[37m1 - CPF\n");
    printf("\033[37m2 - Usuário\n");
    printf("\033[37m3 - Voltar\n");
    printf("\033[37mEscolha [1-3]: ");
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
	            printf("\033[32mUsuário encontrado.\n\n");
	
	            printf("\033[37mNome: %s\n", info[i].nomeCliente);
	            printf("\033[37mData de nascimento: %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
	            printf("\033[37mCPF: %s\n", info[i].cpfCnpj);
	            
	            if(strcmp(info[i].carroAlugado, "") ==0){
	            	printf("\033[37mCarro alugado: Nenhum\n");
				}else{
					printf("\033[37mCarro alugado: %s\n", info[i].carroAlugado);
				}
				
	            printf("\033[37mUsuário de Login: %s\n\n", info[i].usuario);
	            
	            system("pause");
	            system("cls");
				return menuFuncionario();
	        }
	    }
	}else if(opcao == '2'){
		system("cls");
		fflush(stdin);
		printf("\033[37mInforme o usuário: ");
    	gets(usuario);
    	
    	for (int i = 0; i < codigoCliente; i++) {
	        if (strcmp(usuario, info[i].usuario) == 0) {
	        	encontrado = true;
	            system("cls");
	            printf("\033[32mUsuário encontrado.\n\n");
	
	            printf("\033[37mNome: %s\n", info[i].nomeCliente);
	            printf("\033[37mData de nascimento: %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
	            printf("\033[37mCPF: %s\n", info[i].cpfCnpj);
	            
	            if(strcmp(info[i].carroAlugado, "") ==0){
	            	printf("\033[37mCarro alugado: Nenhum\n");
				}else{
					printf("\033[37mCarro alugado: %s\n", info[i].carroAlugado);
				}
				
	            printf("\033[37mUsuário de Login: %s\n\n", info[i].usuario);
	            
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
    
    printBanner();
    
    printf("\033[37m******* Menu de Funcionário *******\n\n");
    
    printf("\033[37m|1 - Cadastrar veiculo\n");
    printf("\033[37m|2 - Remover veiculos\n");
    printf("\033[37m|3 - Liberar veículo\n");
    printf("\033[37m|4 - Buscar veiculos\n");
    printf("\033[37m|5 - Consultar locações\n");    
    printf("\033[37m|6 - Buscar usuário\n");
    printf("\033[37m|7 - Voltar para o menu inicial\n");
    printf("\033[33mEscolha uma opção [1-7]: ");
    scanf(" %c", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}