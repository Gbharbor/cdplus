// 1. Variáveis
// Variáveis são usadas para armazenar valores temporários na memória durante a execução do programa.
// Exemplos: int, float, string, etc.

// 2. Bibliotecas
// As bibliotecas fornecem funcionalidades adicionais ao programa, como entrada/saída ou operações matemáticas.
// Exemplos:
// <iostream> -> Biblioteca padrão para entrada e saída em C++ (ex.: cin, cout).
// <stdio.h> -> Biblioteca para funções de entrada/saída em C (ex.: printf, scanf).

// 3. Estrutura básica de um programa em C++:
// Sequência correta:
// 1. Bibliotecas
// 2. Funções do usuário
// 3. Função main

#include <iostream> // Biblioteca padrão
using namespace std; // Para usar cin e cout sem std::

int main() {
    // 4. Leitura de valores do usuário
    int idade; // Declarar variável inteira
    cout << "Entre com a idade: ";
    cin >> idade; // Entrada do usuário
    cout << "Idade: " << idade << endl; // Saída do valor
    return 0;
}

// 5. Função do compilador
// Um compilador traduz código-fonte escrito em linguagem de programação para código de máquina.
// Ele permite que o programa seja executado diretamente pelo computador.

// 6. Controle de loops
// Exemplo de loop infinito:
int main() {
    int i = 1;
    while (i > 0) { // Condição sempre verdadeira
        i++; // Incrementa indefinidamente
    }
    return 0;
}

// Corrigido com condição de saída:
int main() {
    int i = 1;
    while (i > 0) {
        printf("Valor de i: %d\n", i); // Exibe o valor de i
        if (i == 10) { // Interrompe o loop
            break;
        }
        i++;
    }
    printf("Loop finalizado, valor final de i: %d\n", i);
    return 0;
}

// 7. Diferença entre while e do-while:
// - while: Verifica a condição antes de executar o bloco.
// - do-while: Executa o bloco pelo menos uma vez, mesmo que a condição seja falsa.

// Exemplo de do-while:
int main() {
    int i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i < 5); // Condição verificada após a execução
    return 0;
}

// 8. Estruturas condicionais:
// if: Testa a condição entre parênteses. Se verdadeira, executa o bloco de código.
// else: Opcional, executado se a condição do if for falsa.

int main() {
    int idade;
    cout << "Digite sua idade: ";
    cin >> idade;

    if (idade >= 18) {
        cout << "Maior de idade" << endl;
    } else {
        cout << "Menor de idade" << endl;
    }
    return 0;
}

// 9. Comparando números e validando o maior:
#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3;
    cout << "Digite os valores de n1, n2 e n3: ";
    cin >> n1 >> n2 >> n3;

    if ((n1 > n2) && (n1 > n3)) {
        cout << "n1 é o maior: " << n1 << endl;
    } else if ((n2 > n1) && (n2 > n3)) {
        cout << "n2 é o maior: " << n2 << endl;
    } else {
        cout << "n3 é o maior: " << n3 << endl;
    }
    return 0;
}

// 10. Operador %
// O operador % retorna o resto da divisão.
// Exemplo:
int main() {
    int valor;
    cout << "Digite um número: ";
    cin >> valor;
    cout << "Resto da divisão por 3: " << valor % 3 << endl;
    return 0;
}

// 11. Estruturas de repetição equivalentes:
// Usando while:
int main() {
    int i = 0; // Inicialização
    while (i < 5) { // Condição
        cout << i << endl; // Comandos
        i++; // Incremento
    }
    return 0;
}

// Usando for:
int main() {
    for (int i = 0; i < 5; i++) { // Inicialização; Condição; Incremento
        cout << i << endl; // Comandos
    }
    return 0;
}

// O comando for combina inicialização, condição e incremento em uma única linha, enquanto o while separa essas partes.
