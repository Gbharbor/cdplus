#include <iostream>
#include <string>

using namespace std;

// ------------------------------------------------------------
// 1. Definição de uma struct
// ------------------------------------------------------------

/*
Uma struct permite criar um novo tipo de dado que agrupa
várias variáveis relacionadas.

Em C++ uma struct também pode conter:
- métodos
- construtores
- outros recursos da programação orientada a objetos
*/

struct Pessoa {
    string nome;
    int idade;
    float altura;

    // Método da struct
    void exibirInfo() {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};


// ------------------------------------------------------------
// 2. Struct com construtor
// ------------------------------------------------------------

struct Ponto {
    int x;
    int y;

    // Construtor
    Ponto(int _x, int _y) {
        x = _x;
        y = _y;
    }

    void imprimir() {
        cout << "Ponto: (" << x << ", " << y << ")" << endl;
    }
};


// ------------------------------------------------------------
// 3. Estruturas aninhadas
// ------------------------------------------------------------

struct Data {
    int dia;
    int mes;
    int ano;
};

struct PessoaComNascimento {
    string nome;
    Data nascimento;
};


// ------------------------------------------------------------
// 4. Passando struct para funções
// ------------------------------------------------------------

// Passagem por valor (faz uma cópia)
void imprimirPessoa(Pessoa p) {
    cout << "Pessoa: " << p.nome << " - Idade: " << p.idade << endl;
}

// Passagem por referência (altera o original)
void atualizarIdade(Pessoa& p) {
    p.idade += 1;
}


// ------------------------------------------------------------
// 5. Função que recebe struct Ponto por valor
// ------------------------------------------------------------

void imprimirPonto(Ponto p) {
    cout << "Ponto recebido: (" << p.x << ", " << p.y << ")" << endl;
}


// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    // --------------------------------------------------------
    // 6. Criando structs
    // --------------------------------------------------------

    Pessoa p1;
    p1.nome = "Ana";
    p1.idade = 25;
    p1.altura = 1.65;

    Pessoa p2 = {"Maria", 30, 1.70};

    p1.exibirInfo();
    p2.exibirInfo();


    // --------------------------------------------------------
    // 7. Leitura de dados para struct
    // --------------------------------------------------------

    Pessoa p3;

    cout << "\nDigite o nome: ";
    getline(cin, p3.nome);

    cout << "Digite a idade: ";
    cin >> p3.idade;

    cout << "Digite a altura: ";
    cin >> p3.altura;

    cout << "\nDados digitados:" << endl;
    cout << "Nome: " << p3.nome << endl;
    cout << "Idade: " << p3.idade << endl;
    cout << "Altura: " << p3.altura << endl;


    // --------------------------------------------------------
    // 8. Struct com construtor
    // --------------------------------------------------------

    Ponto ponto1(10, 20);

    ponto1.imprimir();

    cout << "Coordenada x: " << ponto1.x << endl;
    cout << "Coordenada y: " << ponto1.y << endl;


    // --------------------------------------------------------
    // 9. Passando struct para funções
    // --------------------------------------------------------

    imprimirPessoa(p1);

    atualizarIdade(p1);

    cout << "Depois da atualização:" << endl;
    imprimirPessoa(p1);


    // --------------------------------------------------------
    // 10. Usando ponteiros com struct
    // --------------------------------------------------------

    Ponto* pPtr = &ponto1;

    cout << "\nAcesso via ponteiro:" << endl;
    cout << "x: " << pPtr->x << endl;
    cout << "y: " << pPtr->y << endl;


    // --------------------------------------------------------
    // 11. Struct aninhada
    // --------------------------------------------------------

    PessoaComNascimento pessoa1 = {"João", {15, 8, 1990}};

    cout << "\nPessoa com nascimento:" << endl;
    cout << "Nome: " << pessoa1.nome << endl;
    cout << "Data: "
         << pessoa1.nascimento.dia << "/"
         << pessoa1.nascimento.mes << "/"
         << pessoa1.nascimento.ano << endl;


    // --------------------------------------------------------
    // 12. Alias de tipos (typedef / using)
    // --------------------------------------------------------

    typedef Pessoa PessoaTipo;

    PessoaTipo pessoaAlias = {"Carlos", 28, 1.75};

    cout << "\nUsando typedef:" << endl;
    pessoaAlias.exibirInfo();

    using PessoaAlias = Pessoa;

    PessoaAlias outraPessoa = {"Julia", 22, 1.60};

    cout << "\nUsando using:" << endl;
    outraPessoa.exibirInfo();


    return 0;
}