#include <stdio.h>
#include <stdlib.h>

/*
    Aula de C - Tipos, printf, scanf e formatação
    Organização em tópicos para estudo
*/

/* =========================================================
   Função auxiliar: limpar o buffer de entrada
   Útil depois de alguns scanf, antes de usar fgets
   ========================================================= */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta os caracteres restantes */
    }
}

/* =========================================================
   Tópico 1 - Exemplo básico de variável inteira
   ========================================================= */
void exemploBasico(void) {
    int numero1 = 21;

    printf("=== Tópico 1 - Exemplo básico ===\n");
    printf("O valor do número é: %d\n\n", numero1);
}

/* =========================================================
   Tópico 2 - Tipos de variáveis e formatos no printf
   ========================================================= */
void imprimirVariaveis(void) {
    int numero = 42;
    char letra = 'A';
    char nome[] = "Alice";
    float piFloat = 3.14159f;
    double valorDouble = 1234567.89;
    long int valorLong = 1234567890L;
    unsigned int numUnsigned = 40000U;

    printf("=== Tópico 2 - Tipos de variáveis ===\n");
    printf("1. Inteiro: %d\n", numero);
    printf("2. Caractere: %c\n", letra);
    printf("3. String: %s\n", nome);
    printf("4. Float: %f\n", piFloat);
    printf("5. Double: %f\n", valorDouble);
    printf("6. Long int: %ld\n", valorLong);
    printf("7. Unsigned int: %u\n", numUnsigned);
    printf("8. Hexadecimal (minúsculo): %x\n", numero);
    printf("9. Hexadecimal (maiúsculo): %X\n", numero);
    printf("10. Notação científica (e): %e\n", piFloat);
    printf("11. Notação científica (E): %E\n", piFloat);
    printf("\n");
}

/* =========================================================
   Tópico 3 - Formatação com printf
   ========================================================= */
void imprimirFormatacoes(void) {
    int num = 42;
    float valor = 123.456f;
    char nome[] = "Alice";

    printf("=== Tópico 3 - Formatação com printf ===\n");
    printf("Número com largura mínima 5: %5d\n", num);
    printf("Número com zeros à esquerda: %05d\n", num);
    printf("Número alinhado à esquerda: %-5d\n", num);
    printf("Float com 2 casas decimais: %.2f\n", valor);
    printf("Float com largura 8 e 2 casas: %8.2f\n", valor);
    printf("String com largura mínima 10: %10s\n", nome);
    printf("String alinhada à esquerda: %-10s\n", nome);
    printf("\n");
}

/* =========================================================
   Tópico 4 - Leitura de inteiro, float e char com scanf
   ========================================================= */
void lerTiposBasicos(void) {
    int num;
    float altura;
    char letra;

    printf("=== Tópico 4 - Leitura de tipos básicos ===\n");

    printf("Digite um número inteiro: ");
    if (scanf("%d", &num) == 1) {
        printf("Número lido: %d\n", num);
    } else {
        printf("Entrada inválida para inteiro.\n");
        limparBuffer();
    }

    printf("Digite sua altura em metros: ");
    if (scanf("%f", &altura) == 1) {
        printf("Altura lida: %.2f m\n", altura);
    } else {
        printf("Entrada inválida para float.\n");
        limparBuffer();
    }

    printf("Digite a inicial do seu nome: ");
    scanf(" %c", &letra); /* espaço antes do %c ignora ENTER anterior */
    printf("Inicial lida: %c\n\n", letra);
}

/* =========================================================
   Tópico 5 - Leitura de strings
   scanf("%s") lê apenas até o primeiro espaço
   fgets() lê a linha inteira
   ========================================================= */
void lerStrings(void) {
    char nome[50];
    char nomeCompleto[100];

    printf("=== Tópico 5 - Leitura de strings ===\n");

    printf("Digite seu primeiro nome: ");
    scanf("%49s", nome); /* evita overflow */
    printf("Nome lido com scanf(\"%%s\"): %s\n", nome);

    limparBuffer(); /* limpa o ENTER deixado no buffer */

    printf("Digite seu nome completo: ");
    if (fgets(nomeCompleto, sizeof(nomeCompleto), stdin) != NULL) {
        printf("Nome completo lido com fgets(): %s", nomeCompleto);
    }

    printf("\n");
}

/* =========================================================
   Tópico 6 - Leitura de hexadecimal
   %x lê um número em base hexadecimal
   ========================================================= */
void lerHexadecimal(void) {
    int hex;

    printf("=== Tópico 6 - Leitura hexadecimal ===\n");
    printf("Digite um número hexadecimal (ex.: FF ou 1A): ");

    if (scanf("%x", &hex) == 1) {
        printf("Valor em decimal: %d\n", hex);
        printf("Valor em hexadecimal: %x\n", hex);
    } else {
        printf("Entrada inválida para hexadecimal.\n");
        limparBuffer();
    }

    printf("\n");
}

/* =========================================================
   Tópico 7 - Observações importantes
   ========================================================= */
void observacoes(void) {
    printf("=== Tópico 7 - Observações importantes ===\n");
    printf("1. %%d -> inteiro\n");
    printf("2. %%f -> float e double no printf\n");
    printf("3. %%c -> caractere\n");
    printf("4. %%s -> string\n");
    printf("5. %%x / %%X -> hexadecimal\n");
    printf("6. scanf(\"%%s\") lê apenas até o primeiro espaço\n");
    printf("7. fgets() é melhor para ler frases ou nomes completos\n");
    printf("8. Em scanf, variáveis simples normalmente usam & antes do nome\n");
    printf("9. Em arrays de char, como strings, não se usa & no scanf com %%s\n");
    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main(void) {
    exemploBasico();
    imprimirVariaveis();
    imprimirFormatacoes();
    lerTiposBasicos();
    lerStrings();
    lerHexadecimal();
    observacoes();

    return 0;
}