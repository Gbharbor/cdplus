#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

using namespace std;

// Função para pausar o console, útil em sistemas Windows
void pause() {
    system("PAUSE > nul");
}

// Função principal
int main() {
    // --- EXEMPLO 1: Contagem de 1 a 5 ---
    cout << "EXEMPLO 1: Contando de 1 a 5\n";
    int i = 1;  // Inicializa a variável de controle i em 1

    // O loop while continuará executando enquanto a condição (i <= 5) for verdadeira
    while (i <= 5) {
        cout << "i = " << i << endl;  // Imprime o valor atual de i
        i++;  // Incrementa i em 1 a cada iteração
    }
    cout << endl; // Linha em branco para separar os exemplos

    // --- EXEMPLO 2: Somar Números até um Limite ---
    cout << "EXEMPLO 2: Somando números até um limite\n";
    int numero, soma = 0;  // Inicializa a variável para o número e a soma

    cout << "Digite números para somar (digite 0 para parar):" << endl;

    // O loop continua até que o usuário digite 0
    while (true) {
        cin >> numero;  // Lê um número do usuário
        if (numero == 0) {  // Se o número for 0, o loop termina
            break;
        }
        soma += numero;  // Adiciona o número à soma total
    }

    cout << "A soma total é: " << soma << endl;  // Exibe a soma total
    cout << endl; // Para separar a saída

    // --- EXEMPLO 3: Jogo de Adivinhação ---
    cout << "EXEMPLO 3: Jogo de Adivinhação\n";
    srand(time(0));  // Inicializa o gerador de números aleatórios
    int numeroSecreto = rand() % 100 + 1;  // Gera um número secreto entre 1 e 100
    int palpite = 0;  // Inicializa o palpite do usuário

    cout << "Adivinhe o número secreto entre 1 e 100:" << endl;

    // O loop continua enquanto o palpite for diferente do número secreto
    while (palpite != numeroSecreto) {
        cout << "Digite seu palpite: ";
        cin >> palpite;  // Lê o palpite do usuário

        if (palpite < numeroSecreto) {
            cout << "Muito baixo! Tente novamente." << endl;  // Dica para palpite baixo
        } else if (palpite > numeroSecreto) {
            cout << "Muito alto! Tente novamente." << endl;  // Dica para palpite alto
        } else {
            cout << "Parabéns! Você adivinhou o número!" << endl;  // Acertou
        }
    }
    cout << endl; // Para separar a saída

    // --- EXEMPLO 4: Contagem Regressiva para o Ano Novo ---
    cout << "EXEMPLO 4: Contagem regressiva para o Ano Novo\n";
    int contagem = 10;  // Inicializa a contagem em 10

    cout << "Contagem regressiva para o Ano Novo!" << endl;

    // O loop continua enquanto a contagem for maior que 0
    while (contagem > 0) {
        cout << contagem << endl;  // Imprime o valor atual da contagem
        contagem--;  // Decrementa a contagem em 1
    }

    cout << "Feliz Ano Novo!" << endl;  // Mensagem após a contagem regressiva
    cout << endl; // Para separar a saída

    // --- EXEMPLO 5: Laço While Simples ---
    cout << "EXEMPLO 5: Laço while simples\n";
    i = 0; // Inicializa i
    while (i < 5) { // Enquanto i for menor que 5
        cout << "i = " << i << endl; // Exibe o valor de i
        i++; // Incrementa i em 1
    }
    cout << endl; // Para separar a saída

    return 0; // Retorna 0 para indicar que o programa terminou sem erros
}