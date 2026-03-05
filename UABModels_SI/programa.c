#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 128

static int valor_romano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

static int par_subtrativo_valido(char atual, char seguinte) {
    return (atual == 'I' && (seguinte == 'V' || seguinte == 'X')) ||
           (atual == 'X' && (seguinte == 'L' || seguinte == 'C')) ||
           (atual == 'C' && (seguinte == 'D' || seguinte == 'M'));
}

int main(void) {
    char entrada[MAX_INPUT];
    char romano[MAX_INPUT];

    printf("Introduza um numeral romano: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        printf("Erro: não foi possível ler a entrada.\n");
        return 1;
    }

    entrada[strcspn(entrada, "\n")] = '\0';

    size_t inicio = 0;
    while (entrada[inicio] != '\0' && isspace((unsigned char)entrada[inicio])) {
        inicio++;
    }

    size_t fim = strlen(entrada);
    while (fim > inicio && isspace((unsigned char)entrada[fim - 1])) {
        fim--;
    }

    size_t tamanho = fim - inicio;
    if (tamanho == 0) {
        printf("Erro: a entrada está vazia.\n");
        return 1;
    }

    for (size_t i = 0; i < tamanho; i++) {
        romano[i] = (char)toupper((unsigned char)entrada[inicio + i]);
    }
    romano[tamanho] = '\0';

    int total = 0;
    int ultimo_bloco = 4000;
    char anterior = '\0';
    int repeticoes = 0;

    for (size_t i = 0; i < tamanho; i++) {
        char atual = romano[i];
        int valor_atual = valor_romano(atual);

        if (valor_atual == 0) {
            printf("Erro: símbolo inválido '%c'. Utilize apenas I, V, X, L, C, D, M.\n", atual);
            return 1;
        }

        if (atual == anterior) {
            repeticoes++;
        } else {
            repeticoes = 1;
        }

        if ((atual == 'V' || atual == 'L' || atual == 'D') && repeticoes > 1) {
            printf("Erro: '%c' não pode ser repetido.\n", atual);
            return 1;
        }

        if ((atual == 'I' || atual == 'X' || atual == 'C' || atual == 'M') && repeticoes > 3) {
            printf("Erro: '%c' não pode aparecer mais de 3 vezes seguidas.\n", atual);
            return 1;
        }

        if (i + 1 < tamanho) {
            char seguinte = romano[i + 1];
            int valor_seguinte = valor_romano(seguinte);

            if (valor_seguinte == 0) {
                printf("Erro: símbolo inválido '%c'. Utilize apenas I, V, X, L, C, D, M.\n", seguinte);
                return 1;
            }

            if (valor_seguinte > valor_atual) {
                if (repeticoes > 1) {
                    printf("Erro: '%c' não pode ser repetido antes de uma subtração.\n", atual);
                    return 1;
                }

                if (!par_subtrativo_valido(atual, seguinte)) {
                    printf("Erro: par subtrativo inválido '%c%c'.\n", atual, seguinte);
                    return 1;
                }

                int bloco = valor_seguinte - valor_atual;
                if (bloco > ultimo_bloco) {
                    printf("Erro: ordem inválida no numeral romano.\n");
                    return 1;
                }

                total += bloco;
                ultimo_bloco = bloco;

                i++;
                anterior = '\0';
                repeticoes = 0;
                continue;
            }
        }

        if (valor_atual > ultimo_bloco) {
            printf("Erro: ordem inválida no numeral romano.\n");
            return 1;
        }

        total += valor_atual;
        ultimo_bloco = valor_atual;
        anterior = atual;
    }

    printf("%s = %d\n", romano, total);
    return 0;
}
