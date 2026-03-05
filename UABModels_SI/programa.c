#include <ctype.h>   // isspace, toupper
#include <stdio.h>   // printf, fgets
#include <string.h>  // strlen, strcspn

// Tamanho máximo da linha lida do terminal (inclui terminador '\0').
#define MAX_INPUT 128

// Converte um símbolo romano individual no seu valor decimal.
// Retorna 0 quando o caractere não é um símbolo romano válido.
static int valor_romano(char c) {
    switch (c) {
        case 'I': return 1;     // I = 1
        case 'V': return 5;     // V = 5
        case 'X': return 10;    // X = 10
        case 'L': return 50;    // L = 50
        case 'C': return 100;   // C = 100
        case 'D': return 500;   // D = 500
        case 'M': return 1000;  // M = 1000
        default: return 0;      // Qualquer outro símbolo é inválido
    }
}

// Verifica se um par subtrativo é permitido pelas regras clássicas.
// Permitidos: IV, IX, XL, XC, CD, CM.
static int par_subtrativo_valido(char atual, char seguinte) {
    return (atual == 'I' && (seguinte == 'V' || seguinte == 'X')) ||
           (atual == 'X' && (seguinte == 'L' || seguinte == 'C')) ||
           (atual == 'C' && (seguinte == 'D' || seguinte == 'M'));
}

int main(void) {
    // Buffer original da entrada e buffer final (normalizado em maiúsculas).
    char entrada[MAX_INPUT];
    char romano[MAX_INPUT];

    // 1) Lê o numeral romano do utilizador.
    printf("Introduza um numeral romano: ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        // Erro de leitura (EOF/erro de stream).
        printf("Erro: não foi possível ler a entrada.\n");
        return 1;
    }

    // Remove o '\n' do final, caso exista.
    entrada[strcspn(entrada, "\n")] = '\0';

    // 2) Remove espaços no início da string.
    size_t inicio = 0;
    while (entrada[inicio] != '\0' && isspace((unsigned char)entrada[inicio])) {
        inicio++;
    }

    // Remove espaços no fim da string.
    size_t fim = strlen(entrada);
    while (fim > inicio && isspace((unsigned char)entrada[fim - 1])) {
        fim--;
    }

    // Calcula o tamanho útil da entrada (sem espaços nas extremidades).
    size_t tamanho = fim - inicio;
    if (tamanho == 0) {
        // Se não sobrou nada, a entrada está vazia.
        printf("Erro: a entrada está vazia.\n");
        return 1;
    }

    // Copia para 'romano' convertendo tudo para maiúsculas.
    // Assim aceitamos entrada como "mcmlxxix" e tratamos como "MCMLXXIX".
    for (size_t i = 0; i < tamanho; i++) {
        romano[i] = (char)toupper((unsigned char)entrada[inicio + i]);
    }
    romano[tamanho] = '\0';

    // Variáveis de controlo da conversão.
    int total = 0;              // Soma decimal final.
    int ultimo_bloco = 4000;    // Guarda o último bloco para validar a ordem.
    char anterior = '\0';       // Último símbolo processado.
    int repeticoes = 0;         // Número de repetições consecutivas do símbolo atual.

    // 3) Percorre cada símbolo romano para validar e converter.
    for (size_t i = 0; i < tamanho; i++) {
        char atual = romano[i];
        int valor_atual = valor_romano(atual);

        // Se valor_atual = 0, o símbolo não pertence ao conjunto I,V,X,L,C,D,M.
        if (valor_atual == 0) {
            printf("Erro: símbolo inválido '%c'. Utilize apenas I, V, X, L, C, D, M.\n", atual);
            return 1;
        }

        // Atualiza contador de repetições consecutivas.
        if (atual == anterior) {
            repeticoes++;
        } else {
            repeticoes = 1;
        }

        // Regra: V, L e D nunca podem repetir.
        if ((atual == 'V' || atual == 'L' || atual == 'D') && repeticoes > 1) {
            printf("Erro: '%c' não pode ser repetido.\n", atual);
            return 1;
        }

        // Regra: I, X, C e M podem repetir no máximo 3 vezes seguidas.
        if ((atual == 'I' || atual == 'X' || atual == 'C' || atual == 'M') && repeticoes > 3) {
            printf("Erro: '%c' não pode aparecer mais de 3 vezes seguidas.\n", atual);
            return 1;
        }

        // Se existir próximo símbolo, verifica se há caso subtrativo.
        if (i + 1 < tamanho) {
            char seguinte = romano[i + 1];
            int valor_seguinte = valor_romano(seguinte);

            // Segurança extra: valida também o próximo símbolo.
            if (valor_seguinte == 0) {
                printf("Erro: símbolo inválido '%c'. Utilize apenas I, V, X, L, C, D, M.\n", seguinte);
                return 1;
            }

            // Caso subtrativo: símbolo menor antes de símbolo maior (ex.: IV, IX, CM).
            if (valor_seguinte > valor_atual) {
                // Não pode haver repetição antes da subtração (ex.: IIV é inválido).
                if (repeticoes > 1) {
                    printf("Erro: '%c' não pode ser repetido antes de uma subtração.\n", atual);
                    return 1;
                }

                // O par precisa ser um dos pares subtrativos permitidos.
                if (!par_subtrativo_valido(atual, seguinte)) {
                    printf("Erro: par subtrativo inválido '%c%c'.\n", atual, seguinte);
                    return 1;
                }

                // Calcula o valor do bloco subtrativo (ex.: IX = 9).
                int bloco = valor_seguinte - valor_atual;

                // Valida ordem global (evita construções inválidas em sequência).
                if (bloco > ultimo_bloco) {
                    printf("Erro: ordem inválida no numeral romano.\n");
                    return 1;
                }

                // Soma o bloco subtrativo e atualiza o último bloco.
                total += bloco;
                ultimo_bloco = bloco;

                // Pula o próximo símbolo, pois ele já foi consumido no par.
                i++;

                // Reseta controlo de repetição para o próximo ciclo.
                anterior = '\0';
                repeticoes = 0;
                continue;
            }
        }

        // Caso aditivo normal (sem subtração): apenas soma valor atual.
        // Também valida ordem para evitar sequências crescentes inválidas.
        if (valor_atual > ultimo_bloco) {
            printf("Erro: ordem inválida no numeral romano.\n");
            return 1;
        }

        total += valor_atual;
        ultimo_bloco = valor_atual;
        anterior = atual;
    }

    // 4) Saída final no formato solicitado.
    printf("%s = %d\n", romano, total);
    return 0;
}
