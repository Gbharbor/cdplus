#include <iostream>
#include <limits> // Necessário para ver os limites dos tipos de dados

int main() {
    // 1. Tipo char
    char letra = 'A';  // Caractere padrão
    std::cout << "char (letra): " << letra << " (tamanho: " << sizeof(char) << " byte)" << std::endl;

    // 2. signed char
    signed char s_char = -120;  // Caractere com sinal, valor negativo
    std::cout << "signed char: " << (int)s_char << " (tamanho: " << sizeof(signed char) << " byte)" << std::endl;

    // 3. unsigned char
    unsigned char u_char = 240;  // Caractere sem sinal, valor positivo
    std::cout << "unsigned char: " << (int)u_char << " (tamanho: " << sizeof(unsigned char) << " byte)" << std::endl;

    // 4. short
    short s_num = 32767;  // Valor máximo de um short
    std::cout << "short: " << s_num << " (tamanho: " << sizeof(short) << " bytes)" << std::endl;

    // 5. unsigned short
    unsigned short us_num = 65535;  // Valor máximo de um unsigned short
    std::cout << "unsigned short: " << us_num << " (tamanho: " << sizeof(unsigned short) << " bytes)" << std::endl;

    // 6. int
    int num = 2147483647;  // Valor máximo de um int
    std::cout << "int: " << num << " (tamanho: " << sizeof(int) << " bytes)" << std::endl;

    // 7. unsigned int
    unsigned int u_num = 4294967295;  // Valor máximo de um unsigned int
    std::cout << "unsigned int: " << u_num << " (tamanho: " << sizeof(unsigned int) << " bytes)" << std::endl;

    // 8. long
    long l_num = 2147483647;  // Valor máximo de um long (em sistemas 32 bits)
    std::cout << "long: " << l_num << " (tamanho: " << sizeof(long) << " bytes)" << std::endl;

    // 9. unsigned long
    unsigned long ul_num = 4294967295;  // Valor máximo de um unsigned long
    std::cout << "unsigned long: " << ul_num << " (tamanho: " << sizeof(unsigned long) << " bytes)" << std::endl;

    // 10. long long
    long long ll_num = 9223372036854775807;  // Valor máximo de um long long
    std::cout << "long long: " << ll_num << " (tamanho: " << sizeof(long long) << " bytes)" << std::endl;

    // 11. unsigned long long
    unsigned long long ull_num = 18446744073709551615ULL;  // Valor máximo de um unsigned long long
    std::cout << "unsigned long long: " << ull_num << " (tamanho: " << sizeof(unsigned long long) << " bytes)" << std::endl;

    // 12. float
    float f_num = 3.14159f;  // Número de ponto flutuante de precisão simples
    std::cout << "float: " << f_num << " (tamanho: " << sizeof(float) << " bytes)" << std::endl;

    // 13. double
    double d_num = 3.141592653589793;  // Número de ponto flutuante de precisão dupla
    std::cout << "double: " << d_num << " (tamanho: " << sizeof(double) << " bytes)" << std::endl;

    // 14. long double
    long double ld_num = 3.14159265358979323846L;  // Número de ponto flutuante de precisão estendida
    std::cout << "long double: " << ld_num << " (tamanho: " << sizeof(long double) << " bytes)" << std::endl;

    return 0;
}