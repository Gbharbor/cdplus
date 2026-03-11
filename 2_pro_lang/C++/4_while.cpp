#include <iostream>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()

using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - CONTANDO DE 1 A 5
    // ======================================================
    cout << "EXEMPLO 1: Contando de 1 a 5\n";

    int i = 1;  // inicializa o contador

    // enquanto i <= 5, o loop continua executando
    while (i <= 5) {
        cout << "i = " << i << endl;
        i++; // incrementa o contador
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 2 - SOMANDO NUMEROS ATE O UTILIZADOR PARAR
    // ======================================================
    cout << "EXEMPLO 2: Somando numeros ate o utilizador parar\n";

    int numero;
    int soma = 0;

    cout << "Digite numeros para somar (digite 0 para parar):\n";

    while (true) {  // loop infinito
        cin >> numero;

        if (numero == 0) {
            break; // sai do loop
        }

        soma += numero; // soma = soma + numero
    }

    cout << "A soma total e: " << soma << endl;

    cout << endl;


    // ======================================================
    // EXEMPLO 3 - JOGO DE ADIVINHACAO
    // ======================================================
    cout << "EXEMPLO 3: Jogo de Adivinhacao\n";

    // inicializa o gerador de numeros aleatorios
    srand(time(0));

    // gera um numero aleatorio entre 1 e 100
    int numeroSecreto = rand() % 100 + 1;

    int palpite = 0;

    cout << "Adivinhe o numero entre 1 e 100\n";

    // continua ate o utilizador acertar
    while (palpite != numeroSecreto) {

        cout << "Digite seu palpite: ";
        cin >> palpite;

        if (palpite < numeroSecreto) {
            cout << "Muito baixo, tente novamente.\n";
        }
        else if (palpite > numeroSecreto) {
            cout << "Muito alto, tente novamente.\n";
        }
        else {
            cout << "Parabens! Voce acertou!\n";
        }
    }

    cout << endl;

    return 0;
}