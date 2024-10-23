#include <iostream>

// 1. CONST SIGNED CHAR
// signed char: Armazena valores de -128 a 127 (usando 1 byte = 8 bits), ideal para números inteiros pequenos.
// const signed char: Não pode ser alterado após a inicialização.
void exemploConstSignedChar() {
    const signed char sc = -120; // Valor inicial de -120
    std::cout << "Valor de const signed char: " << static_cast<int>(sc) << std::endl;
    // sc = -100; // Isso causaria um erro de compilação, pois sc é const.
}

// 2. CONST UNSIGNED CHAR
// unsigned char: Armazena apenas valores positivos, de 0 a 255.
// const unsigned char: Não pode ser alterado após a inicialização.
void exemploConstUnsignedChar() {
    const unsigned char uc = 200; // Valor inicial 200
    std::cout << "Valor de const unsigned char: " << static_cast<int>(uc) << std::endl;
    // uc = 150; // Isso causaria erro de compilação porque uc é const.
}

// 3. CONST CHAR
// Tipo básico para armazenar um único caractere, ocupa 1 byte.
// Pode armazenar valores de -128 a 127 e representar strings literais.
void exemploConstChar() {
    const char letra = 'A'; // Valor inicial não alterável por ser const
    std::cout << "Valor de const char: " << letra << std::endl;
}

// 4. VOID
// Função que não retorna nenhum valor.
void mostrarMensagem() {
    std::cout << "Essa função não retorna nada." << std::endl;
}

// 5. VOID* GENÉRICO
// Declara um ponteiro genérico que pode apontar para qualquer tipo de dado.
// Ao usá-lo, é necessário fazer casting para o tipo correto.
void exemploVoidPointer() {
    int num = 42;
    void* ptr = &num;  // Ponteiro genérico

    // Para acessar o valor, você precisa fazer um casting para o tipo correto
    std::cout << "Valor de num via void*: " << *(static_cast<int*>(ptr)) << std::endl;
}

int main() {
    exemploConstSignedChar();      // Chama o exemplo de const signed char
    exemploConstUnsignedChar();    // Chama o exemplo de const unsigned char
    exemploConstChar();            // Chama o exemplo de const char
    mostrarMensagem();             // Chama a função que não retorna nada
    exemploVoidPointer();          // Chama o exemplo do ponteiro void

    return 0;
}