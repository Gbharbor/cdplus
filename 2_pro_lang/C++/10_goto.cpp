#include <iostream>
#include <limits> // necessario para numeric_limits

using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - USO BASICO DO GOTO
    // ======================================================
    int x = 10;

    cout << "EXEMPLO 1: Uso basico do goto\n";

    // Se x for igual a 10, o programa salta diretamente
    // para a etiqueta chamada "etiqueta".
    if (x == 10) {
        goto etiqueta;
    }

    // Esta linha sera ignorada, porque o goto desvia
    // o fluxo do programa antes de chegar aqui.
    cout << "Este codigo sera ignorado." << endl;

    // Etiqueta para onde o programa salta
etiqueta:
    cout << "Salto realizado com goto!" << endl;

    cout << endl;


    // ======================================================
    // EXEMPLO 2 - USO DO GOTO COMO LOOP
    // ======================================================
    cout << "EXEMPLO 2: Uso do goto em um loop\n";

    int contador = 0;

    // Etiqueta que marca o inicio da repeticao
loop_inicio:

    // Enquanto contador for menor que 5,
    // o programa imprime o valor e volta para a etiqueta.
    if (contador < 5) {
        cout << "Contador: " << contador << endl;
        contador++;

        // Retorna para a etiqueta, repetindo o bloco
        goto loop_inicio;
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 3 - GOTO PARA TRATAMENTO DE ERRO
    // ======================================================
    cout << "EXEMPLO 3: Uso do goto para tratar erro\n";

    int num;

    // Solicita ao utilizador que digite um numero
    cout << "Digite um numero (ou um valor invalido para testar o erro): ";
    cin >> num;

    // Verifica se houve falha na leitura
    // Isso acontece, por exemplo, se o utilizador digitar letras
    // em vez de um numero.
    if (cin.fail()) {

        // Limpa o estado de erro do cin
        cin.clear();

        // Descarta a entrada invalida que ficou no buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Salta para a etiqueta de erro
        goto erro;
    }

    // Se a entrada for valida, o numero e exibido normalmente
    cout << "Numero digitado: " << num << endl;

    // Salta para o final do programa, evitando executar
    // o bloco de erro.
    goto fim;


// ==========================================================
// ETIQUETA DE ERRO
// ==========================================================
erro:
    cout << "Erro: entrada invalida. Digite um numero valido." << endl;


// ==========================================================
// ETIQUETA FINAL
// ==========================================================
fim:
    cout << "Programa finalizado." << endl;

    return 0;
}