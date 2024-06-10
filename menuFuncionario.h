#ifndef MENUFUNCIONARIO_H
#define MENUFUNCIONARIO_H

#define MAX_VEICULOS 100
#define MAX_LOCACOES 100

struct Veiculo{
    char nome[40];
    char codigo[10];
    char categoria[10];
    char ano[10];
    int dias;
    float quilometragem;
    float valorDiaria;
    bool disponivel;
} veiculos[MAX_VEICULOS];

int totalLocacoes = 0;
int totalVeiculos = 0;
extern void menuPrincipal();

void menuFuncionario();
void cadastrarVeiculo();
void removerVeiculo();
void buscarVeiculo();
void loginFuncionario();

#endif
