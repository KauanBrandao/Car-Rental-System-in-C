#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "menuFuncionario.h"
#include "menuCliente.h"

bool usuarioOuSenhaInvalido(char usuarioOuSenha[20]){
    if (strlen(usuarioOuSenha) > 20) {
        return true;
    }
    return false;
}

bool menorIdade(int ano){
	if(ano > 2006){
		return true;
	}
	return false;
}

bool cpfInvalido(char cpf[20]){
	if(strlen(cpf) < 11){
		return true;
	}
	return false;
}

void registroCliente(){
    fflush(stdin);
    printf("Digite o seu nome: ");
    gets(info[codigoCliente].nomeCliente);
	
	fflush(stdin);
    printf("\nInforme a sua Data de Nascimento (DD MM AA): ");
    scanf("%d %d %d", &info[codigoCliente].dia, &info[codigoCliente].mes, &info[codigoCliente].ano);
    
    if(menorIdade(info[codigoCliente].ano)){
    	printf("\nVoc� tem menos de 18 anos e por isso n�o poder� terminar o cadastro!\n\n");
    	system("pause");
    	system("cls");
    	return menuPrincipal();
	}
	
	fflush(stdin);
    printf("\nDigite o seu CPF/CNPJ: ");
    gets(info[codigoCliente].cpfCnpj);
    
    if(cpfInvalido(info[codigoCliente].cpfCnpj)){
    	system("cls");
    	printf("CPF inv�lido, tente novamente!\n\n");
    	return registroCliente();
	}

    printf("\nEscolha seu usu�rio/ID (MAX 20 CARACTERES): ");
    gets(info[codigoCliente].usuario);

    if (usuarioOuSenhaInvalido(info[codigoCliente].usuario)){
        system("cls");
        printf("ERROR: Usu�rio maior que 20 caracteres!\n\n");
        return registroCliente();
    }

    printf("\nEscolha sua senha (MAX 20 CARACTERES): ");
    gets(info[codigoCliente].senha);

    if (usuarioOuSenhaInvalido(info[codigoCliente].senha)) {
        system("cls");
        printf("ERROR: Senha maior que 20 caracteres!\n\n");
        return registroCliente();
    }

    codigoCliente++;
    printf("\nCadastro conclu�do!\n");
    system("pause");
    system("cls");
    menuClienteRegistro();
}

bool loginInvalido(char usuario[20], char senha[20]){
    for (int i = 0; i < codigoCliente; i++) {
        if (strcmp(usuario, info[i].usuario) == 0 && strcmp(senha, info[i].senha) == 0) {
            return false;
        }
    }
    return true;
}

void loginCliente(){
    char usuario[20];
    char senha[20];
    char operador [10];
	
    fflush(stdin);
    printf("Insira seu nome de usu�rio: ");
    gets(usuario);

    printf("\nInsira sua senha: ");
    gets(senha);
	
    if (loginInvalido(usuario, senha)) {
        system("cls");
        printf("Usu�rio ou senha inv�lidos, voltando para o menu inicial... \n");
        system("pause");
        system("cls");
        return menuPrincipal();
        
    }  
    printf("\nLogin efetuado com sucesso.\n");
    system("pause");
    system("cls");
    menuCliente();
}

void menuClienteRegistro(){
    char opcao;

    printf("******* Fa�a seu Registro/Login *******\n\n");

    printf("|1 - Registro\n");
    printf("|2 - Login\n");
    printf("|3 - Voltar para o menu inicial\n");
    printf("|Escolha uma op��o [1-3]: ");
    scanf(" %c", &opcao);

    if (opcao == '1') {
        system("cls");
        registroCliente();
    } else if (opcao == '2') {
        system("cls");
        loginCliente();
    } else if (opcao == '3') {
    	system("cls");
    	menuPrincipal();
	} else {
        system("cls");
        printf("Op��o inv�lida!\n\n");
        return menuClienteRegistro();
    }
}

