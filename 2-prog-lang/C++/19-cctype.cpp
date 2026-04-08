#include <iostream>   // Entrada e saída
#include <cctype>     // Funções para manipulação e teste de caracteres

using namespace std;

int main() {
    char c; // Variável para armazenar um caractere

    // ------------------------------------------------------------
    // Leitura de um caractere
    // ------------------------------------------------------------
    cout << "Digite um caractere: ";
    cin >> c;

    // ------------------------------------------------------------
    // Verifica se o caractere é alfanumérico
    // Letras ou dígitos
    // ------------------------------------------------------------
    if (isalnum(c)) {
        cout << c << " e um caractere alfanumerico." << endl;
    } else {
        cout << c << " nao e um caractere alfanumerico." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se o caractere é uma letra
    // ------------------------------------------------------------
    if (isalpha(c)) {
        cout << c << " e uma letra." << endl;

        // Verifica se a letra é minúscula ou maiúscula
        if (islower(c)) {
            cout << c << " e minuscula." << endl;
            cout << "Convertendo para maiuscula: " << (char)toupper(c) << endl;
        } 
        else if (isupper(c)) {
            cout << c << " e maiuscula." << endl;
            cout << "Convertendo para minuscula: " << (char)tolower(c) << endl;
        }
    } else {
        cout << c << " nao e uma letra." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é caractere de controle
    // Ex.: \n, \t
    // ------------------------------------------------------------
    if (iscntrl(c)) {
        cout << c << " e um caractere de controle." << endl;
    } else {
        cout << c << " nao e um caractere de controle." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é um dígito decimal
    // Ex.: 0 a 9
    // ------------------------------------------------------------
    if (isdigit(c)) {
        cout << c << " e um digito." << endl;
    } else {
        cout << c << " nao e um digito." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é um caractere gráfico
    // Todo caractere visível, exceto espaço
    // ------------------------------------------------------------
    if (isgraph(c)) {
        cout << c << " e um caractere grafico." << endl;
    } else {
        cout << c << " nao e um caractere grafico." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é um caractere imprimível
    // Pode ser mostrado na tela
    // ------------------------------------------------------------
    if (isprint(c)) {
        cout << c << " e um caractere imprimivel." << endl;
    } else {
        cout << c << " nao e um caractere imprimivel." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é um caractere de pontuação
    // Ex.: . , ! ? ; :
    // ------------------------------------------------------------
    if (ispunct(c)) {
        cout << c << " e um caractere de pontuacao." << endl;
    } else {
        cout << c << " nao e um caractere de pontuacao." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é espaço em branco
    // Ex.: espaço, tabulação, nova linha
    // ------------------------------------------------------------
    if (isspace(c)) {
        cout << c << " e um espaco em branco." << endl;
    } else {
        cout << c << " nao e um espaco em branco." << endl;
    }

    // ------------------------------------------------------------
    // Verifica se é dígito hexadecimal
    // Ex.: 0-9, a-f, A-F
    // ------------------------------------------------------------
    if (isxdigit(c)) {
        cout << c << " e um digito hexadecimal." << endl;
    } else {
        cout << c << " nao e um digito hexadecimal." << endl;
    }

    return 0;
}