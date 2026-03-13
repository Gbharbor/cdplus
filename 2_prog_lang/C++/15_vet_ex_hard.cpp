// Estrutura de Dados para Alunos + Ordenação de Notas

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>   // std::sort
#include <iomanip>     // std::setprecision

using namespace std;

// ------------------------------------------------------------
// Classe Aluno
// ------------------------------------------------------------
class Aluno {
public:
    string nome;
    vector<float> notas;
    float media;

    // Método para calcular a média das notas
    void calcular_media() {
        float soma = 0;

        for (float nota : notas) {
            soma += nota;
        }

        media = soma / notas.size();
    }
};

// ------------------------------------------------------------
// Exemplo 1: Cadastro de alunos e cálculo da média
// ------------------------------------------------------------
void exemploCadastroAlunos() {

    const int NUM_ALUNOS = 3;
    const int NUM_NOTAS = 3;

    vector<Aluno> alunos(NUM_ALUNOS);

    // Entrada de dados
    for (int i = 0; i < NUM_ALUNOS; i++) {

        cout << "Digite o nome do aluno " << i + 1 << ": ";
        getline(cin, alunos[i].nome);

        alunos[i].notas.resize(NUM_NOTAS);

        cout << "Digite as " << NUM_NOTAS << " notas de " << alunos[i].nome << ":\n";

        for (int j = 0; j < NUM_NOTAS; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> alunos[i].notas[j];
        }

        alunos[i].calcular_media();

        cin.ignore(); // limpa buffer
    }

    // Exibição
    cout << fixed << setprecision(2);

    cout << "\nResultados:\n";

    for (const Aluno& aluno : alunos) {
        cout << "Nome: " << aluno.nome
             << " | Media: " << aluno.media << endl;
    }

    cout << endl;
}

// ------------------------------------------------------------
// Exemplo 2: Ordenação de notas
// ------------------------------------------------------------
void exemploOrdenacaoNotas() {

    const int MAX_ALUNOS = 5;
    vector<float> notas(MAX_ALUNOS);

    cout << "Digite as notas dos alunos:\n";

    for (int i = 0; i < MAX_ALUNOS; i++) {
        cout << "Nota do aluno " << i + 1 << ": ";
        cin >> notas[i];
    }

    // Ordenação crescente
    sort(notas.begin(), notas.end());

    cout << "\nNotas em ordem crescente:\n";

    for (int i = 0; i < MAX_ALUNOS; i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    cout << endl;
}

// ------------------------------------------------------------
// Função principal
// ------------------------------------------------------------
int main() {

    exemploCadastroAlunos();
    exemploOrdenacaoNotas();

    return 0;
}