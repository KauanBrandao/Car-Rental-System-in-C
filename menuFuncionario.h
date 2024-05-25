#ifndef MENUFUNCIONARIO_H
#define MENUFUNCIONARIO_H

#define MAX_VEICULOS 100

struct Veiculo{
    char nome[40];
    char categoria[15];
    int codigo;
} veiculos[MAX_VEICULOS];

int totalVeiculos = 0;
void loginFuncionario();

#endif