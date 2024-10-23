/*Aqui tem um resumo dos tipos de variaveis e seus especificadores.

inteiro : %d ou %i
caractere : %c 
string (texto) : %s
ponto flutuante : %f , digamos que queira uma precisao maior pode colocar %2f imprime um numero com 2 casas decimais.
double : %lf
inteiro longo : %ld
unsigned inteiro : %u
hexadecimal : %x ou %X
notacao cientifica : %e ou %E
o formato se ajsuta automaticamente : g% ou G%
*/

#include <stdio.h>
//#include <stdlib.h> // para os tipos de variaveis que vou exibir nao e preciso essa biblioteca.

int main() {
    // Variáveis para os exemplos
    int numero = 42;// Inteiro
    char letra = 'A';// Caractere
    char nome[] = "Alice";// String
    float pi = 3.14159;// Float 
    float altura = 1.75;  //float
    double grande_numero = 1234567.89;// Double
    long int numero_grande = 1234567890;// Long Inteiro
    unsigned int numero_unsigned = 40000;// Unsigned Inteiro : notacao cientifica
    float num1 = 0.000123456; // 2 opcoes 
    float num2 = 123456780; // aqui dependendo do valor ele colocara em notacao cientifica.
    float num3 = 3.14159265358979323846;
    


    // Exemplos de printf com diferentes especificadores
    printf("1. O valor do número inteiro é: %d\n", numero);      // %d
    printf("2. A letra é: %c\n", letra);  // %c
    printf("3. O nome é: %s\n", nome);  // %s
    printf("4. O valor de pi é: %f\n", pi);   // %f
    printf("5. O valor de grande_numero é: %lf\n", grande_numero);   // %lf
    printf("6. O valor do número grande é: %ld\n", numero_grande);// %ld
    printf("7. O valor do número unsigned é: %u\n", numero_unsigned);// %u
    printf("8. O valor em hexadecimal é: %x\n", numero);// %x
    printf("9. O valor em hexadecimal (maiusculas) é: %X\n", numero);// %X
    printf("10. O valor em notação científica é: %e\n", pi);// %e
    printf("11. O valor em notação científica (maiusculas) é: %E\n", pi);// %E

    // Exemplo com precisão
    printf("12. A altura é: %.2f metros\n", 1.75);// %.2f
    // Usando %g com precisão para garantir a exibição do ponto decimal
    printf("usando %%g:\n");
    printf ("num1: %.8g\n", num1);//exibicao em notacao cientifica ou normal
    printf ("num2: %.8g\n", num2);//aqui o ponto decimal aparecera
    printf ("num3: %.8g\n", num3);//exibicao em notacal normal ou cientifica.

    // Usando %G com precisão
    printf("\nUsando %%G:\n");
    printf("Num1: %.8G\n", num1); // Exibição em notação normal ou científica
    printf("Num2: %.8G\n", num2); // Aqui, o ponto decimal aparecerá
    printf("Num3: %.8G\n", num3); // Exibição em notação normal ou científica
    return 0;
};