void carrosDisponiveis(){
    if (totalVeiculos == 0) {
        printf("Nenhum ve�culo cadastrado!\n\n");
    }
	
	for (int i = 0; i < totalVeiculos; i++) {
	   	printf("Carro %d\n", i+1);
	    printf("Nome: %s\n", veiculos[i].nome);
	    printf("Categoria: %s\n", veiculos[i].categoria);
	    printf("Ano: %s\n", veiculos[i].ano);
	    printf("Quilometragem: %.fkm\n", veiculos[i].quilometragem);
	    printf("Valor da di�ria: %.2fR$\n", veiculos[i].valorDiaria);
	    printf("-----------\n");
	}
	
	system("pause");
    system("cls");
    return menuCliente();
}

void regrasLocadora(){
    printf("******** REGRAS LOCADORA ********\n\n");

    printf("1. O VE�CULO DEVE SER ENTREGUE E FEITO O CHECKLIST DE IMEDIATO\n");
    printf("2. O VE�CULO DEVE SER ENTREGUE COM O TANQUE CHEIO\n");
    printf("3. O VE�CULO DEVE SER ENTREGUE LIMPO\n");
    printf("4. O LOCADOR DEVE SER RESPONS�VEL POR QUAISQUER DANOS AO VE�CULO.\n");
    printf("5. AS MULTAS DE TR�NSITO S�O RESPONSABILIDADE DO LOCADOR\n");
    printf("6. O PAGAMENTO DEVE SER FEITO ANTES DE PEGAR O VE�CULO\n");
    printf("7. A CAU��O DEVE SER PAGA COM ANTECED�NCIA\n");
    printf("8. O PAGAMENTO DEVE SER FEITO VIA PIX, NO CART�O (EM AT� 12X/ COM JUROS DE 2%), OU EM ESP�CIE\n\n");                                                   
    system("pause");
    system("cls");
    return menuCliente();
}

void minhasInfo() {
    char cpfCnpj[20];

    fflush(stdin);
    printf("Informe seu CPF/CNPJ: ");
    gets(cpfCnpj);

    for (int i = 0; i < codigoCliente; i++) {
        if (strcmp(info[i].cpfCnpj, cpfCnpj) == 0) {
            system("cls");
            printf("Usu�rio encontrado.\n\n");

            printf("Nome: %s\n", info[i].nomeCliente);
            printf("Data de Nascimento %d/%d/%d", info[i].dia, info[i].mes, info[i].ano);
            printf("CPF: %s\n", info[i].cpfCnpj);
            
            if(strcmp(info[i].carroAlugado, "") ==0){
            	printf("Carro alugado: Nenhum\n");
			}else{
				printf("Carro alugado: %s\n", info[i].carroAlugado);
			}
        
            printf("Usu�rio de Login: %s\n\n", info[i].usuario);

            system("pause");
            system("cls");
            return menuCliente();
        }
    }
    system("cls");
    printf("Usu�rio n�o encontrado.\n\n");
    return menuCliente();
}

