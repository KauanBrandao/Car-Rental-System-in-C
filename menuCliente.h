#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

struct Cliente {
    char nomeCliente[50];
    char cpfCnpj[20];
    int idade;
    char usuario[20];
    char senha[20];
} info[];

int codigoCliente = 0;
extern void menuPrincipal();

void menuClienteRegistro();
void menuCliente();
void registroCliente();
void loginCliente();
void menuClienteRegistro();

#endif