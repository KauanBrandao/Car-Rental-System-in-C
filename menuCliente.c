#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "menuFuncionario.h"
#include "menuCliente.h"
#include "menuFrontEnd.h"

void printCompleteBanner(); 

bool usuarioOuSenhaInvalido(char usuario[20], char senha[20]){
    if (strlen(usuario) > 20 || strlen(senha) > 20) {
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

bool usuarioExistente(char usuario[20]){
	for(int i = 0; i < codigoCliente; i++){
		if(strcmp(usuario, info[i].usuario) == 0){
			return true;
		}else{
			return false;
		}
	}
}

bool clienteTemCarroAlugado(int indiceCliente) {
    return strcmp(info[indiceCliente].carroAlugado, "") != 0;
}

void registroCliente(){
    fflush(stdin);
    
    printCompleteBanner(); 
    printf("\n \n");
    
    
    printf("Digite o seu nome: ");
    gets(info[codigoCliente].nomeCliente);
	
	fflush(stdin);
    printf("\nInforme a sua Data de Nascimento (DD MM AA): ");
    scanf("%d %d %d", &info[codigoCliente].dia, &info[codigoCliente].mes, &info[codigoCliente].ano);
    
    if(menorIdade(info[codigoCliente].ano)){
    	printf("\033[31m\nVocê tem menos de 18 anos e por isso não poderá terminar o cadastro!\n\n");
    	system("pause");
    	system("cls");
    	return menuPrincipal();
	}
	
	fflush(stdin);
    printf("\nDigite o seu CPF/CNPJ: ");
    gets(info[codigoCliente].cpfCnpj);
    
    if(cpfInvalido(info[codigoCliente].cpfCnpj)){
    	system("cls");
    	printf("\033[31mCPF inválido, tente novamente!\n\n");
    	return registroCliente();
	}

    printf("\nEscolha seu usuário (MAX 20 CARACTERES): ");
    gets(info[codigoCliente].usuario);
    
    if(usuarioExistente(info[codigoCliente].usuario)){
    	system("cls");	
		printf("\033[31mErro: Este nome de usuário já está em uso!\n\n");
		return menuClienteRegistro();
	}

    printf("\nEscolha sua senha (MAX 20 CARACTERES): ");
    gets(info[codigoCliente].senha);

    if (usuarioOuSenhaInvalido(info[codigoCliente].usuario, info[codigoCliente].senha)) {
        system("cls");
        printf("\033[31mERROR: Usuário ou senha maior que 20 caracteres!\n\n");
        return menuClienteRegistro();
    }
    
    FILE *file = fopen("clientes.txt", "a");
    if (file == NULL) {
        printf("\033[31mErro ao abrir o arquivo!\n");
        return;
    }

    fprintf(file, "Nome: %s\n", info[codigoCliente].nomeCliente);
    fprintf(file, "Data de Nascimento: %02d %02d %04d\n", info[codigoCliente].dia, info[codigoCliente].mes, info[codigoCliente].ano);
    fprintf(file, "CPF/CNPJ: %s\n", info[codigoCliente].cpfCnpj);
    fprintf(file, "Usuário: %s\n", info[codigoCliente].usuario);
    fprintf(file, "Senha: %s\n", info[codigoCliente].senha);
    fprintf(file, "---------------------------\n");

    fclose(file);

    codigoCliente++;
    printf("\033[32m\nCadastro concluído!\n");
    system("pause");
    system("cls");
    menuClienteRegistro();
}

bool loginInvalido(char usuario[20], char senha[20]){
    for (int i = 0; i < codigoCliente; i++) {
        if (strcmp(usuario, info[i].usuario) == 0 && strcmp(senha, info[i].senha) == 0) {
        	clienteAtual = i;
            return false;
        }
    }
    return true;
}

void loginCliente(){
    char usuario[20];
    char senha[20];
    char operador [10];
	
	
	void printCompleteBanner(); 
	printf("\n \n");
	

    fflush(stdin);
    printf("Insira seu nome de usuário: ");
    gets(usuario);

    printf("\nInsira sua senha: ");
    gets(senha);
	
    if (loginInvalido(usuario, senha)) {
    	char opcao;
        system("cls");
        printf("\033[31mUsuário ou senha inválidos \n");
        system("pause");
        system("cls");
        printf("Deseja tentar novamente? [S/N]: ");
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
	 
    printf("\033[32m\nLogin efetuado com sucesso.\n");
    system("pause");
    system("cls");
    menuCliente();
}

void menuClienteRegistro(){
    char opcao;


	void printCompleteBanner(); 
    printf("\n \n");
    
    
    printf("******* Faça seu Registro/Login *******\n\n");

    printf("|1 - Registro\n");
    printf("|2 - Login\n");
    printf("|3 - Voltar para o menu inicial\n");
    printf("|Escolha uma opção [1-3]: ");
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
        printf("\033[31mOpção inválida!\n\n");
        return menuClienteRegistro();
    }
}

void carrosDisponiveis() {
	
	void printCompleteBanner(); 
    printf("\n \n"); 
    
    
    if (totalVeiculos == 0) {
        printf("\033[31mNenhum veículo cadastrado!\n\n");
        system("pause");
        return menuCliente(); 
    }
    
    for (int i = 0; i < totalVeiculos; i++) {
        printf("Carro %d\n", i+1);
        printf("Nome: %s\n", veiculos[i].nomeVeiculo);
        printf("Categoria: %s\n", veiculos[i].categoria);
        printf("Ano: %s\n", veiculos[i].ano);
        printf("Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
        printf("Valor da diária: %.2fR$\n", veiculos[i].valorDiaria);
        printf( "------------------\n\n");
    }
	
    system("pause");
    system("cls");
    return menuCliente();
    
}

void vistoriaCarro(int indiceCliente) {
	char resposta1, resposta2, resposta3;
	float valorPago, valorTotal;
	int totalProblemas = 0;
	float percentualAumento;
	
	void printCompleteBanner(); 
    printf("\n \n");
	
    if (!clienteTemCarroAlugado(indiceCliente)) {
        printf("\033[31mCliente não possui carro alugado para vistoria.\n");
        return menuCliente();
    }

    printf("Começando vistoria no veículo '%s'...\n\n", info[indiceCliente].carroAlugado);
	//sleep(2);
	
    printf("Perguntas:\n");
    printf("1. O carro está limpo? (S/N): ");
    scanf(" %c", &resposta1);
    
    if (resposta1 == 'N' || resposta1 == 'n'){
    	totalProblemas++;
	}
	
    printf("\n2. Há algum dano visível no carro? (S/N): ");
    scanf(" %c", &resposta2);
    
    if (resposta2 == 'S' || resposta2 == 's'){
    	totalProblemas++;
	}
    
    printf("\n3. O carro está sendo entregue com tanque cheio? [S/N]: ");
    scanf(" %c", &resposta3);
    system("cls");
    
    if (resposta3 == 'N' || resposta3 == 'n'){
    	totalProblemas++;
	}
    
    if (totalProblemas > 0) {
    	percentualAumento = 1 + (0.1 * totalProblemas); 
    	valorTotal = veiculos[indiceCliente].valorDiaria * veiculos[indiceCliente].dias * percentualAumento;
    	
        printf("\033[31mHouve problemas encontrados durante a vistoria.\n");
        printf("\033[33mCusto da locação foi aumentado em %d%%.\n\n", 10 * totalProblemas);
        
        //sleep(3);
        
        system("cls");
        printf("Novo valor da locação: R$ %.2f\n", valorTotal);
		
		fflush(stdin);
        printf("Por favor, insira o valor de R$ %.2f para concluir a devolução: ", valorTotal);
        scanf(" %f", &valorPago);
        system("cls");
        
        int valorTotalCentavos = round(valorTotal * 100);
        int valorPagoCentavos = round(valorPago * 100);

        if (valorPagoCentavos == valorTotalCentavos) {
            printf("\033[32mPagamento recebido.\n");
            
            totalLocacoes--;
    		strcpy(info[indiceCliente].carroAlugado, "");
    		veiculos[clienteAtual].disponivel = true;
    
			printf("Carro devolvido com sucesso.\n\n");
			system("pause");
			system("cls");
			return menuCliente();
        } else {
            printf("\033[31mValor pago é diferente. Devolução não concluída.\n\n");
            system("pause");
            system("cls");
            return menuCliente();
        }
    }
    if(totalProblemas == 0){
        printf("\033[32mVistoria concluída. Carro em bom estado.\n\n");
        
        totalLocacoes--;
    	strcpy(info[indiceCliente].carroAlugado, "");
    	veiculos[clienteAtual].disponivel = true;
    
		printf("\033[32mCarro devolvido com sucesso.\n\n");
		system("pause");
		system("cls");
		return menuCliente();
    }
}

void devolverCarro(int indiceCliente) {
	
	void printCompleteBanner(); 
    printf("\n \n");
    
    
    if (!clienteTemCarroAlugado(indiceCliente)) {
        printf("\033[31mVocê não possui nenhum carro alugado.\n\n");
        return menuCliente();
    }

    printf("\033[32mVocê está devolvendo o carro %s.\n\n", info[indiceCliente].carroAlugado);
	system("pause");
	
	system("cls");
    vistoriaCarro(indiceCliente);
}

void regrasLocadora() {
	
	
	void printCompleteBanner(); 
    printf("\n \n");
    
    
    printf("******** Regras da Locadora ********\n\n");

    printf("1. O VEÍCULO DEVE SER ENTREGUE E FEITO O CHECKLIST DE IMEDIATO\n");
    printf("2. O VEÍCULO DEVE SER ENTREGUE COM O TANQUE CHEIO\n");
    printf("3. O VEÍCULO DEVE SER ENTREGUE LIMPO\n");
    printf("4. O LOCADOR DEVE SER RESPONSÁVEL POR QUAISQUER DANOS AO VEÍCULO.\n");
    printf("5. AS MULTAS DE TRÂNSITO SÃO RESPONSABILIDADE DO LOCADOR\n");
    printf("6. O PAGAMENTO DEVE SER FEITO ANTES DE PEGAR O VEÍCULO\n");
    printf("7. A CAUÇÃO DEVE SER PAGA COM ANTECEDÊNCIA\n\n");
    printf("8. O PAGAMENTO DEVE SER FEITO VIA PIX, NO CARTÃO (EM ATÉ 4x SEM JUROS, OU 8X COM JUROS DE 2%% AO MÊS), OU EM ESPÉCIE\n\n ");
    
	system("pause");
    system("cls");
    

    
    FILE *file = fopen("regras.txt", "w");
    if (file == NULL) {
        printf("\033[31mErro ao abrir o arquivo!\n");
        return; 
    }
    
    fprintf(file, "1. O VEÍCULO DEVE SER ENTREGUE E FEITO O CHECKLIST DE IMEDIATO\n");
    fprintf(file, "2. O VEÍCULO DEVE SER ENTREGUE COM O TANQUE CHEIO\n");
    fprintf(file, "3. O VEÍCULO DEVE SER ENTREGUE LIMPO\n");
    fprintf(file, "4. O LOCADOR DEVE SER RESPONSÁVEL POR QUAISQUER DANOS AO VEÍCULO.\n");
    fprintf(file, "5. AS MULTAS DE TRÂNSITO SÃO RESPONSABILIDADE DO LOCADOR\n");
    fprintf(file, "6. O PAGAMENTO DEVE SER FEITO ANTES DE PEGAR O VEÍCULO\n");
    fprintf(file, "7. A CAUÇÃO DEVE SER PAGA COM ANTECEDÊNCIA\n\n");
    fprintf(file, "8. O PAGAMENTO DEVE SER FEITO VIA PIX, NO CARTÃO (EM ATÉ 4x SEM JUROS, OU 8X COM JUROS DE 2%% AO MÊS), OU EM ESPÉCIE\n\n ");
    
    fclose(file);
    
    return menuCliente();
}



void minhasInfo() {
    char cpfCnpj[20];
     
    void printCompleteBanner(); 
    printf("\n \n");

    fflush(stdin);
    printf("Informe seu CPF/CNPJ: ");
    gets(cpfCnpj);
	
	
    
    for (int i = 0; i < codigoCliente; i++) {
        if (strcmp(info[i].cpfCnpj, cpfCnpj) == 0) {
            system("cls");
            printf("Usuário encontrado.\n\n");

            printf("Nome: %s\n", info[i].nomeCliente);
            printf("Data de Nascimento %d/%d/%d\n", info[i].dia, info[i].mes, info[i].ano);
            printf("CPF: %s\n", info[i].cpfCnpj);
            
            if(strcmp(info[i].carroAlugado, "") ==0){
            	printf("Carro alugado: Nenhum\n");
			}else{
				printf("\033[32mCarro alugado: %s\n", info[i].carroAlugado);
			}
            printf("Usuário de Login: %s\n\n", info[i].usuario);

            system("pause");
            system("cls");
            return menuCliente();
        }
    }
    system("cls");
    printf("\033[31mUsuário não encontrado.\n\n");
    return menuCliente();
}

void alugarVeiculo(){
	char nomeCarro[40];
	char opcao;
	char confirmar;
	float valorTotal;
	bool carroEncontrado = false;
	
	void printCompleteBanner(); 
    printf("\n \n");
	
	printf("***** ALUGAR CARRO *****\n\n");
	
    if (strcmp(info[clienteAtual].carroAlugado, "") != 0) {
        printf("\033[33mVocê já possui um carro alugado.\n\n");
        system("pause");
        system("cls");
        return menuCliente();
    }
    
	printf("|1- Escolher carro\n");
	printf("|2- Voltar ao menu\n");
	printf("Escolha [1-2]: ");
	scanf(" %c", &opcao);
	
	switch(opcao){
		case '1':
			if (totalVeiculos == 0) {
                printf("\033[31m\nNão há veículos cadastrados!\n\n");
                system("pause");
                system("cls");
                return menuCliente();
            }
            
			fflush(stdin);
			system("cls");
			printf("Informe o nome do veículo que deseja alugar (Ex. Gol): ");
			gets(nomeCarro);
			
			for(int i = 0; i < totalVeiculos; i++){
				if(strcmp(nomeCarro, veiculos[i].nomeVeiculo) == 0 && veiculos[i].disponivel == true){
					system("cls");
					carroEncontrado = true;
					printf("\033[32mVeículo '%s' encontrado!\n\n", nomeCarro);
						
					printf("Nome: %s\n", veiculos[i].nomeVeiculo);
					printf("Categoria: %s\n", veiculos[i].categoria);
					printf("Valor da diária: %.2f\n\n", veiculos[i].valorDiaria);
						
					fflush(stdin);			
					printf("Quantos dias deseja alugar?: ");
					scanf(" %d", &veiculos[i].dias);
						
					valorTotal = veiculos[i].dias * veiculos[i].valorDiaria;
						
					fflush(stdin);
					printf("\nDeseja alugar '%s' por R$%.2f? [S/N]: ", veiculos[i].nomeVeiculo, valorTotal);
					scanf(" %c", &confirmar);
						
					fflush(stdin);
						
					if(confirmar == 'S' || confirmar == 's'){
						strcpy(info[clienteAtual].carroAlugado, nomeCarro);
								
						system("cls");
						printf("\033[32mCarro alugado!\n\n");
							
						veiculos[i].disponivel = false;
						totalLocacoes++;
							
						return menuCliente();
					}else if(confirmar == 'N' || confirmar == 'n'){
						printf("\033[31m\nOperação cancelada.\n");
						system("pause");
						system("cls");
						return menuCliente();
					}else{
						system("cls");
						printf("\033[31mOpção inválida!\n\n");
						return alugarVeiculo();
					}
				}
			}
					
			if(!carroEncontrado){
				system("cls");
				printf("\033[31mVeículo não encontrado ou já alugado.\n\n");
				return menuCliente();
			}
			break;
			
		case '2':
			system("cls");
			menuCliente();
			break;
			
		default:
			system("cls");
			printf("\033[31mOpção inválida! Tente novamente\n\n");
			alugarVeiculo();
	}	
}

void simularAluguel(){
	char carroSimulacao[40];
	bool carroEncontrado = false;
	int diaSimulacao;
	
	void printCompleteBanner(); 
    printf("\n \n");
	
	printf("***** SIMULAR LOCAÇÃO *****\n\n");
	

	fflush(stdin);
	printf("Qual veículo deseja simular a locação? (Ex. Gol): ");
	gets(carroSimulacao);
	
	for(int i = 0; i < totalVeiculos; i++){
		if(strcmp(carroSimulacao, veiculos[i].nomeVeiculo) ==0){
			carroEncontrado = true;
			printf("\nQuantos dias você deseja passar com o veículo? ");
			scanf(" %d", &diaSimulacao);
			
			float diariaCarro = veiculos[i].valorDiaria;
			
			fflush(stdin);
			system("cls");
			printf("##### Simulação #####\n\n");
			printf("Veículo escolhido: %s\n", carroSimulacao);
			printf("Quantidade de dias: %d\n", diaSimulacao);
			printf("Valor da diária: %.2f\n", diariaCarro);
			
			float valorTotal = diariaCarro * diaSimulacao;
			printf("Valor total da locação: %.2f\n\n", valorTotal);
			
			system("pause");
			system("cls");
			return menuCliente();
		}
	}
	
	if(! carroEncontrado){
		system("cls");
		printf("\033[31mVeículo não encontrado!\n\n");
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
        	devolverCarro(clienteAtual);
        	break;
        case '5':
            regrasLocadora();
            break;
        case '6':
            minhasInfo();
            break;
        case '7':
            menuPrincipal();
            break;
            
        default:
            printf("Escolha uma opção válida!\n\n");
            menuCliente();
    }
}

void menuCliente(){
    char opcao;
    
    void printCompleteBanner(); 
    printf("\n \n");

    printf("******* Menu de Clientes *******\n\n");

    printf("|1 - Carros disponíveis\n");
    printf("|2 - Alugar um veiculo\n");
    printf("|3 - Simular locação\n");
    printf("|4 - Devolver veículo\n");
    printf("|5 - Regras da locadora\n");
    printf("|6 - Minhas informações\n");
    printf("|7 - Voltar para o menu inicial\n");
    printf("|Escolha uma opção [1-7]: ");
    scanf(" %c", &opcao);

    system("cls");
    controleMenuCliente(opcao);
}
