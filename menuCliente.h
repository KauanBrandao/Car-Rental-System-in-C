#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

struct Cliente {
    char nomeCliente[50];
    int dia, mes, ano;
    char cpfCnpj[20];
    char usuario[20];
    char senha[20];
    char carroAlugado[40];
    float custoAluguel;
}info[]; // FAVOR NAO COLOCAR NUMERO NA ARRAY, POIS É UMA ARRAY SEM TAMANHO!!!!!!!!!!!

int codigoCliente = 0;
extern void menuPrincipal();

void menuClienteRegistro();
void menuCliente();
void registroCliente();
void loginCliente();
void menuClienteRegistro();
void formadePagamento();

int clienteAtual = -1;

#endif