void alugarVeiculo(){
	char nomeCarro[40];
	char opcao;
	char confirmar;
	int dias;
	float valorTotal;
	bool carroEncontrado = false;
	
	printf("***** Alugar carro *****\n\n");
	
	printf("1- Escolher carro\n");
	printf("2- Voltar ao menu\n");
	printf("Escolha [1-2]: ");
	scanf(" %c", &opcao);
	
	switch(opcao){
		case '1':
			fflush(stdin);
			system("cls");
			printf("Informe o ve�culo que deseja alugar (Ex. Celta): ");
			gets(nomeCarro);
			
			for(int i = 0; i < totalVeiculos; i++){
				if(strcmp(nomeCarro, veiculos[i].nome) ==0){
					system("cls");
					carroEncontrado = true;
					printf("Ve�culo '%s' encontrado!\n\n", nomeCarro);
					
					printf("Nome: %s\n", veiculos[i].nome);
					printf("Categoria: %s\n", veiculos[i].categoria);
					printf("Valor da di�ria: %.2f\n\n", veiculos[i].valorDiaria);
					
					fflush(stdin);
					printf("Quantos dias deseja alugar?: ");
					scanf(" %d", &dias);
					
					valorTotal = dias * veiculos[i].valorDiaria;
					
					fflush(stdin);
					printf("\nDeseja alugar '%s' por R$%.2f? [S/N]: ", veiculos[i].nome, valorTotal);
					scanf(" %c", &confirmar);
					
					if(confirmar == 'S' || confirmar == 's'){
						for(int j = 0; j < codigoCliente; j++){
							strcpy(info[j].carroAlugado, nomeCarro);
						}
						system("cls");
						printf("Carro alugado!\n\n");
						return menuCliente();
					}else if(confirmar == 'N' || confirmar == 'n'){
						printf("\nOpera��o cancelada.\n");
						system("pause");
						system("cls");
						return menuCliente();
					}else{
						system("cls");
						printf("Op��o inv�lida!\n\n");
						return alugarVeiculo();
					}
				}
				if(!carroEncontrado){
					system("cls");
					printf("Carro n�o encontrado.\n\n");
					return menuCliente();
				}
			}
			
			break;
		case '2':
			system("cls");
			menuCliente();
			break;
		default:
			system("cls");
			printf("Op��o inv�lida! Tente novamente\n\n");
			alugarVeiculo();
	}	
}

void simularAluguel(){
	char carroSimulacao[40];
	bool carroEncontrado = false;
	int diaSimulacao;
	
	printf("***** Simular loca��o *****\n\n");
	
	fflush(stdin);
	printf("Qual ve�culo deseja simular loca��o? (Ex. Celta): ");
	gets(carroSimulacao);
	
	for(int i = 0; i < totalVeiculos; i++){
		if(strcmp(carroSimulacao, veiculos[i].nome) ==0){
			carroEncontrado = true;
			printf("\nQuantos dias voc� deseja passar com o ve�culo? ");
			scanf(" %d", &diaSimulacao);
			
			float diariaCarro = veiculos[i].valorDiaria;
			
			fflush(stdin);
			system("cls");
			printf("##### Resultado da simula��o #####\n\n");
			printf("Ve�culo escolhido: %s\n", carroSimulacao);
			printf("Dias: %d\n", diaSimulacao);
			printf("Valor da di�ria: %.2f\n", diariaCarro);
			
			float valorTotal = diariaCarro * diaSimulacao;
			printf("Valor total da loca��o: %.2f\n\n", valorTotal);
			
			system("pause");
			system("cls");
			return menuCliente();
		}
	}
	
	if(! carroEncontrado){
		system("cls");
		printf("Carro n�o encontrado!\n\n");
		return menuCliente();
	}
}

void controleMenuCliente(char opcao){
    switch (opcao) {
        case '1':
            carrosDisponiveis();
            break;
        case '2':
            alugarVeiculo(); 
            break;
        case '3':
            simularAluguel();
            break;
        case '4':
            regrasLocadora();
            break;
        case '5':
            minhasInfo();
            break;
        case '6':
            menuPrincipal();
            break;
        default:
            printf("Escolha uma op��o v�lida!\n\n");
            menuCliente();
    }
}

void menuCliente(){
    char opcao;

    printf("******* Menu de Clientes *******\n\n");

    printf("|1 - Carros dispon�veis\n");
    printf("|2 - Alugar um veiculo\n");
    printf("|3 - Simular Loca��o\n");
    printf("|4 - Regras da locadora\n");
    printf("|5 - Minhas informa��es\n");
    printf("|6 - Voltar para o menu inicial\n");
    printf("|Escolha uma op��o [1-6]: ");
    scanf(" %c", &opcao);

    system("cls");
    controleMenuCliente(opcao);
}