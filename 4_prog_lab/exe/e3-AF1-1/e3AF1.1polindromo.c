#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALINDROMOS 10000

typedef struct {
    int ini_original;
    int fim_original;
    int len_normalizado;
} Palindromo;

/* =========================================================
   Função: remover_acentos
   Objetivo:
   - Converter caracteres acentuados comuns em equivalente sem acento.
   - Trabalha com UTF-8 nos casos mais frequentes do português.
   - Retorna:
       * caractere ASCII equivalente, se reconhecido
       * '\0' se o byte atual fizer parte de sequência UTF-8 ignorada
   ========================================================= */
char remover_acentos_utf8(const unsigned char *s, int *consumidos) {
    *consumidos = 1;

    /* Caracteres ASCII normais */
    if (s[0] < 128) {
        return (char)s[0];
    }

    /* UTF-8 mais comum em português:
       letras acentuadas de 2 bytes.
    */
    if (s[0] == 0xC3) {
        *consumidos = 2;
        switch (s[1]) {
            /* a */
            case 0xA1: case 0xA0: case 0xA2: case 0xA3: case 0xA4:
            case 0x81: case 0x80: case 0x82: case 0x83: case 0x84:
                return 'a';

            /* e */
            case 0xA9: case 0xA8: case 0xAA: case 0xAB:
            case 0x89: case 0x88: case 0x8A: case 0x8B:
                return 'e';

            /* i */
            case 0xAD: case 0xAC: case 0xAE: case 0xAF:
            case 0x8D: case 0x8C: case 0x8E: case 0x8F:
                return 'i';

            /* o */
            case 0xB3: case 0xB2: case 0xB4: case 0xB5: case 0xB6:
            case 0x93: case 0x92: case 0x94: case 0x95: case 0x96:
                return 'o';

            /* u */
            case 0xBA: case 0xB9: case 0xBB: case 0xBC:
            case 0x9A: case 0x99: case 0x9B: case 0x9C:
                return 'u';

            /* c */
            case 0xA7: case 0x87:
                return 'c';

            /* n */
            case 0xB1: case 0x91:
                return 'n';

            default:
                return '\0';
        }
    }

    /* Não reconhecido */
    return '\0';
}

/* =========================================================
   Função: eh_alnum_normalizado
   Objetivo:
   - Dizer se o caractere, depois de normalizado, conta para o palíndromo.
   - Só letras e dígitos interessam.
   ========================================================= */
int eh_alnum_normalizado(char c) {
    return isalnum((unsigned char)c);
}

/* =========================================================
   Função: ler_ficheiro
   Objetivo:
   - Ler o ficheiro inteiro para memória.
   - Retorna ponteiro para string alocada dinamicamente.
   ========================================================= */
char *ler_ficheiro(const char *nome) {
    /* Tenta abrir o ficheiro em modo de leitura binária */
    FILE *f = fopen(nome, "rb");
    if (!f) return NULL; /* Se falhar, devolve NULL */

    /* Vai para o fim do ficheiro para descobrir o tamanho */
    fseek(f, 0, SEEK_END);

    /* Guarda a posição atual, que corresponde ao tamanho em bytes */
    long tamanho = ftell(f);

    /* Volta ao início para começar a leitura */
    rewind(f);

    /* Aloca memória para o conteúdo + 1 byte para '\0' */
    char *buffer = (char *)malloc(tamanho + 1);
    if (!buffer) {
        fclose(f);      /* Fecha o ficheiro antes de sair */
        return NULL;    /* Falha na alocação */
    }

    /* Lê o conteúdo do ficheiro para o buffer */
    fread(buffer, 1, tamanho, f);

    /* Termina a string em C */
    buffer[tamanho] = '\0';

    /* Fecha o ficheiro */
    fclose(f);

    /* Devolve o texto lido */
    return buffer;
}

/* =========================================================
   Função: normalizar_texto
   Objetivo:
   - Criar versão normalizada do texto:
       * minúsculas
       * sem acentos
       * sem espaços/pontuação
   - map[i] guarda a posição no texto original do caractere norm[i].
   ========================================================= */
