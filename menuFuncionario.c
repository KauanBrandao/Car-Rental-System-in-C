#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 100

typedef struct {
    char nome[40];
    char modelo[40];
    int codigo;
} Veiculo;

void menuFuncionario();
void cadastrarVeiculo();
void removerVeiculo();
void buscarVeiculo();

Veiculo veiculos[MAX_VEICULOS];
int totalVeiculos = 0;

void controleMenuFuncionario(int opcao) {
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
            // consultarLocacoes();
            break;
        default:
            printf("Escolha uma opção válida!\n\n");
            menuFuncionario();
    }
}

void loginFuncionario() {
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

void menuFuncionario() {
    int opcao;
    
    printf("******* Menu de Funcionário *******\n");
    
    printf("|1 - Cadastrar veiculo\n");
    printf("|2 - Remover veiculos\n");
    printf("|3 - Buscar veiculos\n");
    printf("|4 - Consultar locações\n");    
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}

void cadastrarVeiculo() {
    if (totalVeiculos >= MAX_VEICULOS) {
        printf("Limite de veículos cadastrados atingido!\n");
        return;
    }
    
    Veiculo v;

    printf("Digite o nome do carro: \n");
    scanf("%s", v.nome);

    printf("Digite o modelo do carro: \n");
    scanf("%s", v.modelo);

    printf("Digite o código para esse veículo: \n");
    scanf("%d", &v.codigo);

    veiculos[totalVeiculos++] = v;

    system("cls");

    printf("**** CARRO CADASTRADO COM SUCESSO ****\n\n");

    system("pause");
    system("cls");
    menuFuncionario();
}

void removerVeiculo() {
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n");
        return;
    }
    
    int codigo;
    printf("Digite o código do veículo a ser removido: \n");
    scanf("%d", &codigo);

    int index = -1;
    for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].codigo == codigo) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Veículo não encontrado!\n");
    } else {
        for (int i = index; i < totalVeiculos - 1; i++) {
            veiculos[i] = veiculos[i + 1];
        }
        totalVeiculos--;
        printf("**** VEÍCULO REMOVIDO COM SUCESSO ****\n\n");
    }

    system("pause");
    system("cls");
    menuFuncionario();
}

void buscarVeiculo() {
    if (totalVeiculos == 0) {
        printf("Nenhum veículo cadastrado!\n");
        system("pause");
        system("cls");
        menuFuncionario();
        return;
    }

    int opcao;
    printf("Buscar veículo por:\n");
    printf("1. Código\n");
    printf("2. Nome\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int codigo;
        printf("Digite o código do veículo: ");
        scanf("%d", &codigo);

        for (int i = 0; i < totalVeiculos; i++) {
            if (veiculos[i].codigo == codigo) {
                printf("Veículo encontrado:\n");
                printf("Nome: %s\n", veiculos[i].nome);
                printf("Modelo: %s\n", veiculos[i].modelo);
                printf("Código: %d\n", veiculos[i].codigo);
                system("pause");
                system("cls");
                menuFuncionario();
                return;
            }
        }
        printf("Veículo não encontrado!\n");

    } else if (opcao == 2) {
        char nome[40];
        printf("Digite o nome do veículo: ");
        scanf("%s", nome);

        for (int i = 0; i < totalVeiculos; i++) {
            if (strcmp(veiculos[i].nome, nome) == 0) {
                printf("Veículo encontrado:\n");
                printf("Nome: %s\n", veiculos[i].nome);
                printf("Modelo: %s\n", veiculos[i].modelo);
                printf("Código: %d\n", veiculos[i].codigo);
                system("pause");
                system("cls");
                menuFuncionario();
                return;
            }
        }
        printf("Veículo não encontrado!\n");

    } else {
        printf("Opção inválida!\n");
    }

    system("pause");
    system("cls");
    menuFuncionario();
}

