#include <stdio.h>
#include "mensagens.h"

/* Variavel global privada do modulo */
static int totalMensagensMostradas = 0;

/* Funcao interna (privada) */
static void incrementarContador(void)
{
    totalMensagensMostradas++;
}

/* Funcao publica */
void mostrarMensagem(const char *texto)
{
    incrementarContador();

    printf("Mensagem: %s\n", texto);
    printf("Total: %d\n", totalMensagensMostradas);
}

/* Usa variavel externa (definida noutro modulo) */
void mostrarAutor(void)
{
    incrementarContador();

    printf("Autor: %s\n", autorDoPrograma);
    printf("Total: %d\n", totalMensagensMostradas);
}

void mostrarResumoDaAula(void)
{
    incrementarContador();

    printf("\n=== RESUMO ===\n");
    printf("Modulos | .h declara | .c implementa | extern | static\n");
    printf("Total: %d\n", totalMensagensMostradas);
}