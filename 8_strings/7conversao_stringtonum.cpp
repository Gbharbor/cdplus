#include <iostream>
#include <cstdlib> // Para atoi, atof, atoll, strtol, strtod
#include <string>  // Para std::string

int main() {
    // Exemplo de uso de atoi para converter C-string para int
    const char* cstr1 = "12345"; // C-string
    int numero1 = std::atoi(cstr1); // Converte C-string para int
    std::cout << "C-string: " << cstr1 << ", Número (atoi): " << numero1 << std::endl;

    // Exemplo de uso de atof para converter C-string para double
    const char* cstr2 = "123.45"; // C-string
    double numero2 = std::atof(cstr2); // Converte C-string para double
    std::cout << "C-string: " << cstr2 << ", Número (atof): " << numero2 << std::endl;

    // Exemplo de uso de atoll para converter C-string para long long
    const char* cstr3 = "123456789012345"; // C-string
    long long numero3 = std::atoll(cstr3); // Converte C-string para long long
    std::cout << "C-string: " << cstr3 << ", Número (atoll): " << numero3 << std::endl;

    // Exemplo de uso de strtol para conversão robusta de C-string para long
    const char* cstr4 = "12345abc"; // C-string
    char* end; // Ponteiro para armazenar o endereço do caractere após o número
    long numero4 = std::strtol(cstr4, &end, 10); // Converte C-string para long

    // Verifica se houve erro na conversão
    if (end == cstr4) {
        std::cout << "Nenhum número foi convertido (strtol)." << std::endl;
    } else {
        std::cout << "C-string: " << cstr4 << ", Número (strtol): " << numero4 << std::endl;
        std::cout << "Caractere após o número: " << *end << std::endl;
    }

    // Exemplo de uso de strtod para conversão robusta de C-string para double
    const char* cstr5 = "123.45abc"; // C-string
    double numero5 = std::strtod(cstr5, &end); // Converte C-string para double

    // Verifica se houve erro na conversão
    if (end == cstr5) {
        std::cout << "Nenhum número foi convertido (strtod)." << std::endl;
    } else {
        std::cout << "C-string: " << cstr5 << ", Número (strtod): " << numero5 << std::endl;
        std::cout << "Caractere após o número: " << *end << std::endl;
    }

    return 0; // Indica que o programa terminou corretamente
}