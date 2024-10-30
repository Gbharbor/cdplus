#include <iostream> // Necessário para operações de entrada e saída
#include <string>   // Necessário para usar a classe std::string

using namespace std;

int main() {
    string nome;        // Declara uma string para armazenar o nome
    string sobrenome;   // Declara uma string para armazenar o sobrenome

    // Lê o nome do usuário
    cout << "Digite seu nome: ";
    cin >> nome; // Lê o nome até encontrar um espaço em branco

    // Lê o sobrenome do usuário
    cout << "Digite seu sobrenome: ";
    cin >> sobrenome; // Lê o sobrenome até encontrar um espaço em branco

    // Exibe o nome e sobrenome lidos
    cout << "Seu nome é " << nome << " e seu sobrenome é " << sobrenome << "." << endl;

    // Problema: O cin lê até encontrar um espaço em branco, 
    // portanto, se o usuário digitar um nome completo, 
    // apenas a primeira parte será lida.

    // Para resolver isso, vamos usar getline para ler strings completas
    cout << "\nVersão melhorada do programa usando getline:\n";
    
    // Lê o nome do usuário, permitindo espaços
    cout << "Digite seu nome completo: ";
    getline(cin, nome); // Lê a linha inteira, incluindo espaços

    // Lê o sobrenome do usuário
    cout << "Digite seu sobrenome completo: ";
    getline(cin, sobrenome); // Lê a linha inteira, incluindo espaços

    // Exibe o nome e sobrenome lidos
    cout << "Seu nome completo é " << nome << " e seu sobrenome completo é " << sobrenome << "." << endl;

    return 0; // Indica que o programa terminou corretamente
}