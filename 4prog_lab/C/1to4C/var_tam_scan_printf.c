#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Biblioteca para funções adicionais, como alocação de memória

// Função principal do programa
int main() {            
    int numero1 = 21;  // Declara e atribui valor a uma variável inteira
    printf("O valor do número é: %d\n", numero1);
    return 0;          // Retorna 0 indicando que o programa terminou sem erros
}

// Função para exibir diferentes tipos de variáveis usando printf
void imprimirVariaveis() {
    int numero = 42;
    char letra = 'A';
    char nome[] = "Alice";
    float pi = 3.14159;
    double longo_float = 1234567.89;
    long int longo_double = 1234567890;
    unsigned int num_unsigned = 40000;

    printf("1. Inteiro: %d\n", numero);
    printf("2. Caractere: %c\n", letra);
    printf("3. String: %s\n", nome);
    printf("4. Float: %f\n", pi);
    printf("5. Double: %lf\n", longo_float);
    printf("6. Long Int: %ld\n", longo_double);
    printf("7. Unsigned: %u\n", num_unsigned);
    printf("8. Hexadecimal (min): %x\n", numero);
    printf("9. Hexadecimal (maiúsc): %X\n", numero);
    printf("10. Notação científica (e): %e\n", pi);
    printf("11. Notação científica (E): %E\n", pi);
}

// Função para demonstrar formatação de variáveis com printf
void imprimirFormatacoes() {
    int num = 42;
    float valor = 123.456;
    char nome[] = "Alice";

    printf("Número (largura mínima 5): %5d\n", num);
    printf("Número (zeros à esquerda, 5 dígitos): %05d\n", num);
    printf("Número (alinhado à esquerda, largura 5): %-5d\n", num);
    printf("Float (precisão 2): %.2f\n", valor);
    printf("Float (largura 8, precisão 2): %8.2f\n", valor);
    printf("String (largura mínima 10): %10s\n", nome);
}

// Função para leitura de variáveis com scanf
void lerVariaveis() {
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    printf("Número lido: %d\n", num);

    float altura;
    printf("Digite sua altura (m): ");
    scanf("%f", &altura);
    printf("Altura: %.2f\n", altura);

    char letra;
    printf("Digite a inicial do seu nome: ");
    scanf(" %c", &letra); // O espaço evita problemas com espaços em branco
    printf("Inicial: %c\n", letra);

    char nome[50];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Nome: %s\n", nome);

    printf("Digite seu nome completo: ");
    getchar(); // Limpa o buffer antes do fgets
    fgets(nome, sizeof(nome), stdin);
    printf("Nome completo: %s", nome);

    int hex;
    printf("Digite um número hexadecimal: ");
    scanf("%x", &hex);
    printf("Hexadecimal: %x\n", hex);

    void *ptr;
    printf("Digite um endereço de memória: ");
    scanf("%p", &ptr);
    printf("Endereço: %p\n", ptr);
}

// Função principal que chama outras funções
int main() {
    imprimirVariaveis();       // Exibe diferentes tipos de variáveis
    imprimirFormatacoes();     // Demonstra formatação
    lerVariaveis();            // Lê variáveis e exibe valores lidos
    return 0;
}