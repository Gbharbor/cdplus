#include <iostream>
using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - REPETICAO DE FRASE
    // ======================================================
    cout << "EXEMPLO 1: Repeticao de frase\n";

    for (int controle = 0; controle <= 30; controle++) {
        cout << "Esta frase se repetira ate que a variavel controle seja maior que 30.\n";
        cout << "Controle = " << controle << "\n";
    }

    cout << endl; // separa os exemplos


    // ======================================================
    // EXEMPLO 2 - INCREMENTO E DECREMENTO
    // ======================================================
    cout << "EXEMPLO 2: Incremento e decremento\n";

    cout << "Contando de 1 ate 5\n";
    for (int i = 1; i <= 5; i++) {
        cout << "i = " << i << endl;
    }

    cout << "\nContando de 5 ate 1\n";
    for (int k = 5; k >= 1; k--) {
        cout << "k = " << k << endl;
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 3 - SOMA DOS NUMEROS DE 1 A 10
    // ======================================================
    cout << "EXEMPLO 3: Soma dos numeros de 1 a 10\n";

    int soma = 0;

    for (int i = 1; i <= 10; i++) {
        soma += i;   // equivalente a: soma = soma + i
    }

    cout << "A soma dos numeros de 1 a 10 e: " << soma << endl;

    cout << endl;


    // ======================================================
    // EXEMPLO 4 - NUMEROS PARES
    // ======================================================
    cout << "EXEMPLO 4: Numeros pares de 1 a 10\n";

    for (int i = 2; i <= 10; i += 2) {
        cout << i << " ";
    }

    cout << endl << endl;


    // ======================================================
    // EXEMPLO 5 - TABELA DE MULTIPLICACAO
    // ======================================================
    cout << "EXEMPLO 5: Tabela de multiplicacao por 2\n";

    for (int i = 1; i <= 10; i++) {
        cout << i << " x 2 = " << i * 2 << endl;
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 6 - SEQUENCIA DE FIBONACCI
    // ======================================================
    cout << "EXEMPLO 6: Sequencia de Fibonacci (10 termos)\n";

    int a = 0;
    int b = 1;
    int next;

    // primeiros termos
    cout << a << " " << b << " ";

    for (int i = 3; i <= 10; i++) {
        next = a + b;   // calcula o proximo termo

        cout << next << " ";

        // atualiza os valores para o proximo calculo
        a = b;
        b = next;
    }

    cout << endl;

    return 0;
}                                                              