#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar as informações da nota fiscal
typedef struct {
    char nomeCliente[100];
    char cpfCnpj[20];
    char carro[50];
    char dataLocacao[11];
    char dataDevolucao[11];
    double valorDiaria;
    int diasLocados;
    double valorTotal;
} NotaFiscal;

// Função para calcular o valor total da locação
double calcularValorTotal(double valorDiaria, int diasLocados) {
    return valorDiaria * diasLocados;
}

// Função para coletar as informações e gerar a nota fiscal
void gerarNotaFiscal() {
    NotaFiscal nota;

    setlocale(LC_ALL, "");

    // Coletando as informações do cliente
    printf("Digite o nome do cliente: ");
    fgets(nota.nomeCliente, 100, stdin);
    nota.nomeCliente[strcspn(nota.nomeCliente, "\n")] = 0; 

    printf("Digite o CPF/CNPJ do cliente: ");
    fgets(nota.cpfCnpj, 20, stdin);
    nota.cpfCnpj[strcspn(nota.cpfCnpj, "\n")] = 0; 

    // Coletando as informações do carro e locação
    printf("Digite o modelo do carro: ");
    fgets(nota.carro, 50, stdin);
    nota.carro[strcspn(nota.carro, "\n")] = 0;

    printf("Digite a data de locação (DD/MM/AAAA): ");
    fgets(nota.dataLocacao, 11, stdin);
    nota.dataLocacao[strcspn(nota.dataLocacao, "\n")] = 0; 
     
    printf("Digite a data de devolução (DD/MM/AAAA): ");
    fgets(nota.dataDevolucao, 11, stdin);
    nota.dataDevolucao[strcspn(nota.dataDevolucao, "\n")] = 0; 

    printf("Digite o valor da diária: ");
    scanf("%lf", &nota.valorDiaria);

    printf("Digite a quantidade de dias locados: ");
    scanf("%d", &nota.diasLocados);

    // Calculando o valor total
    nota.valorTotal = calcularValorTotal(nota.valorDiaria, nota.diasLocados);
    
     system("cls");
     system("pause");
    
    // Exibindo a nota fiscal resumida
    printf("\n========= Nota Fiscal de Serviço =========\n");
    printf("Nome do Cliente: %s\n", nota.nomeCliente);
    printf("CPF/CNPJ do Cliente: %s\n", nota.cpfCnpj);
    printf("Carro: %s\n", nota.carro);
    printf("Data de Locação: %s\n", nota.dataLocacao);
    printf("Data de Devolução: %s\n", nota.dataDevolucao);
    printf("Valor da Diária: R$%.2lf\n", nota.valorDiaria);
    printf("Dias Locados: %d\n", nota.diasLocados);
    printf("Valor Total: R$%.2lf\n", nota.valorTotal);
    printf("=========================================\n");
}

int main() {
    gerarNotaFiscal();
    return 0;
}

