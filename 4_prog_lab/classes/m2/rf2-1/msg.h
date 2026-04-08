#ifndef MENSAGENS_H
#define MENSAGENS_H

/* Constante do modulo */
#define MENSAGEM_PADRAO "Welcome ao estudo de modularidade em C"

/* Variavel externa (definida noutro modulo) */
extern char *autorDoPrograma;

/* Funcoes publicas do modulo */
void mostrarMensagem(const char *texto);
void mostrarAutor(void);
void mostrarResumoDaAula(void);

#endif