void normalizar_texto(const char *original, char **norm_out, int **map_out, int *n_out) {
    int capacidade = (int)strlen(original) + 1;
    char *norm = (char *)malloc(capacidade);
    int *map = (int *)malloc(capacidade * sizeof(int));

    if (!norm || !map) {
        free(norm);
        free(map);
        *norm_out = NULL;
        *map_out = NULL;
        *n_out = 0;
        return;
    }

    int i = 0, k = 0;
    while (original[i] != '\0') {
        int consumidos = 1;
        char c = remover_acentos_utf8((const unsigned char *)&original[i], &consumidos);

        if (c != '\0') {
            c = (char)tolower((unsigned char)c);
            if (eh_alnum_normalizado(c)) {
                norm[k] = c;
                map[k] = i;
                k++;
            }
        }

        i += consumidos;
    }

    norm[k] = '\0';

    *norm_out = norm;
    *map_out = map;
    *n_out = k;
}

/* =========================================================
   Função: expandir_centro
   Objetivo:
   - Expandir palíndromos num dado centro na string normalizada.
   - Se encontrar palíndromo com comprimento >= 3, guarda.
   ========================================================= */
void expandir_centro(
    const char *norm, int n, int *map,
    int esq, int dir,
    Palindromo pals[], int *total
) {
    while (esq >= 0 && dir < n && norm[esq] == norm[dir]) {
        int comp = dir - esq + 1;
        if (comp >= 3 && *total < MAX_PALINDROMOS) {
            pals[*total].ini_original = map[esq];
            pals[*total].fim_original = map[dir];
            pals[*total].len_normalizado = comp;
            (*total)++;
        }
        esq--;
        dir++;
    }
}

/* =========================================================
   Função: comparar_palindromos
   Critério:
   1. início crescente
   2. fim decrescente
   3. maior comprimento primeiro
   ========================================================= */
int comparar_palindromos(const void *a, const void *b) {
    const Palindromo *p1 = (const Palindromo *)a;
    const Palindromo *p2 = (const Palindromo *)b;

    if (p1->ini_original != p2->ini_original)
        return p1->ini_original - p2->ini_original;

    if (p1->fim_original != p2->fim_original)
        return p2->fim_original - p1->fim_original;

    return p2->len_normalizado - p1->len_normalizado;
}

/* =========================================================
   Função: contido_em
   Objetivo:
   - Verificar se p1 está contido em p2.
   ========================================================= */
int contido_em(Palindromo p1, Palindromo p2) {
    return p1.ini_original >= p2.ini_original &&
           p1.fim_original <= p2.fim_original &&
           (p1.ini_original != p2.ini_original || p1.fim_original != p2.fim_original);
}

/* =========================================================
   Programa principal
   ========================================================= */
int main(void) {
    char nome_ficheiro[256];

    printf("Nome do ficheiro: ");
    if (scanf("%255s", nome_ficheiro) != 1) {
        printf("Erro ao ler o nome do ficheiro.\n");
        return 1;
    }

    char *original = ler_ficheiro(nome_ficheiro);
    if (!original) {
        printf("Erro: nao foi possivel abrir o ficheiro.\n");
        return 1;
    }

    char *norm = NULL;
    int *map = NULL;
    int n = 0;

    normalizar_texto(original, &norm, &map, &n);
    if (!norm || !map) {
        printf("Erro de memoria.\n");
        free(original);
        return 1;
    }

    Palindromo pals[MAX_PALINDROMOS];
    int total = 0;

    /* Procurar palíndromos de comprimento ímpar e par */
    for (int i = 0; i < n; i++) {
        expandir_centro(norm, n, map, i, i, pals, &total);       /* ímpar */
        expandir_centro(norm, n, map, i, i + 1, pals, &total);   /* par */
    }

    if (total == 0) {
        printf("\nNao foram encontrados palindromos.\n");
        free(original);
        free(norm);
        free(map);
        return 0;
    }

    /* Ordenar para facilitar eliminação dos contidos */
    qsort(pals, total, sizeof(Palindromo), comparar_palindromos);

    printf("\nPalindromos encontrados (mais abrangentes):\n\n");

    for (int i = 0; i < total; i++) {
        int contido = 0;

        for (int j = 0; j < total; j++) {
            if (i != j && contido_em(pals[i], pals[j])) {
                contido = 1;
                break;
            }
        }

        if (!contido) {
            for (int k = pals[i].ini_original; k <= pals[i].fim_original; k++) {
                putchar(original[k]);
            }
            putchar('\n');
        }
    }

    free(original);
    free(norm);
    free(map);

    return 0;
}
