#include <stdio.h>

/*
    Aula 03 - Estruturas de Controle e Repetição
    switch, for, while, do-while, break, continue e goto
*/

/* =========================================================
   Tópico 1 - Estrutura switch
   ========================================================= */
void exemploSwitch() {

    int x = 10;

    printf("=== Estrutura switch ===\n");

    switch (x) {

        case 10:
            printf("x é igual a 10\n");
            break;

        case 20:
            printf("x é igual a 20\n");
            break;

        default:
            printf("x não é 10 nem 20\n");
            break;
    }

    printf("\n");
}

/* =========================================================
   Tópico 2 - Laço for
   ========================================================= */
void exemploFor() {

    printf("=== Laço for ===\n");

    for (int i = 0; i < 5; i++) {

        printf("i = %d\n", i);

    }

    printf("\n");
}

/* =========================================================
   Tópico 3 - Laço while
   ========================================================= */
void exemploWhile() {

    printf("=== Laço while ===\n");

    int i = 0;

    while (i < 5) {

        printf("i = %d\n", i);
        i++;

    }

    printf("\n");
}

/* =========================================================
   Tópico 4 - Laço do-while
   ========================================================= */
void exemploDoWhile() {

    printf("=== Laço do-while ===\n");

    int i = 0;

    do {

        printf("i = %d\n", i);
        i++;

    } while (i < 5);

    printf("\n");
}

/* =========================================================
   Tópico 5 - Uso do break
   ========================================================= */
void exemploBreak() {

    printf("=== Uso do break ===\n");

    for (int i = 0; i < 10; i++) {

        if (i == 5) {

            break;

        }

        printf("i = %d\n", i);
    }

    printf("\n");
}

/* =========================================================
   Tópico 6 - Uso do continue
   ========================================================= */
void exemploContinue() {

    printf("=== Uso do continue ===\n");

    for (int i = 0; i < 5; i++) {

        if (i == 2) {

            continue;

        }

        printf("i = %d\n", i);

    }

    printf("\n");
}

/* =========================================================
   Tópico 7 - Uso do goto
   ========================================================= */
void exemploGoto() {

    printf("=== Uso do goto ===\n");

    int x = 10;

    if (x == 10) {

        goto etiqueta;

    }

    printf("Este código será ignorado.\n");

etiqueta:

    printf("Salto realizado com goto!\n");

    printf("\n");
}

/* =========================================================
   Tópico 8 - Classificação de idade
   ========================================================= */
void classificarIdade() {

    int idade;

    printf("=== Classificação de idade ===\n");
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 0 && idade <= 12) {

        printf("Você é uma criança.\n");

    }
    else if (idade <= 19) {

        printf("Você é um adolescente.\n");

    }
    else if (idade <= 64) {

        printf("Você é um adulto.\n");

    }
    else {

        printf("Você é um idoso.\n");

    }

    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main() {

    exemploSwitch();
    exemploFor();
    exemploWhile();
    exemploDoWhile();
    exemploBreak();
    exemploContinue();
    exemploGoto();
    classificarIdade();

    return 0;
}