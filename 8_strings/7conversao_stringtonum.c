#include <stdio.h>   // Necessário para printf e scanf
#include <stdlib.h>  // Necessário para atoi, atof, atoll, strtol, strtod

int main() {
    // Exemplo de uso de atoi para converter C-string para int
    const char* cstr1 = "12345"; // C-string
    int numero1 = atoi(cstr1);    // Converte C-string para int
    printf("C-string: %s, Número (atoi): %d\n", cstr1, numero1);

    // Exemplo de uso de atof para converter C-string para double
    const char* cstr2 = "123.45"; // C-string
    double numero2 = atof(cstr2);  // Converte C-string para double
    printf("C-string: %s, Número (atof): %f\n", cstr2, numero2);

    // Exemplo de uso de atoll para converter C-string para long long
    const char* cstr3 = "123456789012345"; // C-string
    long long numero3 = atoll(cstr3);      // Converte C-string para long long
    printf("C-string: %s, Número (atoll): %lld\n", cstr3, numero3);

    // Exemplo de uso de strtol para conversão robusta de C-string para long
    const char* cstr4 = "12345abc"; // C-string
    char* end;                      // Ponteiro para armazenar o endereço do caractere após o número
    long numero4 = strtol(cstr4, &end, 10); // Converte C-string para long

    // Verifica se houve erro na conversão
    if (end == cstr4) {
        printf("Nenhum número foi convertido (strtol).\n");
    } else {
        printf("C-string: %s, Número (strtol): %ld\n", cstr4, numero4);
        printf("Caractere após o número: %c\n", *end);
    }

    // Exemplo de uso de strtod para conversão robusta de C-string para double
    const char* cstr5 = "123.45abc"; // C-string
    double numero5 = strtod(cstr5, &end); // Converte C-string para double

    // Verifica se houve erro na conversão
    if (end == cstr5) {
        printf("Nenhum número foi convertido (strtod).\n");
    } else {
        printf("C-string: %s, Número (strtod): %f\n", cstr5, numero5);
        printf("Caractere após o número: %c\n", *end);
    }

    return 0; // Indica que o programa terminou corretamente
}
