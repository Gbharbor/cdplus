#include <iostream>
#include <string>
#include <algorithm> // Para sort
#include <vector>
#include <cmath>     // Para sqrt

using namespace std;

int main() {

    // ------------------------------------------------------------
    // 1. Entrada de dados
    // ------------------------------------------------------------
    // Pedimos ao utilizador que introduza o seu nome.

    string nome;

    cout << "Digite o seu nome: ";
    cin >> nome;

    // Exibe uma saudação e o número de letras do nome
    cout << "Olá " << nome 
         << ", o seu nome tem " 
         << nome.length() 
         << " letras.\n";


    // ------------------------------------------------------------
    // 2. Converter a string para um vetor de caracteres
    // ------------------------------------------------------------
    /*
       Este bloco copia cada letra da string 'nome'
       para um vetor de caracteres chamado 'letras'.

       - nome.begin() → início da string
       - nome.end()   → fim da string
       - vector<char> → estrutura que armazena os caracteres
    */

    vector<char> letras(nome.begin(), nome.end());


    // ------------------------------------------------------------
    // 3. Ordenar as letras do nome
    // ------------------------------------------------------------
    /*
       Aqui usamos a função sort() da biblioteca <algorithm>.

       A função sort organiza os elementos do vetor
       em ordem alfabética (baseado no valor ASCII).
    */

    sort(letras.begin(), letras.end());

    cout << "Letras do seu nome em ordem alfabética: ";


    // ------------------------------------------------------------
    // 4. Mostrar as letras ordenadas
    // ------------------------------------------------------------
    /*
       Este ciclo percorre o vetor 'letras' e imprime
       cada caractere individualmente.
    */

    for (char letra : letras) {
        cout << letra << ' ';
    }

    cout << endl; // quebra de linha


    // ------------------------------------------------------------
    // 5. Função matemática: raiz quadrada
    // ------------------------------------------------------------
    /*
       Calcula a raiz quadrada de 225 utilizando
       a função sqrt() da biblioteca <cmath>.
    */

    cout << "A raiz quadrada de 225 é: "
         << sqrt(225.0)
         << endl;


    // ------------------------------------------------------------
    // 6. Raiz quadrada usando variáveis
    // ------------------------------------------------------------
    /*
       Primeiro é calculada a expressão matemática:
       base + multiplicador * fator

       Depois é aplicada a função sqrt() ao resultado.
    */

    float base = 13;
    float multiplicador = 3;
    float fator = 4;

    float resultado = sqrt(base + multiplicador * fator);

    cout << "A raiz quadrada de (base + multiplicador * fator) é: "
         << resultado
         << endl;


    return 0;
}