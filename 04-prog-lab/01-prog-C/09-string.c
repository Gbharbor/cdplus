#include <stdio.h>
#include <string.h>
#include <strings.h> /* para strcasecmp em sistemas Unix/macOS/Linux */

/*
    Aula 09 - Strings em C
    Conceito, inicialização, leitura, segurança e funções da biblioteca string.h
*/

/* =========================================================
   Tópico 1 - Conceito e inicialização de strings
   ========================================================= */
void conceitoString(void) {
    /*
        Em C, string é um vetor de caracteres terminado por '\0'.

        Exemplo:
        char nome[] = "Ana";

        Na memória, isso seria algo como:
        'A' 'n' 'a' '\0'

        O '\0' é o terminador nulo, que indica onde a string termina.
        O printf com %s imprime os caracteres até encontrar '\0'.

        Portanto, toda string em C precisa estar corretamente terminada.
    */

    char exemplo[] = "Ana";

    /*
        Inicialização com tamanho definido:
        o vetor pode armazenar até 19 caracteres + '\0'
    */
    char str1[20] = "Olá, mundo!";

    /*
        Inicialização com tamanho automático:
        o compilador calcula o tamanho exato
    */
    char str2[] = "Olá, C!";

    printf("=== Tópico 1 - Conceito e inicialização de strings ===\n");
    printf("String de exemplo: %s\n", exemplo);
    printf("Comprimento com strlen: %zu\n", strlen(exemplo));
    printf("String com tamanho definido: %s\n", str1);
    printf("String com tamanho automático: %s\n", str2);
    printf("\n");
}

/* =========================================================
   Tópico 2 - Uso do scanf com strings
   ========================================================= */
void leituraComScanf(void) {
    char sPalavra[100];

    /*
        Erro comum:
        scanf("%s", &sPalavra);

        Isso está errado porque o nome do vetor já representa
        o endereço do primeiro elemento.

        Correto:
        scanf("%s", sPalavra);

        Outro ponto importante:
        scanf("%s", ...) lê apenas até o primeiro espaço.
        Então ele funciona bem para uma palavra, mas não para frases.
    */

    printf("=== Tópico 2 - Leitura com scanf ===\n");
    printf("Digite uma palavra: ");
    scanf("%99s", sPalavra); /* limita a leitura para evitar overflow */

    printf("Você digitou: %s\n", sPalavra);
    printf("\n");
}

/* =========================================================
   Tópico 3 - Uso do fgets para leitura segura
   ========================================================= */
void leituraComFgets(void) {
    char sPalavraSegura[100];

    /*
        fgets é mais seguro que scanf("%s") para ler texto,
        porque permite controlar o tamanho máximo da leitura.

        Além disso, fgets pode ler espaços.
    */

    /* limpa o ENTER que pode ter ficado no buffer do scanf anterior */
    getchar();

    printf("=== Tópico 3 - Leitura com fgets ===\n");
    printf("Digite uma frase ou palavra: ");
    fgets(sPalavraSegura, sizeof(sPalavraSegura), stdin);

    /*
        O fgets normalmente guarda o '\n' se houver espaço.
        Então podemos removê-lo, se necessário.
    */
    sPalavraSegura[strcspn(sPalavraSegura, "\n")] = '\0';

    printf("Você digitou: %s\n", sPalavraSegura);
    printf("\n");
}

/* =========================================================
   Tópico 4 - strlen
   ========================================================= */
void exemploStrlen(void) {
    char str1[] = "Hello, world!";

    printf("=== Tópico 4 - strlen ===\n");
    printf("String: %s\n", str1);
    printf("Comprimento da string: %zu\n", strlen(str1));
    printf("\n");
}

/* =========================================================
   Tópico 5 - strcpy
   ========================================================= */
void exemploStrcpy(void) {
    char src[] = "Hello";
    char dest[20];

    strcpy(dest, src);

    printf("=== Tópico 5 - strcpy ===\n");
    printf("Origem: %s\n", src);
    printf("Destino após strcpy: %s\n", dest);
    printf("\n");
}

/* =========================================================
   Tópico 6 - strncpy
   ========================================================= */
void exemploStrncpy(void) {
    char src2[] = "Hello, World!";
    char dest2[20];

    strncpy(dest2, src2, 5);
    dest2[5] = '\0'; /* garante o terminador nulo */

    printf("=== Tópico 6 - strncpy ===\n");
    printf("Origem: %s\n", src2);
    printf("Destino após strncpy: %s\n", dest2);
    printf("\n");
}

/* =========================================================
   Tópico 7 - strcat
   ========================================================= */
void exemploStrcat(void) {
    char dest3[50] = "Hello";
    char src3[] = " World";

    strcat(dest3, src3);

    printf("=== Tópico 7 - strcat ===\n");
    printf("Resultado após strcat: %s\n", dest3);
    printf("\n");
}

/* =========================================================
   Tópico 8 - strcmp
   ========================================================= */
