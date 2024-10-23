#include <stdio.h>

/*
 * A função printf permite definir o tamanho mínimo de saída para variáveis,
 * preenchendo espaços vazios à esquerda ou zeros, além de ajustar a precisão
 * para números de ponto flutuante. 
 */

// 1. Largura mínima para inteiros
void imprimirNumeroComLarguraMinima(int num) {
    printf("Número com largura 5: '%5d'\n", num); // Preenche com espaços à esquerda
}

// 2. Largura mínima para inteiros com zeros à esquerda
void imprimirNumeroComZeros(int num) {
    printf("Número com zeros à esquerda (5 dígitos): '%05d'\n", num); // Preenche com zeros à esquerda
}

// 3. Alinhamento à esquerda
void imprimirNumeroAlinhadoEsquerda(int num) {
    printf("Alinhado à esquerda (largura 5): '%-5d'\n", num); // Alinha à esquerda
}

// 4. Precisão para ponto flutuante
void imprimirFloatComPrecisao(float valor) {
    printf("Número flutuante com 2 casas decimais: '%.2f'\n", valor); // Define precisão de 2 casas decimais
}

// 5. Largura mínima e precisão combinadas
void imprimirFloatComLarguraEPrecisao(float valor) {
    printf("Número flutuante com largura 8 e 2 casas decimais: '%8.2f'\n", valor); // Largura e precisão
}

// 6. Imprimindo strings com largura mínima
void imprimirStringComLarguraMinima(char nome[]) {
    printf("Nome com largura mínima 10: '%10s'\n", nome); // Alinha string à direita com largura mínima
}

int main() {
    int num = 42;
    float valor = 123.456;
    char nome[] = "Alice";

    // Chama as funções para demonstrar as formatações
    imprimirNumeroComLarguraMinima(num);
    imprimirNumeroComZeros(num);
    imprimirNumeroAlinhadoEsquerda(num);
    imprimirFloatComPrecisao(valor);
    imprimirFloatComLarguraEPrecisao(valor);
    imprimirStringComLarguraMinima(nome);
    
    return 0;
}