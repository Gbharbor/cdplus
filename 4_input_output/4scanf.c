#include <stdio.h>

/*
 * A função scanf é usada para ler dados da entrada padrão (geralmente teclado)
 * e armazená-los em variáveis. Assim como printf tem seus especificadores,
 * scanf também possui os seus.
 */

// 1. Inteiros (%d, %i, %u)
// %d: Lê inteiros em base decimal (positivo ou negativo).
// %i: Lê inteiros, detectando a base (decimal, octal com prefixo 0, ou hexadecimal com prefixo 0x).
// %u: Lê inteiros sem sinal (somente positivo).
void lerInteiros() {
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num); // Lê um inteiro
    printf("Número lido: %d\n", num);
}

// 2. Números de ponto flutuante (%f, %lf)
// %f: Lê float (ponto flutuante simples).
// %lf: Lê double (ponto flutuante duplo).
void lerPontoFlutuante() {
    float altura;
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura); // Lê um número de ponto flutuante
    printf("Altura lida: %.2f\n", altura);
}

// 3. Caracteres (%c)
// Lê um único caractere, incluindo espaços em branco e novas linhas.
void lerCaracter() {
    char letra;
    printf("Digite a inicial do seu nome: ");
    scanf(" %c", &letra); // O espaço antes de %c ignora espaços em branco
    printf("Inicial do nome: %c\n", letra);
}

// 4. Strings (%s)
// Lê uma sequência de caracteres até encontrar um espaço em branco ou nova linha.
void lerString() {
    char nome[50]; // Cria um array de 50 caracteres
    printf("Digite seu nome: ");
    scanf("%s", nome); // Não precisa de & porque nome já é um ponteiro
    printf("Nome: %s\n", nome);
}

// 5. Lendo uma string com espaços usando fgets
void lerNomeCompleto() {
    char nome[50]; // Cria um array de 50 caracteres
    printf("Digite seu nome completo: ");
    fgets(nome, sizeof(nome), stdin); // Lê até 49 caracteres, incluindo espaços
    printf("Seu nome completo é: %s", nome);
}

// 6. Números hexadecimais e octais (%x, %o)
void lerHexadecimal() {
    int hex;
    printf("Digite um número hexadecimal: ");
    scanf("%x", &hex); // Lê um número hexadecimal
    printf("Número hexadecimal lido: %x\n", hex);
}

// 7. Ponteiro (%p)
// Lê um endereço de memória (um ponteiro).
void lerPonteiro() {
    int *ptr;
    printf("Digite um endereço de memória (ponteiro): ");
    scanf("%p", &ptr); // Lê um ponteiro
    printf("Endereço de memória lido: %p\n", ptr);
}

int main() {
    lerInteiros();        // Chama a função para ler um inteiro
    lerPontoFlutuante(); // Chama a função para ler um número de ponto flutuante
    lerCaracter();       // Chama a função para ler um caractere
    lerString();         // Chama a função para ler uma string
    lerNomeCompleto();   // Chama a função para ler um nome completo
    lerHexadecimal();    // Chama a função para ler um número hexadecimal
    lerPonteiro();       // Chama a função para ler um ponteiro

    return 0;
}