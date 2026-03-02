#include <iostream>
using namespace std;

// 1. Definindo uma struct com métodos
// A declaração de uma struct em C++ é semelhante à de C. A diferença é que em C++ podemos incluir métodos.
struct Ponto {
    int x;
    int y;

    // Construtor que inicializa a struct com valores para x e y
    Ponto(int _x, int _y) {
        x = _x;
        y = _y;
    }

    // Método para imprimir as coordenadas do ponto
    void imprimir() {
        cout << "Ponto: " << x << " , " << y << endl;
    }
};

// 7. Estruturas aninhadas
// Podemos declarar structs dentro de outras structs.
struct Data {
    int dia;
    int mes;
    int ano;
};

struct Pessoa {
    string nome;
    Data nascimento;  // Estrutura aninhada
};

// 4. Função que recebe a struct Ponto como argumento por valor
// Uma cópia dos dados é passada, então alterações aqui não afetam o original.
void imprimirPonto(Ponto p) {
    cout << "Ponto: (" << p.x << ", " << p.y << ")" << endl;
}

// 5. Função que modifica os membros de uma struct Ponto por referência
// Como é passada por referência, qualquer alteração afeta o original.
void moverPonto(Ponto& p, int novoX, int novoY) {
    p.x = novoX;
    p.y = novoY;
}

int main() {
    // 2. Declarando e inicializando uma struct com construtor
    Ponto p1(10, 20); // Utilizando o construtor para inicializar
    p1.imprimir();    // Chamando método da struct

    // 3. Acessando os membros diretamente da struct
    cout << "Coordenada x de p1: " << p1.x << endl;
    cout << "Coordenada y de p1: " << p1.y << endl;

    // 4. Passando a struct como argumento para uma função por valor
    imprimirPonto(p1);

    // 5. Passando a struct como argumento por referência
    moverPonto(p1, 30, 40);
    cout << "Depois de mover: (" << p1.x << ", " << p1.y << ")" << endl;

    // 6. Usando ponteiros para manipular structs
    // O operador '->' acessa membros da struct por ponteiro, equivalente a (*pPtr).x
    Ponto* pPtr = &p1;  // 'pPtr' é um ponteiro que aponta para a struct 'p1'
    cout << "Coordenada x de p1 via ponteiro: " << pPtr->x << endl;
    cout << "Coordenada y de p1 via ponteiro: " << pPtr->y << endl;

    // 7. Usando struct aninhada
    Pessoa pessoa1 = {"João", {15, 8, 1990}};
    cout << "Nome: " << pessoa1.nome << endl;
    cout << "Data de Nascimento: " 
         << pessoa1.nascimento.dia << "/" 
         << pessoa1.nascimento.mes << "/" 
         << pessoa1.nascimento.ano << endl;

    // 8. Usando construtor novamente para outro objeto
    Ponto p2(50, 60);
    p2.imprimir();

    return 0;
}