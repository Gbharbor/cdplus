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
        default:  return 0;
    }
}

static int par_subtrativo_valido(char a, char b) {
    return (a == 'I' && (b == 'V' || b == 'X')) ||
           (a == 'X' && (b == 'L' || b == 'C')) ||
           (a == 'C' && (b == 'D' || b == 'M'));
}

int main(void) {
    char entrada[MAX_INPUT];
    char romano[MAX_INPUT];

    printf("Introduza um numeral romano: ");
    fflush(stdout);

    if (!fgets(entrada, sizeof(entrada), stdin)) {
        printf("Erro: não foi possível ler a entrada.\n");
        return 1;
    }

    /* Remove o '\n' do fgets (se existir) */
    entrada[strcspn(entrada, "\n")] = '\0';

    /* Trim (ignora espaços no início e no fim) */
    size_t ini = 0;
    while (entrada[ini] && isspace((unsigned char)entrada[ini])) {
        ini++;
    }

    size_t fim = strlen(entrada);
    while (fim > ini && isspace((unsigned char)entrada[fim - 1])) {
        fim--;
    }

    size_t n = fim - ini;
    if (n == 0) {
        printf("Erro: a entrada está vazia.\n");
        return 1;
    }

    /* Normaliza para maiúsculas */
    for (size_t i = 0; i < n; i++) {
        romano[i] = (char)toupper((unsigned char)entrada[ini + i]);
    }
    romano[n] = '\0';

    int total = 0;

    /* Para validar a ordem dos “blocos” (evita casos como IIV, VX, etc.) */
    int ultimo_bloco = 4000;

    char anterior = '\0';
    int repeticoes = 0;

    for (size_t i = 0; i < n; i++) {
        char atual = romano[i];
        int va = valor_romano(atual);

        if (va == 0) {
            printf("Erro: símbolo inválido '%c'. Utilize apenas I, V, X, L, C, D, M.\n", atual);
            return 1;
        }

        /* Contagem de repetições seguidas */
        if (atual == anterior) {
            repeticoes++;
        } else {
            repeticoes = 1;
        }

        /* V, L, D não podem ser repetidos */
        if ((atual == 'V' || atual == 'L' || atual == 'D') && repeticoes > 1) {
            printf("Erro: '%c' não pode ser repetido.\n", atual);
            return 1;
        }

        /* I, X, C, M no máximo 3 vezes seguidas */
        if ((atual == 'I' || atual == 'X' || atual == 'C' || atual == 'M') && repeticoes > 3) {
            printf("Erro: '%c' não pode aparecer mais de 3 vezes seguidas.\n", atual);
            return 1;
        }

        /* Verifica possível subtração (ex: IV, IX, XL, ...) */
        if (i + 1 < n) {
            char seguinte = romano[i + 1];
            int vb = valor_romano(seguinte);

            if (vb == 0) {
                printf("Erro: símbolo inválido '%c'. Utilize apenas I, V, X, L, C, D, M.\n", seguinte);
                return 1;
            }

            if (vb > va) {
                /* Não pode repetir antes de subtrair: IIV é inválido */
                if (repeticoes > 1) {
                    printf("Erro: '%c' não pode ser repetido antes de uma subtração.\n", atual);
                    return 1;
                }

                if (!par_subtrativo_valido(atual, seguinte)) {
                    printf("Erro: par subtrativo inválido '%c%c'.\n", atual, seguinte);
                    return 1;
                }

                int bloco = vb - va;

                /* Ordem inválida (ex: IXC, IXL, etc.) */
                if (bloco > ultimo_bloco) {
                    printf("Erro: ordem inválida no numeral romano.\n");
                    return 1;
                }

                total += bloco;
                ultimo_bloco = bloco;

                /* Consumimos dois símbolos */
                i++;
                anterior = '\0';
                repeticoes = 0;
                continue;
            }
        }

        /* Caso normal: soma e valida ordem */
        if (va > ultimo_bloco) {
            printf("Erro: ordem inválida no numeral romano.\n");
            return 1;
        }

        total += va;
        ultimo_bloco = va;
        anterior = atual;
    }

    printf("Numero romano em decimal: %s = %d\n", romano, total);
    return 0;
}
