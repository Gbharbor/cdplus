#include <iostream>

int main() {
    using namespace std;

    int x = 10; // Exemplo de valor para x

    // Seção 1: Uso básico do goto
    cout << "Uso do goto:\n";
    if (x == 10) { // Se x for igual a 10
        goto etiqueta; // Salta para a etiqueta "etiqueta"
    }
    cout << "Este código será ignorado." << endl;

etiqueta: // Etiqueta para onde o programa pode saltar
    cout << "Salto realizado com goto!" << endl;

    // Seção 2: Exemplo de goto em um loop
    cout << "\nUso do goto em um loop:\n";
    int contador = 0;

loop_inicio:
    if (contador < 5) {
        cout << "Contador: " << contador << endl;
        contador++;
        goto loop_inicio; // Retorna ao início do loop
    }

    // Seção 3: Exemplo de goto para tratar erro
    cout << "\nExemplo de goto para tratar erro:\n";
    int num;
    cout << "Digite um número (ou um valor inválido para ver o tratamento de erro): ";
    cin >> num;

    if (cin.fail()) {
        cin.clear(); // Limpa o estado de falha
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a entrada inválida
        goto erro; // Salta para a etiqueta de erro
    }

    cout << "Número digitado: " << num << endl;
    goto fim; // Salta para o final do programa

erro: // Etiqueta para tratamento de erro
    cout << "Erro: Entrada inválida! Por favor, digite um número válido." << endl;

fim: // Etiqueta de fim
    cout << "Programa finalizado." << endl;

    return 0; // Finaliza o programa
}