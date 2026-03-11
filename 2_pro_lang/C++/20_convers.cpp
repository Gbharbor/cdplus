// ------------------------------------------------------------
// Conversão de C-strings para números em C++
// Demonstra o uso de atoi, atof, atoll, strtol e strtod
// ------------------------------------------------------------

#include <iostream>
#include <cstdlib> // atoi, atof, atoll, strtol, strtod
#include <string>

int main() {

    // --------------------------------------------------------
    // 1. Conversão usando atoi (string -> int)
    // --------------------------------------------------------
    const char* cstr1 = "12345";

    int numero1 = std::atoi(cstr1);

    std::cout << "C-string: " << cstr1
              << " | Numero convertido (atoi): "
              << numero1 << std::endl;


    // --------------------------------------------------------
    // 2. Conversão usando atof (string -> double)
    // --------------------------------------------------------
    const char* cstr2 = "123.45";

    double numero2 = std::atof(cstr2);

    std::cout << "C-string: " << cstr2
              << " | Numero convertido (atof): "
              << numero2 << std::endl;


    // --------------------------------------------------------
    // 3. Conversão usando atoll (string -> long long)
    // --------------------------------------------------------
    const char* cstr3 = "123456789012345";

    long long numero3 = std::atoll(cstr3);

    std::cout << "C-string: " << cstr3
              << " | Numero convertido (atoll): "
              << numero3 << std::endl;


    // --------------------------------------------------------
    // 4. Conversão usando strtol (mais robusta)
    // --------------------------------------------------------
    const char* cstr4 = "12345abc";

    char* end; // aponta para o primeiro caractere não convertido

    long numero4 = std::strtol(cstr4, &end, 10);

    if (end == cstr4) {
        std::cout << "Nenhum numero foi convertido (strtol)." << std::endl;
    }
    else {
        std::cout << "C-string: " << cstr4
                  << " | Numero convertido (strtol): "
                  << numero4 << std::endl;

        std::cout << "Primeiro caractere apos o numero: "
                  << *end << std::endl;
    }


    // --------------------------------------------------------
    // 5. Conversão usando strtod (string -> double robusto)
    // --------------------------------------------------------
    const char* cstr5 = "123.45abc";

    double numero5 = std::strtod(cstr5, &end);

    if (end == cstr5) {
        std::cout << "Nenhum numero foi convertido (strtod)." << std::endl;
    }
    else {
        std::cout << "C-string: " << cstr5
                  << " | Numero convertido (strtod): "
                  << numero5 << std::endl;

        std::cout << "Primeiro caractere apos o numero: "
                  << *end << std::endl;
    }

    return 0;
}