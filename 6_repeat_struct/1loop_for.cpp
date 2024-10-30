#include <iostream>
using namespace std;

// Função para pausar o console, útil em sistemas Windows
void pause() {
    system("PAUSE > nul");
}

// Função principal
int main() {
    // --- EXEMPLO 1: Repetição de Frase ---
    cout << "EXEMPLO 1: Repetição de frase\n";
    for (int controle = 0; controle <= 30; controle++) {
        cout << "Esta frase se repetirá até que a variável controle seja maior do que 30\n";
        cout << "controle = " << controle << "\n";
    }
    pause(); // Pausa o programa para que o usuário possa ver a saída
    cout << endl; // Linha em branco para separar os exemplos

    // --- EXEMPLO 2: Incremento e Decremento ---
    cout << "EXEMPLO 2: Incremento e decremento\n";
    cout << "Contando de 1 a 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "i = " << i << endl; // i aumenta em 1 a cada iteração
    }

    cout << "Contando de 5 a 1:" << endl;
    for (int j = 5; j >= 1; j--) {
        cout << "j = " << j << endl; // j diminui em 1 a cada iteração
    }
    cout << endl; // Para separar os exemplos

    // --- EXEMPLO 3: Somar Números de 1 a 10 ---
    cout << "EXEMPLO 3: Soma dos números de 1 a 10\n";
    int soma = 0;
    for (int i = 1; i <= 10; i++) {
        soma += i; // adiciona o valor de i à variável soma
    }
    cout << "A soma dos números de 1 a 10 é: " << soma << endl;
    cout << endl; // Para separar os exemplos

    // --- EXEMPLO 4: Imprimir Apenas Números Pares entre 1 e 10 ---
    cout << "EXEMPLO 4: Números pares de 1 a 10\n";
    cout << "Números pares: ";
    for (int i = 2; i <= 10; i += 2) { // Corrigido de i=+2 para i+=2
        cout << i << " "; // Imprime o valor de i (apenas pares)
    }
    cout << endl; // Para separar a saída

    // --- EXEMPLO 5: Tabela de Multiplicação por 2 ---
    cout << "EXEMPLO 5: Tabela de multiplicação por 2\n";
    for (int i = 1; i <= 5; i++) {
        cout << i << " x 2 = " << i * 2 << endl; // calcula e exibe a multiplicação
    }
    cout << endl; // Para separar os exemplos

    // --- EXEMPLO 6: Imprimir a Sequência de Fibonacci (primeiros 10 termos) ---
    cout << "EXEMPLO 6: Sequência de Fibonacci (primeiros 10 termos)\n";
    int a = 0, b = 1, next;
    cout << a << " " << b << " "; // 1 e 2 termos já estão aqui impressos, por isso i começa em 3

    for (int i = 3; i <= 10; i++) { // começa em 3, porque os 2 primeiros termos da sequência já foram impressos
        next = a + b; // calcula o próximo termo da sequência
        cout << next << " ";
        a = b;   // atualiza os valores para o próximo cálculo
        b = next; 
    }
    cout << endl; // Para separar a saída

    return 0; // Retorna 0 para indicar que o programa terminou sem erros
}