//Matriz tridimensional
#include <iostream>
#include <vector>
#include <iomanip> // Para std::setprecision

using namespace std;

int main() {
    const int ALUNOS = 3; // Número de alunos
    const int DISCIPLINAS = 4; // Número de disciplinas
    const int BIMESTRES = 2; // Número de bimestres

    // Declaração da matriz de notas usando vector
    vector<vector<vector<float>>> notas(ALUNOS, vector<vector<float>>(DISCIPLINAS, vector<float>(BIMESTRES)));
    vector<vector<float>> medias(ALUNOS, vector<float>(DISCIPLINAS));

    // Entrada de dados
    for (int i = 0; i < ALUNOS; i++) {
        cout << "Digite as notas do aluno " << i + 1 << ":\n";
        for (int j = 0; j < DISCIPLINAS; j++) {
            for (int k = 0; k < BIMESTRES; k++) {
                cout << "Nota da disciplina " << j + 1 << ", bimestre " << k + 1 << ": ";
                cin >> notas[i][j][k];
            }
        }
    }

    // Cálculo da média para cada aluno por disciplina
    for (int i = 0; i < ALUNOS; i++) {
        for (int j = 0; j < DISCIPLINAS; j++) {
            float soma = 0;
            for (int k = 0; k < BIMESTRES; k++) {
                soma += notas[i][j][k];
            }
            medias[i][j] = soma / BIMESTRES; // Calcula a média
        }
    }

    // Exibindo as médias
    cout << fixed << setprecision(2); // Configura a precisão para 2 casas decimais
    cout << "\nMédias dos alunos por disciplina:\n";
    for (int i = 0; i < ALUNOS; i++) {
        for (int j = 0; j < DISCIPLINAS; j++) {
            cout << "Média do aluno " << i + 1 << " na disciplina " << j + 1 << ": " << medias[i][j] << endl;
        }
    }

    return 0;
}