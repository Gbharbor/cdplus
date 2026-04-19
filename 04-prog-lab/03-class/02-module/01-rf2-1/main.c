#include <stdio.h>
#include "mensagens.h"

/* Definicao real da variavel externa */
char *autorDoPrograma = "Guilherme / Harbor";

/* Variavel global */
int numeroDaAula = 21;

/* Prototipo */
void explicarScope(void);

int main(void)
{
    printf("Programa iniciado.\n\n");

    mostrarMensagem(MENSAGEM_PADRAO);

    printf("\n");

    mostrarAutor();

    printf("\nNumero da aula: %d\n\n", numeroDaAula);

    explicarScope();

    printf("\n");

    mostrarResumoDaAula();

    printf("\nPrograma terminado.\n");

    return 0;
}

void explicarScope(void)
{
    printf("=== SCOPE ===\n");

    printf("Global numeroDaAula = %d\n", numeroDaAula);

    int exemploLocal = 100;

    printf("Local exemploLocal = %d\n", exemploLocal);
}