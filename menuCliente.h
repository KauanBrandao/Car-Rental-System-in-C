#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

struct Cliente {
    char nomeCliente[50];
    int dia, mes, ano;
    char cpfCnpj[20];
    char usuario[20];
    char senha[20];
    char carroAlugado[40];
} info[];

int codigoCliente = 0;
extern void menuPrincipal();

void menuClienteRegistro();
void menuCliente();
void registroCliente();
void loginCliente();
void menuClienteRegistro();

#endif