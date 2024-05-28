#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "menuFuncionario.h"
#include "menuCliente.h"

bool menorIdade(int idade) {
    if (idade < 18) {
        return true;
    }
    return false;
}

bool usuarioOuSenhaInvalido(char usuarioOuSenha[20]) {
    if (strlen(usuarioOuSenha) > 20) {
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
    
    printf("\nDigite a sua idade: ");
    scanf(" %d", &info[codigoCliente].idade);

    if (menorIdade(info[codigoCliente].idade)) {
        printf("\nVocê tem menos de 18 anos e por isso não poderá concluir o cadastro!\n");
        system("pause");
        system("cls");
        return menuPrincipal();
    }
	
	fflush(stdin);
    printf("\nDigite o seu CPF/CNPJ: ");
    gets(info[codigoCliente].cpfCnpj);
    
    if(cpfInvalido(info[codigoCliente].cpfCnpj)){
    	system("cls");
    	printf("CPF inválido, tente novamente!\n\n");
    	return registroCliente();
	}

    fflush(stdin);
    printf("\nEscolha um usuário (MAX 20 CARACTERES): ");
    gets(info[codigoCliente].usuario);

    if (usuarioOuSenhaInvalido(info[codigoCliente].usuario)) {
        system("cls");
        printf("ERROR: Usuário maior que 20 caracteres!\n\n");
        return registroCliente();
    }

    printf("\nEscolha uma senha (MAX 20 CARACTERES): ");
    gets(info[codigoCliente].senha);

    if (usuarioOuSenhaInvalido(info[codigoCliente].senha)) {
        system("cls");
        printf("ERROR: Senha maior que 20 caracteres!\n\n");
        return registroCliente();
    }

    codigoCliente++;
    printf("\nCadastro concluído!\n");
    system("pause");
    system("cls");
    menuClienteRegistro();
}

bool loginInvalido(char usuario[20], char senha[20]) {
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
	
    fflush(stdin);
    printf("Insira seu nome de usuário: ");
    gets(usuario);

    printf("\nInsira sua senha: ");
    gets(senha);
	
    if (loginInvalido(usuario, senha)) {
        system("cls");
        printf("Usuário ou senha inválidos. Tente novamente\n");
        return loginCliente();
    }  
    printf("\nLogin efetuado com sucesso.\n");
    system("pause");
    system("cls");
    menuCliente();
}

void menuClienteRegistro() {
    char opcao;

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
        printf("Opção inválida!\n\n");
        return menuClienteRegistro();
    }
}

void carrosDisponiveis() {
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n\n");
    }
	
	for (int i = 0; i < totalVeiculos; i++) {
	   	printf("Carro %d\n", i+1);
	    printf("Nome: %s\n", veiculos[i].nome);
	    printf("Categoria: %s\n", veiculos[i].categoria);
	    printf("Ano: %s\n", veiculos[i].ano);
	    printf("Quilometragem: %.3fkm\n", veiculos[i].quilometragem);
	    printf("Valor da diária: %.fR$\n", veiculos[i].valorDiaria);
	    printf("-----------\n");
	}
	
	system("pause");
    system("cls");
    return menuCliente();
}

