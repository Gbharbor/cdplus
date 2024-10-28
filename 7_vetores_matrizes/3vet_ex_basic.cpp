// vetor de inteiros 
#include <iostream>
using namespace std;

int main() {
    // Declaração e inicialização de um vetor de inteiros
    int notas[5] = {10, 9, 8, 7, 6};

    // Exibindo os elementos do vetor
    cout << "Notas dos alunos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    return 0;
}
//vetor de caracteres
#include <iostream>
using namespace std;

int main() {
    // Declaração e inicialização de um vetor de caracteres
    char iniciais[5] = {'A', 'B', 'C', 'D', 'E'};

    // Exibindo os elementos do vetor
    cout << "Iniciais:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Inicial " << i + 1 << ": " << iniciais[i] << endl;
    }

    return 0;
}

//vetor de float
#include <iostream>
using namespace std;

int main() {
    // Declaração e inicialização de um vetor de números flutuantes
    float medias[4] = {7.5, 8.2, 6.3, 9.1};

    // Exibindo os elementos do vetor
    cout << "Médias dos alunos:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Média " << i + 1 << ": " << medias[i] << endl;
    }

    return 0;
}