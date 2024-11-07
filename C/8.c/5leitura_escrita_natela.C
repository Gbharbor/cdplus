#include <stdio.h>  // Necessário para operações de entrada e saída
#include <string.h> // Necessário para manipulação de strings
#define MAX 100    // Define um tamanho máximo para as strings

int main() {
    char nome[MAX];        // Declara um vetor de caracteres para armazenar o nome
    char sobrenome[MAX];   // Declara um vetor de caracteres para armazenar o sobrenome

    // Lê o nome do usuário
    printf("Digite seu nome: ");
    scanf("%s", nome); // Lê o nome até encontrar um espaço em branco

    // Lê o sobrenome do usuário
    printf("Digite seu sobrenome: ");
    scanf("%s", sobrenome); // Lê o sobrenome até encontrar um espaço em branco

    // Exibe o nome e sobrenome lidos
    printf("Seu nome é %s e seu sobrenome é %s.\n", nome, sobrenome);

    // Problema: O scanf lê até encontrar um espaço em branco, 
    // portanto, se o usuário digitar um nome completo, 
    // apenas a primeira parte será lida.

    // Para resolver isso, vamos usar fgets para ler strings completas
    printf("\nVersão melhorada do programa usando fgets:\n");
    
    // Lê o nome do usuário, permitindo espaços
    printf("Digite seu nome completo: ");
    fgets(nome, sizeof(nome), stdin); // Lê a linha inteira, incluindo espaços
    nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha, se presente

    // Lê o sobrenome do usuário
    printf("Digite seu sobrenome completo: ");
    fgets(sobrenome, sizeof(sobrenome), stdin); // Lê a linha inteira, incluindo espaços
    sobrenome[strcspn(sobrenome, "\n")] = 0; // Remove o caractere de nova linha, se presente

    // Exibe o nome e sobrenome lidos
    printf("Seu nome completo é %s e seu sobrenome completo é %s.\n", nome, sobrenome);

    return 0; // Indica que o programa terminou corretamente
}
