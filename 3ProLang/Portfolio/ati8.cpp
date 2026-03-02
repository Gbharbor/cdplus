#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe que representa um veículo
class Veiculo {
private:
    string nome;
    string placa;
    string fabricante;
    string cor;

public:
    // Construtor
    Veiculo(string n, string p, string f, string c)
        : nome(n), placa(p), fabricante(f), cor(c) {}

    // Função para imprimir os dados do veículo
    void imprimir() const {
        cout << "Nome: " << nome << endl;
        cout << "Placa: " << placa << endl;
        cout << "Fabricante: " << fabricante << endl;
        cout << "Cor: " << cor << endl;
    }
};

int main() {
    int n;
    cout << "Quantos veículos deseja cadastrar? ";
    cin >> n;
    cin.ignore(); // Limpa o buffer do teclado

    vector<Veiculo> listaVeiculos;

    for (int i = 0; i < n; ++i) {
        string nome, placa, fabricante, cor;

        cout << "\nCadastro do veículo " << i + 1 << ":\n";

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Placa: ";
        getline(cin, placa);

        cout << "Fabricante: ";
        getline(cin, fabricante);

        cout << "Cor: ";
        getline(cin, cor);

        Veiculo v(nome, placa, fabricante, cor);
        listaVeiculos.push_back(v);
    }

    cout << "\n=== Veículos cadastrados ===\n";
    for (const auto& veiculo : listaVeiculos) {
        veiculo.imprimir();
    }

    return 0;
}