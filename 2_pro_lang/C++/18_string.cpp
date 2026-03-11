// ------------------------------------------------------------
// Exemplos de operações com std::string em C++
// ------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main() {

    // --------------------------------------------------------
    // 1. Inicialização e concatenação de strings
    // --------------------------------------------------------
    string str1 = "Olá";
    string str2 = " Mundo!";
    string str3 = str1 + str2;

    cout << "Concatenado: " << str3 << endl;


    // --------------------------------------------------------
    // 2. Cópia e comparação de strings
    // --------------------------------------------------------
    string str4 = str1;

    cout << "Copia de str1: " << str4 << endl;
    cout << "Resultado da comparação (str1 e 'Olá'): "
         << str1.compare("Olá") << endl;


    // --------------------------------------------------------
    // 3. Comprimento e busca em strings
    // --------------------------------------------------------
    cout << "Comprimento de str1: " << str1.length() << endl;

    size_t pos = str3.find('o');

    if (pos != string::npos) {
        cout << "Primeira ocorrência de 'o' na posição: "
             << pos << endl;
    }


    // --------------------------------------------------------
    // 4. Nova concatenação e modificação de caractere
    // --------------------------------------------------------
    string str5 = "Olá, C++!";
    string str6 = str3 + ", " + str5;

    cout << "Concatenação de str3 e str5: " << str6 << endl;

    str6[0] = 'o'; // altera primeiro caractere

    cout << "Após modificação: " << str6 << endl;


    // --------------------------------------------------------
    // 5. Busca e substituição de substring
    // --------------------------------------------------------
    size_t posSubstr = str6.find("C++");

    if (posSubstr != string::npos) {

        cout << "'C++' encontrado na posição: "
             << posSubstr << endl;

        str6.replace(posSubstr, 3, "C#");
    }

    cout << "Após substituição: " << str6 << endl;


    // --------------------------------------------------------
    // 6. Remoção de caracteres e conversões
    // --------------------------------------------------------
    str6.erase(5, 2);

    cout << "Após limpeza: " << str6 << endl;

    string numStr = "12345";
    int num = stoi(numStr);

    cout << "Número convertido: " << num << endl;

    string idadeStr = to_string(30);

    cout << "Idade como string: " << idadeStr << endl;


    // --------------------------------------------------------
    // 7. Comparação lexicográfica
    // --------------------------------------------------------
    string str7 = "apple";
    string str8 = "orange";

    int compResult = str7.compare(str8);

    if (compResult == 0) {
        cout << "As strings são iguais." << endl;
    }
    else if (compResult < 0) {
        cout << "str7 é menor que str8." << endl;
    }
    else {
        cout << "str7 é maior que str8." << endl;
    }


    // --------------------------------------------------------
    // 8. Entrada de strings com cin e getline
    // --------------------------------------------------------
    string nome, sobrenome;

    cout << "Digite seu nome: ";
    cin >> nome;

    cout << "Digite seu sobrenome: ";
    cin >> sobrenome;

    cout << "Seu nome é " << nome
         << " e seu sobrenome é "
         << sobrenome << "." << endl;


    // Limpa o buffer antes de usar getline
    cin.ignore();

    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "Digite seu sobrenome completo: ";
    getline(cin, sobrenome);

    cout << "Seu nome completo é "
         << nome << " e seu sobrenome completo é "
         << sobrenome << "." << endl;

    return 0;
}