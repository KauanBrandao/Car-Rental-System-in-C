#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

struct Cliente {
    char nomeCliente[50];
    int dia, mes, ano;
    char cpfCnpj[20];
    char usuario[20];
    char senha[20];
    char carroAlugado[40];
}info[]; 

int codigoCliente = 0;
extern void menuPrincipal();

void printBanner() {
    printf("\033[034m    __    _____ _____ ____   __  __  ____   _____ \n");
    printf("\033[034m   / /   / __  / ___ /   |  / | / / /   |  /   _/ \n");
    printf("\033[034m  / /   / / / / /   / /| | /  |/ / / /| |  /  /   \n");
    printf("\033[034m / /___/ /_/ / /___/ ___ |/  /| / / ___ |_/  /    \n");
    printf("\033[034m/_____/\\____/\\___/__/ / /|_/|/_/__|_/__/____/   \n");
    printf("\n\n"); 
}
void menuClienteRegistro();
void menuCliente();
void registroCliente();
void loginCliente();
void menuClienteRegistro();
void formadePagamento();
void vistoriaCarro(int indiceCliente);
void carregarClientes();
void carregarLocacoes();

int clienteAtual = -1;

#endif