void exemploStrcmp(void) {
    char str2[] = "Apple";
    char str3[] = "Banana";
    int cmpResult = strcmp(str2, str3);

    printf("=== Tópico 8 - strcmp ===\n");
    printf("Comparando \"%s\" com \"%s\"\n", str2, str3);
    printf("Resultado: %d\n", cmpResult);
    printf("Se for negativo, a primeira string é menor.\n");
    printf("Se for zero, são iguais.\n");
    printf("Se for positivo, a primeira string é maior.\n");
    printf("\n");
}

/* =========================================================
   Tópico 9 - strncmp
   ========================================================= */
void exemploStrncmp(void) {
    char str4[] = "Hello";
    char str5[] = "Helicopter";
    int cmpResult2 = strncmp(str4, str5, 3);

    printf("=== Tópico 9 - strncmp ===\n");
    printf("Comparando os 3 primeiros caracteres de \"%s\" e \"%s\"\n", str4, str5);
    printf("Resultado: %d\n", cmpResult2);
    printf("\n");
}

/* =========================================================
   Tópico 10 - strcasecmp
   ========================================================= */
void exemploStrcasecmp(void) {
    char str6[] = "hello";
    char str7[] = "HELLO";
    int cmpResult3 = strcasecmp(str6, str7);

    /*
        Em muitos materiais aparece stricmp, mas ela não é padrão da linguagem C.
        Em sistemas Unix/macOS/Linux, o equivalente mais comum é strcasecmp.
    */

    printf("=== Tópico 10 - strcasecmp ===\n");
    printf("Comparando \"%s\" e \"%s\" sem diferenciar maiúsculas/minúsculas\n", str6, str7);
    printf("Resultado: %d\n", cmpResult3);
    printf("\n");
}

/* =========================================================
   Tópico 11 - strchr
   ========================================================= */
void exemploStrchr(void) {
    char str8[] = "Hello, world!";
    char *firstOccurrence = strchr(str8, 'o');

    printf("=== Tópico 11 - strchr ===\n");
    if (firstOccurrence != NULL) {
        printf("Primeira ocorrência de 'o': %s\n", firstOccurrence);
    } else {
        printf("Caractere não encontrado.\n");
    }
    printf("\n");
}

/* =========================================================
   Tópico 12 - strrchr
   ========================================================= */
void exemploStrrchr(void) {
    char str9[] = "Hello, world!";
    char *lastOccurrence = strrchr(str9, 'o');

    printf("=== Tópico 12 - strrchr ===\n");
    if (lastOccurrence != NULL) {
        printf("Última ocorrência de 'o': %s\n", lastOccurrence);
    } else {
        printf("Caractere não encontrado.\n");
    }
    printf("\n");
}

/* =========================================================
   Tópico 13 - memcpy
   ========================================================= */
void exemploMemcpy(void) {
    char src4[] = "Goodbye";
    char dest4[20];

    memcpy(dest4, src4, strlen(src4) + 1);

    printf("=== Tópico 13 - memcpy ===\n");
    printf("Destino após memcpy: %s\n", dest4);
    printf("\n");
}

/* =========================================================
   Tópico 14 - printf, sprintf e snprintf
   ========================================================= */
void exemploPrintfSprintf(void) {
    int age = 25;
    char buffer[50];
    char bufferSeguro[50];

    printf("=== Tópico 14 - printf, sprintf e snprintf ===\n");

    printf("Usando printf:\n");
    printf("Idade: %d\n", age);

    sprintf(buffer, "Idade: %d", age);
    printf("Usando sprintf:\n");
    printf("%s\n", buffer);

    snprintf(bufferSeguro, sizeof(bufferSeguro), "Idade: %d", age);
    printf("Usando snprintf:\n");
    printf("%s\n", bufferSeguro);

    /*
        snprintf é mais seguro que sprintf,
        porque limita a quantidade de caracteres no buffer.
    */

    printf("\n");
}

/* =========================================================
   Tópico 15 - Observações finais sobre strings
   ========================================================= */
void observacoesStrings(void) {
    printf("=== Tópico 15 - Observações finais ===\n");
    printf("1. Toda string em C deve terminar com '\\0'.\n");
    printf("2. O nome do vetor já representa um endereço, então não usar & com %%s.\n");
    printf("3. scanf(\"%%s\") lê apenas até o primeiro espaço.\n");
    printf("4. fgets é mais indicado para ler frases completas.\n");
    printf("5. char str[20] pode armazenar até 19 caracteres + '\\0'.\n");
    printf("6. Funções de string ficam principalmente em <string.h>.\n");
    printf("7. Em Unix/macOS/Linux, strcasecmp é mais comum que stricmp.\n");
    printf("8. snprintf é mais seguro que sprintf.\n");
    printf("9. Sempre tomar cuidado com o tamanho do vetor para evitar overflow.\n");
    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main(void) {
    conceitoString();
    leituraComScanf();
    leituraComFgets();
    exemploStrlen();
    exemploStrcpy();
    exemploStrncpy();
    exemploStrcat();
    exemploStrcmp();
    exemploStrncmp();
    exemploStrcasecmp();
    exemploStrchr();
    exemploStrrchr();
    exemploMemcpy();
    exemploPrintfSprintf();
    observacoesStrings();

    return 0;
}