void regrasLocadora() {
    printf("******** REGRAS LOCADORA ********\n\n");

    printf("1. O VEÍCULO DEVE SER ENTREGUE E FEITO O CHECKLIST DE IMEDIATO\n");
    printf("2. O VEÍCULO DEVE SER ENTREGUE COM O TANQUE CHEIO\n");
    printf("3. O VEÍCULO DEVE SER ENTREGUE LIMPO\n");
    printf("4. O LOCADOR DEVE SER RESPONSÁVEL POR QUAISQUER DANOS AO VEÍCULO.\n");
    printf("5. AS MULTAS DE TRÃNSITO SÃO RESPONSABILIDADE DO LOCADOR\n");
    printf("6. O PAGAMENTO DEVE SER FEITO ANTES DE PEGAR O VEÍCULO\n");
    printf("7. A CAUÇÃO DEVE SER PAGA COM ANTECEDÊNCIA\n");
    printf("8. O PAGAMENTO DEVE SER FEITO VIA PIX, NO CARTÃƒO (EM ATÉ 12X/ COM JUROS DE 2%), OU EM ESPÉCIE\n\n");

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
            printf("Usuário encontrado.\n\n");

            printf("Nome: %s\n", info[i].nomeCliente);
            printf("Idade: %d\n", info[i].idade);
            printf("CPF: %s\n", info[i].cpfCnpj);
            printf("Usuário de Login: %s\n\n", info[i].usuario);

            system("pause");
            system("cls");
            return menuCliente();
        }
    }
    system("cls");
    printf("Usuário não encontrado.\n\n");
    return menuCliente();
}

/*void alugarVeiculo(){
	char carro[20];
	int dias;
	float precoDiariaCarro, 
	float totalValor = dias * precoDiariaCarro;
	
	
	printf("***** ALUGUEL DE CARROS *****");
	
	registroCliente();
	carrosDisponiveis();
	
	
	
	printf("Qual carro vocÃª deseja alugar? ");
	fflushin(stdin);
	gets(carro);
	
	printf("Quantos dias vocÃª vai passar com o carro");
	scanf("%d", &dias);
	
	printf("O valor do carro Ã©: %f ", precoDiariaCarro);
	
	printf("O Valor total da locaÃ§Ã£o Ã©: %f ", totalValor);
	
	FUNÃ‡ÃƒO AINDA NÃƒO ESTÃ COMPLETA POIS NÃƒO DECIDIMOS ONDE VAMOS ARMAZENAR AS INFORMAÃ‡Ã•ES (ARQUIVO OU VETOR)
	
}*/

/*void simularAluguel(){
	
	char carroSimulacao[20];
	int diaSimulacao;
	float precoDiariaSimulacao;
	float totalValorSimulacao = diaSimulacao * precoSimulacao;
	
	printf("$$$$$$$ SIMULAÃ‡ÃƒO DA LOCAÃ‡ÃƒO $$$$$$$");
	
	printf("Qual carro deseja alugar? ");
	gets(carroSimulacao);
	
	printf("Quantos dias vocÃª deseja passar com o carro? ");
	scanf("%d", diaSimulacao);
	
	printf("###### RESULTADO DA SIMULAÃ‡ÃƒO DA LOCAÃ‡ÃƒO ######\n");
	printf("O carro que vocÃª escolheu foi: %s", carroSimulacao);
	printf("\nDias: %d", diaSimulacao);
	printf("\n O preÃ§o da diaria do carro Ã©: %f", precoDiariaSimulacao);
	printf("\n Valor total da locaÃ§Ã£o: %f ", totalValorSimulacao);
	
}*/

void controleMenuCliente(char opcao) {
    switch (opcao) {
        case '1':
            carrosDisponiveis();
            break;
        case '2':
            //alugarVeiculo(); 
            break;
        case '3':
            //simularAluguel();
            break;
        case '4':
            regrasLocadora();
            break;
        case '5':
            menuPrincipal();
            break;
        case '6':
            minhasInfo();
            break;
        default:
            printf("Escolha uma opção válida!\n\n");
            menuCliente();
    }
}

void menuCliente() {
    char opcao;

    printf("******* Menu de Clientes *******\n\n");

    printf("|1 - Carros disponíveis\n");
    printf("|2 - Alugar um veiculo\n");
    printf("|3 - Simular Locação\n");
    printf("|4 - Regras da locadora\n");
    printf("|5 - Voltar para o menu inicial\n");
    printf("|6 - Minhas informações\n");
    printf("|Escolha uma opção [1-6]: ");
    scanf(" %c", &opcao);

    system("cls");
    controleMenuCliente(opcao);
}
