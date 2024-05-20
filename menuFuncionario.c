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
            printf("Escolha uma op��o v�lida!\n\n");
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
        printf("Login ou senha inv�lidos.\n\n");
        loginFuncionario();
    }
}

void menuFuncionario() {
    int opcao;
    
    printf("******* Menu de Funcion�rio *******\n");
    
    printf("|1 - Cadastrar veiculo\n");
    printf("|2 - Remover veiculos\n");
    printf("|3 - Buscar veiculos\n");
    printf("|4 - Consultar loca��es\n");    
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);
    
    system("cls");
    controleMenuFuncionario(opcao);
}

void cadastrarVeiculo() {
    if (totalVeiculos >= MAX_VEICULOS) {
        printf("Limite de ve�culos cadastrados atingido!\n");
        return;
    }
    
    Veiculo v;

    printf("Digite o nome do carro: \n");
    scanf("%s", v.nome);

    printf("Digite o modelo do carro: \n");
    scanf("%s", v.modelo);

    printf("Digite o c�digo para esse ve�culo: \n");
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
        printf("Nenhum ve�culo cadastrado!\n");
        return;
    }
    
    int codigo;
    printf("Digite o c�digo do ve�culo a ser removido: \n");
    scanf("%d", &codigo);

    int index = -1;
    for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].codigo == codigo) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Ve�culo n�o encontrado!\n");
    } else {
        for (int i = index; i < totalVeiculos - 1; i++) {
            veiculos[i] = veiculos[i + 1];
        }
        totalVeiculos--;
        printf("**** VE�CULO REMOVIDO COM SUCESSO ****\n\n");
    }

    system("pause");
    system("cls");
    menuFuncionario();
}

void buscarVeiculo() {
    if (totalVeiculos == 0) {
        printf("Nenhum ve�culo cadastrado!\n");
        system("pause");
        system("cls");
        menuFuncionario();
        return;
    }

    int opcao;
    printf("Buscar ve�culo por:\n");
    printf("1. C�digo\n");
    printf("2. Nome\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int codigo;
        printf("Digite o c�digo do ve�culo: ");
        scanf("%d", &codigo);

        for (int i = 0; i < totalVeiculos; i++) {
            if (veiculos[i].codigo == codigo) {
                printf("Ve�culo encontrado:\n");
                printf("Nome: %s\n", veiculos[i].nome);
                printf("Modelo: %s\n", veiculos[i].modelo);
                printf("C�digo: %d\n", veiculos[i].codigo);
                system("pause");
                system("cls");
                menuFuncionario();
                return;
            }
        }
        printf("Ve�culo n�o encontrado!\n");

    } else if (opcao == 2) {
        char nome[40];
        printf("Digite o nome do ve�culo: ");
        scanf("%s", nome);

        for (int i = 0; i < totalVeiculos; i++) {
            if (strcmp(veiculos[i].nome, nome) == 0) {
                printf("Ve�culo encontrado:\n");
                printf("Nome: %s\n", veiculos[i].nome);
                printf("Modelo: %s\n", veiculos[i].modelo);
                printf("C�digo: %d\n", veiculos[i].codigo);
                system("pause");
                system("cls");
                menuFuncionario();
                return;
            }
        }
        printf("Ve�culo n�o encontrado!\n");

    } else {
        printf("Op��o inv�lida!\n");
    }

    system("pause");
    system("cls");
    menuFuncionario();
}

