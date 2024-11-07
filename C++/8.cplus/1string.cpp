#include <iostream> // Necessário para operações de entrada e saída
#include <string>   // Necessário para usar a classe std::string

using namespace std;

int main() {
    // 1. Declarando e inicializando as strings
    string str1 = "Olá";          // Inicializa a primeira string
    string str2 = " Mundo!";      // Inicializa a segunda string
    string str3;                  // String para armazenar o resultado da concatenação
    string str4 = "Olá, mundo!";  // Outra string para demonstrações adicionais
    string str5 = "Olá, C++!";    // Outra string para demonstrações de concatenação

    // 2. Concatenar strings
    str3 = str1 + str2;           // Concatena str1 e str2
    cout << "Concatenado: " << str3 << endl;  // Saída: Olá Mundo!

    // 3. Copiar strings
    string str6 = str1;           // Cópia direta usando atribuição
    cout << "Cópia: " << str6 << endl; // Saída: Olá

    // 4. Comparar strings
    int resultadoComparacao = str1.compare("Olá"); // Compara str1 com "Olá"
    cout << "Resultado da comparação (str1 e 'Olá'): " << resultadoComparacao << endl; // Saída: 0 (iguais)

    // 5. Calcular o comprimento da string
    size_t comprimento = str1.length(); // Calcula o comprimento de str1
    cout << "Comprimento de str1: " << comprimento << endl; // Saída: 3

    // 6. Encontrar o primeiro caractere 'o' em str3
    size_t pos = str3.find('o');       // Encontra a posição do primeiro 'o' em str3
    if (pos != string::npos) {
        cout << "Primeira ocorrência de 'o': " << str3.substr(pos) << endl; // Saída: o Mundo!
    } else {
        cout << "'o' não encontrado." << endl;
    }

    // 7. Concatenação de mais strings
    string str7 = str4 + ", " + str5 + "!"; // Concatena str4 e str5
    cout << "Concatenação de str4 e str5: " << str7 << endl; // Saída: Olá, mundo!, Olá, C++!!

    // 8. Modificação de String
    str7[0] = 'o';  // Modifica o primeiro caractere de str7
    cout << "Após modificação: " << str7 << endl; // Saída: olá, mundo!, Olá, C++!!

    // 9. Busca de uma substring
    size_t posSubstr = str7.find("C++");  // Busca por "C++" em str7
    if (posSubstr != string::npos) {
        cout << "'C++' encontrado na posição: " << posSubstr << endl; // Saída: 18
    }

    // 10. Substituição de parte da string
    str7.replace(posSubstr, 3, "C#"); // Substitui "C++" por "C#"
    cout << "Após substituição: " << str7 << endl; // Saída: olá, mundo!, Olá, C#!@

    // 11. Limpeza de parte da string
    str7.erase(5, 2); // Remove vírgula e espaço
    cout << "Após limpeza: " << str7 << endl; // Saída: olá mundo!, Olá, C#!@

    // 12. Conversão de String para Número
    string numStr = "12345";
    int num = stoi(numStr); // Converte string para inteiro
    cout << "Número convertido: " << num << endl; // Saída: 12345

    // 13. Conversão de Número para String
    int idade = 30;
    string idadeStr = to_string(idade); // Converte inteiro para string
    cout << "Idade como string: " << idadeStr << endl; // Saída: 30

    // 14. Comparação de strings lexicográficas
    string str8 = "apple";
    string str9 = "orange";
    int resultadoComparacaoLexico = str8.compare(str9); // Comparação lexicográfica
    if (resultadoComparacaoLexico == 0) {
        cout << "As strings são iguais." << endl;
    } else if (resultadoComparacaoLexico < 0) {
        cout << "str8 é menor que str9." << endl; // Saída: str8 é menor que str9
    } else {
        cout << "str8 é maior que str9." << endl;
    }

    // 15. Leitura de nome e sobrenome
    string nome, sobrenome;
    
    // Lê o nome do usuário
    cout << "Digite seu nome: ";
    cin >> nome; // Lê o nome até encontrar um espaço

    // Lê o sobrenome do usuário
    cout << "Digite seu sobrenome: ";
    cin >> sobrenome; // Lê o sobrenome até encontrar um espaço

    // Exibe o nome e sobrenome
    cout << "Seu nome é " << nome << " e seu sobrenome é " << sobrenome << "." << endl;

    // 16. Leitura de nome completo com getline (permitindo espaços)
    cout << "\nVersão melhorada do programa usando getline:\n";
    
    // Lê o nome completo do usuário
    cout << "Digite seu nome completo: ";
    cin.ignore(); // Ignora o '\n' deixado pelo cin anterior
    getline(cin, nome); // Lê a linha inteira, incluindo espaços

    // Lê o sobrenome completo
    cout << "Digite seu sobrenome completo: ";
    getline(cin, sobrenome); // Lê a linha inteira, incluindo espaços

    // Exibe o nome completo e sobrenome completo
    cout << "Seu nome completo é " << nome << " e seu sobrenome completo é " << sobrenome << "." << endl;

    return 0; // Indica que o programa terminou corretamente
}