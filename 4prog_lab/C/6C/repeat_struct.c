#include <stdio.h>

int main() {
    // 1. Declaração de variáveis
    int x = 10, y = 20;

    // 2. Estrutura switch
    printf("Estrutura switch:\n");
    switch (x) {
        case 10:
            printf("x é igual a 10\n");
            break; // Sai do switch após encontrar a correspondência
        case 20:
            printf("x é igual a 20\n");
            break; // Sai do switch
        default:
            printf("x não é 10 nem 20\n");
            break; // Sai do switch
    }
    printf("\n"); // Para separar a saída

    // --- Estruturas de Controle de Repetição (Laços) ---

    // 3. Laço for
    printf("Laço for:\n");
    for (int i = 0; i < 5; i++) { // i começa em 0 e vai até 4
        printf("i = %d\n", i); // Exibe o valor de i
    }
    printf("\n"); // Para separar a saída

    // 4. Laço while
    printf("Laço while:\n");
    int i = 0; // Inicializa i
    while (i < 5) { // Enquanto i for menor que 5
        printf("i = %d\n", i); // Exibe o valor de i
        i++; // Incrementa i em 1
    }
    printf("\n"); // Para separar a saída

    // 5. Laço do-while
    printf("Laço do-while:\n");
    i = 0; // Inicializa i novamente
    do {
        printf("i = %d\n", i); // Exibe o valor de i
        i++; // Incrementa i em 1
    } while (i < 5); // Enquanto i for menor que 5
    printf("\n"); // Para separar a saída

    // --- Desvios Incondicionais ---

    // 6. Uso do break
    printf("Uso do break no laço for:\n");
    for (i = 0; i < 10; i++) { // Laço que vai de 0 a 9
        if (i == 5) { // Se i for igual a 5
            break; // Sai do laço imediatamente
        }
        printf("i = %d\n", i); // Exibe o valor de i
    }
    printf("\n"); // Para separar a saída

    // 7. Uso do continue
    printf("Uso do continue no laço for:\n");
    for (i = 0; i < 5; i++) { // Laço que vai de 0 a 4
        if (i == 2) { // Se i for igual a 2
            continue; // Pula a iteração atual, volta para o início do laço
        }
        printf("i = %d\n", i); // Exibe o valor de i
    }
    printf("\n"); // Para separar a saída

    // 8. Uso do goto
    printf("Uso do goto:\n");
    if (x == 10) { // Se x for igual a 10
        goto etiqueta; // Salta para a etiqueta "etiqueta"
    }
    printf("Este código será ignorado.\n");

    etiqueta: // Etiqueta para onde o programa pode saltar
    printf("Salto realizado com goto!\n");

    // 9. Exemplo adicional com switch para mostrar as categorias de idade
    printf("\nExemplo de switch para categorias de idade:\n");
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    switch (idade) {
        case 0 ... 12: // Para idades de 0 a 12
            printf("Você é uma criança.\n");
            break;
        case 13 ... 19: // Para idades de 13 a 19
            printf("Você é um adolescente.\n");
            break;
        case 20 ... 64: // Para idades de 20 a 64
            printf("Você é um adulto.\n");
            break;
        default: // Qualquer idade maior ou igual a 65
            printf("Você é um idoso.\n");
            break;
    }

    return 0; // Finaliza o programa
}