#include <stdio.h>
#include <string.h>

#define MAX 100

/* função que verifica se uma palavra é palíndromo */
int eh_palindromo(char palavra[]) {

    int inicio = 0;
    int fim = strlen(palavra) - 1;

    while (inicio < fim) {

        if (palavra[inicio] != palavra[fim]) {
            return 0;   // não é palíndromo
        }

        inicio++;
        fim--;
    }

    return 1;  // é palíndromo
}

int main(void) {

    FILE *ficheiro;
    char palavra[MAX];

    /* abrir ficheiro */
    ficheiro = fopen("e2text.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return 1;
    }

    /* ler palavras do ficheiro */
    while (fscanf(ficheiro, "%s", palavra) == 1) {

        int tamanho = strlen(palavra);

        /* verificar tamanho entre 3 e 10 */
        if (tamanho >= 3 && tamanho <= 10) {

            if (eh_palindromo(palavra)) {
                printf("Palindromo encontrado: %s\n", palavra);
            }

        }
    }

    fclose(ficheiro);

    return 0;
}
