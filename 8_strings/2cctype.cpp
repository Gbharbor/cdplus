#include <iostream>   // Necessário para operações de entrada e saída
#include <cctype>     // Necessário para funções de manipulação de caracteres

using namespace std;

int main() {
    char c;  // Declara um caractere

    // Lê um caractere do usuário
    cout << "Digite um caractere: ";
    cin >> c;

    // Verificações e saídas usando funções da biblioteca cctype

    // Exemplo de isalnum: Verifica se é alfanumérico
    if (isalnum(c)) {
        cout << c << " é um caractere alfanumérico." << endl; // Alfanumérico: letra ou dígito
    } else {
        cout << c << " não é um caractere alfanumérico." << endl;
    }

    // Exemplo de isalpha: Verifica se é uma letra
    if (isalpha(c)) {
        cout << c << " é uma letra." << endl;

        // Verifica se é letra minúscula ou maiúscula
        if (islower(c)) {
            cout << c << " é minúscula." << endl;
            cout << "Convertendo para maiúscula: " << (char)toupper(c) << endl; // Converte para maiúscula
        } else if (isupper(c)) {
            cout << c << " é maiúscula." << endl;
            cout << "Convertendo para minúscula: " << (char)tolower(c) << endl; // Converte para minúscula
        }
    } else {
        cout << c << " não é uma letra." << endl;
    }

    // Exemplo de iscntrl: Verifica se é um caractere de controle
    if (iscntrl(c)) {
        cout << c << " é um caractere de controle." << endl; // Caractere não imprimível
    } else {
        cout << c << " não é um caractere de controle." << endl;
    }

    // Exemplo de isdigit: Verifica se é um dígito
    if (isdigit(c)) {
        cout << c << " é um dígito." << endl; // 0-9
    } else {
        cout << c << " não é um dígito." << endl;
    }

    // Exemplo de isgraph: Verifica se é um caractere gráfico
    if (isgraph(c)) {
        cout << c << " é um caractere gráfico." << endl; // Não é espaço em branco
    } else {
        cout << c << " não é um caractere gráfico." << endl;
    }

    // Exemplo de isprint: Verifica se é um caractere imprimível
    if (isprint(c)) {
        cout << c << " é um caractere imprimível." << endl; // Pode ser exibido
    } else {
        cout << c << " não é um caractere imprimível." << endl;
    }

    // Exemplo de ispunct: Verifica se é um caractere de pontuação
    if (ispunct(c)) {
        cout << c << " é um caractere de pontuação." << endl; // Como '.', '!', etc.
    } else {
        cout << c << " não é um caractere de pontuação." << endl;
    }

    // Exemplo de isspace: Verifica se é um espaço em branco
    if (isspace(c)) {
        cout << c << " é um espaço em branco." << endl; // Espaço, tabulação, nova linha
    } else {
        cout << c << " não é um espaço em branco." << endl;
    }

    // Exemplo de isxdigit: Verifica se é um dígito hexadecimal
    if (isxdigit(c)) {
        cout << c << " é um dígito hexadecimal." << endl; // 0-9, a-f, A-F
    } else {
        cout << c << " não é um dígito hexadecimal." << endl;
    }

    return 0; // Indica que o programa terminou corretamente
}