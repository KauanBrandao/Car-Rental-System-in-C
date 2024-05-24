#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VEICULOS 100

extern void menuPrincipal();

void menuFuncionario();
void cadastrarVeiculo();
void removerVeiculo();
void buscarVeiculo();

struct Veiculo{
    char nome[40];
    char categoria[15];
    int codigo;
} veiculos[MAX_VEICULOS];

int totalVeiculos = 0;

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
        printf("Login ou senha inv�lidos.\n\n");
        loginFuncionario();
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
    printf("|5 - Voltar para o menu inicial\n");
    printf("Escolha uma op��o [1-5]: ");
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
	printf("Escreva a categoria do carro: ");
    gets(veiculos->categoria);
    
    if(modeloValido(veiculos->categoria)){
    	printf("\nDigite o c�digo para esse ve�culo: ");
    	scanf(" %d", &veiculos[totalVeiculos].codigo);

    	totalVeiculos++;
    	system("cls");
	
    	printf("**** CARRO CADASTRADO COM SUCESSO ****\n\n");

   	 	system("pause");
   		system("cls");
    	return menuFuncionario();
	}
	
    system("cls");
    printf("Modelo de carro inv�lido! Tente novamente\n\n");
    return cadastrarVeiculo();
}

void removerVeiculo(){
	char opcao;
	int codigoCarro;
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
    		system("cls");
    		printf("Informe o c�digo do ve�culo: ");
    		scanf(" %d", &codigoCarro);
    		
    		for (int i = 0; i < totalVeiculos; i++) {
            	if (veiculos[i].codigo == codigoCarro) {
	            	carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\nVe�culo de codigo '%d' removido! \n\n", codigoCarro);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
            	}
        	}
        	break;
        case '2':
        	system("cls");
    		printf("Informe o nome do ve�culo: ");
    		scanf(" %s", nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome)==0) {
    				carroEncontrado = true;
	                
	                for (int i = carroEncontrado; i < totalVeiculos - 1; i++) {
           				veiculos[i] = veiculos[i + 1];
        			}
        			totalVeiculos--;
        			printf("\nVe�culo '%s' removido! \n\n", nomeCarro);
	                
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
	int codigoCarro;
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
        	system("cls");
    		printf("Informe o c�digo do ve�culo: ");
    		scanf(" %d", &codigoCarro);

	        for (int i = 0; i < totalVeiculos; i++) {
	            if (veiculos[i].codigo == codigoCarro) {
	                carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("C�digo: %d\n\n", veiculos[i].codigo);
	                
	                system("pause");
	                system("cls");
	                return menuFuncionario();
	            }
	    	}
	    	break;
	    case '2':
	    	system("cls");
    		printf("Informe o nome do ve�culo: ");
    		scanf(" %s", nomeCarro);
    		
    		for(int i = 0; i < totalVeiculos; i++){
    			if(strcmp(nomeCarro, veiculos[i].nome)==0) {
    				carroEncontrado = true;
	                
	                printf("\nNome: %s\n", veiculos[i].nome);
	                printf("Categoria: %s\n", veiculos[i].categoria);
	                printf("C�digo: %d\n\n", veiculos[i].codigo);
	                
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

