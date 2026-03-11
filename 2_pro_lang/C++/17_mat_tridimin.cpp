// ------------------------------------------------------------
// Exemplo de matriz tridimensional com vector
// Armazena notas de alunos por disciplina e por bimestre
// ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <iomanip> // Para fixed e setprecision

using namespace std;

int main() {
    const int ALUNOS = 3;        // Número de alunos
    const int DISCIPLINAS = 4;   // Número de disciplinas
    const int BIMESTRES = 2;     // Número de bimestres

    // Matriz tridimensional:
    // notas[aluno][disciplina][bimestre]
    vector<vector<vector<float>>> notas(
        ALUNOS,
        vector<vector<float>>(
            DISCIPLINAS,
            vector<float>(BIMESTRES)
        )
    );

    // Matriz bidimensional para armazenar a média de cada aluno em cada disciplina
    vector<vector<float>> medias(
        ALUNOS,
        vector<float>(DISCIPLINAS)
    );

    // --------------------------------------------------------
    // Entrada de dados
    // --------------------------------------------------------
    for (int i = 0; i < ALUNOS; i++) {
        cout << "Digite as notas do aluno " << i + 1 << ":\n";

        for (int j = 0; j < DISCIPLINAS; j++) {
            for (int k = 0; k < BIMESTRES; k++) {
                cout << "Nota da disciplina " << j + 1
                     << ", bimestre " << k + 1 << ": ";
                cin >> notas[i][j][k];
            }
        }
    }

    // --------------------------------------------------------
    // Cálculo da média por disciplina
    // --------------------------------------------------------
    for (int i = 0; i < ALUNOS; i++) {
        for (int j = 0; j < DISCIPLINAS; j++) {
            float soma = 0;

            for (int k = 0; k < BIMESTRES; k++) {
                soma += notas[i][j][k];
            }

            medias[i][j] = soma / BIMESTRES;
        }
    }

    // --------------------------------------------------------
    // Exibição das médias
    // --------------------------------------------------------
    cout << fixed << setprecision(2);
    cout << "\nMedias dos alunos por disciplina:\n";

    for (int i = 0; i < ALUNOS; i++) {
        cout << "\nAluno " << i + 1 << ":\n";

        for (int j = 0; j < DISCIPLINAS; j++) {
            cout << "Disciplina " << j + 1
                 << " -> Media: " << medias[i][j] << endl;
        }
    }

    return 0;
}