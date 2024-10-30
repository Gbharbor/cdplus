#include <stdio.h>
#include <string.h>

int main() {
    // '\0' é o terminador nulo que indica o fim de uma string em C.
    // A especificação %s no printf é utilizada para imprimir strings e funciona até encontrar o terminador nulo.
    // É crucial garantir que todas as strings em C sejam terminadas corretamente com \0 para evitar problemas de memória e comportamentos indesejados.

    /*
    Uso do Operador de Endereço (&)
    Erro Comum:
    Ao utilizar a função scanf para ler uma string, não devemos usar o operador de endereço (&) com o nome do vetor. O vetor já fornece o endereço do seu primeiro elemento, e adicionar & causará um erro.
    Para corrigir o erro, basta remover o operador de endereço (&).
    */

    // Exemplo de leitura de string com erro
    char sPalavra[100]; // Declara um vetor para armazenar a string
    printf("Digite uma palavra: ");
    // ERRO: & não deve ser usado aqui
    scanf("%s", &sPalavra); // Deve ser apenas sPalavra
    printf("\n\nVocê digitou: %s", sPalavra); // Saída: a palavra digitada
    // O tamanho máximo da string que pode ser lida é de 99 caracteres
    // pois a última posição do vetor deve ser reservada para o terminador nulo (\0).

    /*
    Segurança: É importante ter cuidado ao usar scanf("%s", ...), pois essa função não verifica o tamanho da entrada.
    Para evitar estouros de buffer, recomenda-se usar fgets para ler strings:
    O nome de um vetor em C já é um ponteiro para seu primeiro elemento, portanto, não use & ao lê-lo.
    Sempre reserve espaço para o terminador nulo ao trabalhar com strings.
    Para maior segurança ao ler strings, prefira funções como fgets em vez de scanf.
    */

    // Exemplo com fgets para leitura de string de forma segura
    printf("\nUsando fgets para ler a string:\n");
    char sPalavraSegura[100]; // Declara um vetor para armazenar a string
    printf("Digite uma palavra: ");
    fgets(sPalavraSegura, sizeof(sPalavraSegura), stdin); // Lê a string de forma segura
    printf("\n\nVocê digitou: %s", sPalavraSegura);

    // Exemplo de funções da biblioteca <string.h>

    // Exemplo de strlen
    char str1[] = "Hello, world!";
    printf("\n\nExemplo de strlen:\n");
    printf("Comprimento da string: %zu\n", strlen(str1)); // Saída: 13

    // Exemplo de strcpy
    char src[] = "Hello";
    char dest[20];
    strcpy(dest, src); // Copia a string de src para dest
    printf("\nExemplo de strcpy:\n");
    printf("Destino após strcpy: %s\n", dest); // Saída: Hello

    // Exemplo de strncpy
    char src2[] = "Hello, World!";
    char dest2[20];
    strncpy(dest2, src2, 5); // Copia apenas os primeiros 5 caracteres
    dest2[5] = '\0'; // Garante que a string termine corretamente
    printf("\nExemplo de strncpy:\n");
    printf("Destino após strncpy: %s\n", dest2); // Saída: Hello

    // Exemplo de strcat
    char dest3[50] = "Hello";
    char src3[] = " World";
    strcat(dest3, src3); // Concatena src3 ao final de dest3
    printf("\nExemplo de strcat:\n");
    printf("Destino após strcat: %s\n", dest3); // Saída: Hello World

    // Exemplo de strcmp
    char str2[] = "Apple";
    char str3[] = "Banana";
    int cmp_result = strcmp(str2, str3); // Compara str2 e str3
    printf("\nExemplo de strcmp:\n");
    printf("Resultado da comparação: %d\n", cmp_result); // Saída: negativo, pois "Apple" é menor que "Banana"

    // Exemplo de strncmp
    char str4[] = "Hello";
    char str5[] = "Helicopter";
    int cmp_result2 = strncmp(str4, str5, 3); // Compara os primeiros 3 caracteres
    printf("\nExemplo de strncmp:\n");
    printf("Resultado da comparação (primeiros 3 caracteres): %d\n", cmp_result2); // Saída: 0, pois "Hel" é igual em ambos

    // Exemplo de stricmp (ou strcasecmp)
    char str6[] = "hello";
    char str7[] = "HELLO";
    int cmp_result3 = stricmp(str6, str7); // Compara str6 e str7 sem diferenciar maiúsculas de minúsculas
    printf("\nExemplo de stricmp:\n");
    printf("Resultado da comparação (case insensitive): %d\n", cmp_result3); // Saída: 0, pois são iguais

    // Exemplo de strrchr
    char str8[] = "Hello, world!";
    char *last_occurrence = strrchr(str8, 'o'); // Encontra a última ocorrência de 'o'
    printf("\nExemplo de strrchr:\n");
    printf("Última ocorrência de 'o': %s\n", last_occurrence); // Saída: o, world!

    // Exemplo de memcpy
    char src4[] = "Goodbye";
    char dest4[20];
    memcpy(dest4, src4, strlen(src4) + 1); // Copia a string incluindo o terminador nulo
    printf("\nExemplo de memcpy:\n");
    printf("Destino após memcpy: %s\n", dest4); // Saída: Goodbye

    // Exemplo de printf e sprintf
    int age = 25;
    char buffer[50];

    // Usando printf
    printf("\nExemplo de printf:\n");
    printf("Idade: %d\n", age); // Saída: Idade: 25

    // Usando sprintf
    sprintf(buffer, "Idade: %d", age); // Formata a string e armazena em buffer
    printf("\nExemplo de sprintf:\n");
    printf("%s\n", buffer); // Saída: Idade: 25

    return 0; // Indica que o programa terminou corretamente
}