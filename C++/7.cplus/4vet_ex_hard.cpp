//Estrutura de Dados para Alunos
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Para std::setprecision

using namespace std;

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

int main() {
    vector<Aluno> alunos(3); // Vetor para 3 alunos

    // Entrada de dados
    for (int i = 0; i < 3; i++) {
        cout << "Digite o nome do aluno " << i + 1 << ": ";
        getline(cin, alunos[i].nome);

        alunos[i].notas.resize(3); // Resize para 3 notas
        cout << "Digite as 3 notas de " << alunos[i].nome << ":\n";
        for (int j = 0; j < 3; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> alunos[i].notas[j];
        }
        alunos[i].calcular_media();
        cin.ignore(); // Limpar o buffer do stdin
    }

    // Exibindo os resultados
    cout << fixed << setprecision(2); // Configura precisão para 2 casas decimais
    cout << "\nResultados:\n";
    for (const Aluno &aluno : alunos) {
        cout << "Nome: " << aluno.nome << ", Média: " << aluno.media << endl;
    }

    return 0;
}

//Ordenacao de Notas
#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort

using namespace std;

int main() {
    const int MAX_ALUNOS = 5;
    vector<float> notas(MAX_ALUNOS);

    // Entrada de dados
    cout << "Digite as notas dos alunos:\n";
    for (int i = 0; i < MAX_ALUNOS; i++) {
        cout << "Nota do aluno " << i + 1 << ": ";
        cin >> notas[i];
    }

    // Ordenando as notas
    sort(notas.begin(), notas.end());

    // Exibindo as notas ordenadas
    cout << "\nNotas em ordem crescente:\n";
    for (int i = 0; i < MAX_ALUNOS; i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    return 0;
}