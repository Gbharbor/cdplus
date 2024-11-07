#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Biblioteca para funcionalidades adicionais, como alocação de memória

// Função principal do programa em C
int main() {
    int numero1;  // Declara uma variável inteira chamada numero1
    numero1 = 21; // Atribui o valor 21 a numero1

    // Exibe o valor da variável usando printf
    printf("O valor do número é: %d\n", numero1); // %d formata como inteiro

    // Retorno 0 indica que o programa terminou sem erros
    return 0;
}

// Função para exibir os tipos de variáveis usando printf com diferentes especificadores
void imprimirVariaveis() {
    int numero = 42;                  // Exemplo de inteiro
    char letra = 'A';                 // Exemplo de caractere
    char nome[] = "Alice";            // Exemplo de string
    float pi = 3.14159;               // Exemplo de float
    double grande_numero = 1234567.89; // Exemplo de double
    long int numero_grande = 1234567890; // Exemplo de inteiro longo
    unsigned int numero_unsigned = 40000; // Exemplo de inteiro sem sinal

    // Exibe diferentes tipos de variáveis com especificadores
    printf("1. Número inteiro: %d\n", numero);         // %d para inteiro
    printf("2. Caractere: %c\n", letra);               // %c para caractere
    printf("3. String: %s\n", nome);                   // %s para string
    printf("4. Valor de pi: %f\n", pi);                // %f para float
    printf("5. Número grande (double): %lf\n", grande_numero); // %lf para double
    printf("6. Número longo: %ld\n", numero_grande);   // %ld para long int
    printf("7. Unsigned inteiro: %u\n", numero_unsigned); // %u para unsigned int
    printf("8. Em hexadecimal: %x\n", numero);         // %x para hexadecimal
    printf("9. Em hexadecimal (maiúsculas): %X\n", numero); // %X para hexadecimal (maiúsculas)
    printf("10. Notação científica: %e\n", pi);        // %e para notação científica
    printf("11. Notação científica (maiúsculas): %E\n", pi); // %E para científica em maiúsculas
    printf("12. Precisão: %.2f\n", 1.75);              // %.2f para precisão de duas casas decimais
}

// Exemplos de funções para formatação de variáveis
void imprimirFormatacoes() {
    int num = 42;
    float valor = 123.456;
    char nome[] = "Alice";

    printf("Número com largura 5: '%5d'\n", num);          // Largura mínima 5
    printf("Número com zeros (5 dígitos): '%05d'\n", num); // Zeros à esquerda
    printf("Alinhado à esquerda (5): '%-5d'\n", num);      // Alinhamento à esquerda
    printf("Float com precisão de 2: '%.2f'\n", valor);    // Precisão de 2 para float
    printf("Float com largura 8 e 2 decimais: '%8.2f'\n", valor); // Largura e precisão
    printf("String com largura mínima 10: '%10s'\n", nome); // Largura mínima para string
}

// Funções para leitura com scanf
void lerVariaveis() {
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    printf("Número lido: %d\n", num);

    float altura;
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);
    printf("Altura lida: %.2f\n", altura);

    char letra;
    printf("Digite a inicial do seu nome: ");
    scanf(" %c", &letra); // O espaço ignora espaços em branco anteriores
    printf("Inicial do nome: %c\n", letra);

    char nome[50];
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Nome: %s\n", nome);

    printf("Digite seu nome completo: ");
    getchar(); // Limpa o buffer de entrada antes de usar fgets
    fgets(nome, sizeof(nome), stdin);
    printf("Nome completo: %s", nome);

    int hex;
    printf("Digite um número hexadecimal: ");
    scanf("%x", &hex);
    printf("Número hexadecimal lido: %x\n", hex);

    int *ptr;
    printf("Digite um endereço de memória (ponteiro): ");
    scanf("%p", &ptr);
    printf("Endereço de memória lido: %p\n", ptr);
}

int main() {
    // Exibe os diferentes tipos de variáveis
    imprimirVariaveis();

    // Demonstra formatação com largura, precisão e alinhamento
    imprimirFormatacoes();

    // Lê variáveis com scanf e exibe valores lidos
    lerVariaveis();

    return 0;
}