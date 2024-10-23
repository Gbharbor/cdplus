#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída para usar printf
#include <stdlib.h> // Inclui a biblioteca padrão para funcionalidades como alocação de memória

int main() { // Função principal do programa, ponto de entrada em C
    int numero1; // Declaração de uma variável inteira chamada numero1
    numero1 = 21; // Atribuição do valor 21 à variável numero1

    // Impressão do valor da variável usando printf
    // O especificador %d é usado para formatar a saída como um inteiro
    printf("O valor do numero é: %d\n", numero1); 

    // Retorno 0 indica que a função main terminou com sucesso
    return 0; 
} // Fim da função main